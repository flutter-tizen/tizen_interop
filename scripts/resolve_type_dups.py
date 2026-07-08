#!/usr/bin/env python3
# Iteratively resolve duplicate-type errors between generated bindings by
# deriving modules.yaml fixes, regenerating, and re-analyzing until clean.
#
#   python3 scripts/resolve_type_dups.py <version> [--assume-generated]
#
# Requires a local rootstrap, dart, and llvm (ffigen) — this is a maintainer
# tool, not a CI check. Typical use right after adding a new version's
# modules.yaml and running generate_bindings.sh.
#
# What it fixes automatically (dart analyze AMBIGUOUS_EXPORT):
#   struct/union/typedef duplicates -> deps entry on the non-owning module
#                                      (the owner then exports a symbol file
#                                      that dedupes ALL types shared by the pair)
#   enum duplicates                 -> enum_renames: {X: _X} (privatization)
#   macro constant duplicates       -> macro_excludes on the non-owning module
# Everything else (e.g. primitive_typedefs cases like time_t, missing symbols
# needing force_types) is reported with a pointer to scripts/README.md.
#
# Note: dart analyze reports at most one conflicting name per export
# directive per pass, so several iterations are normal; each iteration only
# re-runs ffigen for the modules whose config changed.

from __future__ import annotations

import argparse
import os
import re
import subprocess
import sys
from collections import OrderedDict

import modules_yaml
from modules_yaml import ROOT
from rootstrap_index import RootstrapIndex

DUP_RE = re.compile(
    r"The name '(\w+)' is defined in the libraries (.+)\.$")
MOD_RE = re.compile(r'generated_bindings_(\w+)\.dart')

KIND_PATTERNS = [
    ('struct', re.compile(r'^final class {name} extends ffi\.(Struct|Opaque)\b')),
    ('union', re.compile(r'^final class {name} extends ffi\.Union\b')),
    ('enum', re.compile(r'^(abstract )?(final )?class {name} \{{')),
    ('typedef', re.compile(r'^typedef {name}\b')),
    ('macro', re.compile(r'^const (int|double|String) {name} ')),
]


def run(cmd, **kw):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, **kw)


def analyze(version):
    """Return (dups, other_errors).

    dups: OrderedDict name -> set of module names defining it.
    """
    r = run(['dart', 'analyze', '--format=machine', f'lib/{version}/tizen.dart'])
    dups = OrderedDict()
    others = []
    for line in (r.stdout + r.stderr).splitlines():
        parts = line.split('|')
        if len(parts) < 8:
            continue
        code, message = parts[2], parts[7]
        if code != 'AMBIGUOUS_EXPORT':
            if parts[0] == 'ERROR':
                others.append(f'{code}: {message}')
            continue
        m = DUP_RE.search(message)
        if not m:
            others.append(f'unparsed AMBIGUOUS_EXPORT: {message}')
            continue
        name = m.group(1)
        mods = set(MOD_RE.findall(m.group(2)))
        dups.setdefault(name, set()).update(mods)
    return dups, others


def classify(version, name, module):
    """Kind of duplicate `name` as defined in module's generated bindings."""
    path = os.path.join(ROOT, 'lib', 'src', 'bindings', version,
                        f'generated_bindings_{module}.dart')
    try:
        with open(path) as f:
            text = f.read()
    except OSError:
        return None
    for kind, pat in KIND_PATTERNS:
        if re.search(pat.pattern.format(name=re.escape(name)), text,
                     re.MULTILINE):
            return kind
    return None


class Ownership:
    """Decide which of two modules owns a shared type."""

    def __init__(self, cfg, index):
        self.cfg = cfg
        self.index = index
        self.by_name = {m['name']: m for m in cfg['modules']}
        self.order = [m['name'] for m in cfg['modules']]
        # dependency graph: consumer -> set(provider)
        self.edges = {}
        self.in_degree = {}
        for m in cfg['modules']:
            for dep in m.get('deps') or []:
                self.edges.setdefault(m['name'], set()).add(dep)
                self.in_degree[dep] = self.in_degree.get(dep, 0) + 1

    def _pc_of(self, module):
        m = self.by_name.get(module)
        if not m or m.get('no_library'):
            return None
        base = re.sub(r'(\.so)(\.\d+)*$', r'\1', m['library'])
        return self.index.pc_by_lib.get(base) if self.index else None

    def decide(self, a, b, name):
        """Return (owner, other, signal)."""
        # 1. an existing edge already connects the pair
        if a in self.edges.get(b, ()):
            return a, b, 'existing-edge'
        if b in self.edges.get(a, ()):
            return b, a, 'existing-edge'
        # 2. pkg-config Requires direction
        if self.index:
            pa, pb = self._pc_of(a), self._pc_of(b)
            if pa and pb:
                if self.index.pc_requires_transitively(pb, pa):
                    return a, b, 'pc-requires'
                if self.index.pc_requires_transitively(pa, pb):
                    return b, a, 'pc-requires'
        # 3. header include graph
        if self.index:
            ha = self.by_name.get(a, {}).get('headers') or []
            hb = self.by_name.get(b, {}).get('headers') or []
            if ha and hb:
                if self.index.include_graph_reaches(hb, ha):
                    return a, b, 'include-graph'
                if self.index.include_graph_reaches(ha, hb):
                    return b, a, 'include-graph'
        # 4. dependency-graph hub
        da, db = self.in_degree.get(a, 0), self.in_degree.get(b, 0)
        if da != db:
            return (a, b, 'hub') if da > db else (b, a, 'hub')
        # 5. file order (earlier owns), low confidence
        ia, ib = self.order.index(a), self.order.index(b)
        return (a, b, 'file-order (LOW CONFIDENCE)') if ia < ib \
            else (b, a, 'file-order (LOW CONFIDENCE)')


def apply_fix(cfg, name, kind, owner, others):
    """Mutate cfg; return list of modules whose ffigen config changed.

    For struct/union/typedef duplicates a single deps edge suffices: the owner
    then exports a symbol file and ffigen reuses ALL of its types in the
    consumer, not just the one that was reported. The owner is included in the
    returned list — it must be (re)generated before its consumers so its
    symbol file exists.
    """
    by_name = {m['name']: m for m in cfg['modules']}
    changed = []
    for mod in others:
        m = by_name[mod]
        if kind in ('struct', 'union', 'typedef'):
            deps = m.setdefault('deps', [])
            if owner not in deps:
                deps.append(owner)
                changed.append(owner)
                changed.append(mod)
        elif kind == 'enum':
            renames = m.setdefault('enum_renames', OrderedDict())
            if name not in renames:
                renames[name] = f'_{name}'
                changed.append(mod)
        elif kind == 'macro':
            excludes = m.setdefault('macro_excludes', [])
            if name not in excludes:
                excludes.append(name)
                changed.append(mod)
    return changed


def regenerate(version, modules):
    """build_configs + ffigen for the given modules only.

    Modules run in the rendered dependency order (ffigen_order.txt) so that a
    provider's symbol file exists before its consumers are generated.
    """
    r = run([sys.executable, os.path.join(ROOT, 'scripts', 'build_configs.py'),
             version])
    if r.returncode != 0:
        sys.exit(f'build_configs.py failed:\n{r.stderr}')
    build_dir = os.path.join(ROOT, 'build', 'configs', version)
    os.makedirs(os.path.join(build_dir, '.symbols'), exist_ok=True)
    with open(os.path.join(build_dir, 'ffigen_order.txt')) as f:
        order = [line.removeprefix('ffigen_').removesuffix('.yaml')
                 for line in f.read().split()]
    todo = set(modules)
    for mod in [m for m in order if m in todo]:
        cfgp = os.path.join(build_dir, f'ffigen_{mod}.yaml')
        print(f'    ffigen {mod}...')
        r = run(['dart', 'run', 'ffigen', '--config', cfgp,
                 '--ignore-source-errors'])
        if r.returncode != 0:
            sys.exit(f'ffigen failed for {mod}:\n{r.stderr[-2000:]}')
    # Re-apply module-unique names to anything just regenerated (idempotent).
    r = run([sys.executable,
             os.path.join(ROOT, 'scripts', 'rename_unnamed.py'), version])
    if r.returncode != 0:
        sys.exit(f'rename_unnamed.py failed:\n{r.stderr}')


def generate_tizen(version):
    r = run([sys.executable, os.path.join(ROOT, 'scripts', 'generate_tizen.py'),
             version])
    if r.returncode != 0:
        sys.exit(f'generate_tizen.py failed:\n{r.stderr}')


def main():
    ap = argparse.ArgumentParser(
        description='Iteratively resolve duplicate types between generated bindings')
    ap.add_argument('version')
    ap.add_argument('--max-iters', type=int, default=10)
    ap.add_argument('--dry-run', action='store_true',
                    help='Print the derived modules.yaml changes and exit')
    ap.add_argument('--analyze-only', action='store_true',
                    help='Report duplicates without deriving fixes')
    ap.add_argument('--assume-generated', action='store_true',
                    help='Skip the initial full generation (bindings are '
                         'already up to date, e.g. after generate_bindings.sh)')
    args = ap.parse_args()

    cfg_path = os.path.join(ROOT, 'configs', args.version, 'modules.yaml')
    cfg, comments = modules_yaml.load(cfg_path)

    # The rootstrap index sharpens ownership decisions (pkg-config Requires and
    # include-graph direction); without it, decide() falls back to dependency
    # in-degree and file order.
    rootstrap = os.path.join(ROOT, 'rootstraps', args.version)
    index = RootstrapIndex.scan(args.version, rootstrap) \
        if os.path.isdir(rootstrap) else None

    if not args.assume_generated and not args.analyze_only and not args.dry_run:
        print('Running initial full generation (generate_bindings.sh)...')
        r = run(['bash', os.path.join(ROOT, 'scripts', 'generate_bindings.sh'),
                 args.version])
        if r.returncode != 0:
            sys.exit(f'generate_bindings.sh failed:\n{r.stderr[-2000:]}')

    for it in range(1, args.max_iters + 1):
        if not args.dry_run:
            generate_tizen(args.version)
        dups, others = analyze(args.version)
        if not dups:
            print(f'iter {it}: clean — no duplicate exports.')
            if others:
                print(f'\n{len(others)} other analyzer error(s) this tool does '
                      f'not fix (see scripts/README.md "Handling Type '
                      f'Duplication Issues"):')
                for o in others[:20]:
                    print(f'  {o}')
                sys.exit(1)
            print('Done. Run scripts/generate_bindings.sh for the final full '
                  'pass (doxygen conversion + tizen.dart).')
            return

        print(f'iter {it}: {len(dups)} duplicate name(s)')
        if args.analyze_only:
            for name, mods in dups.items():
                print(f'  {name}: {sorted(mods)}')
            sys.exit(1)

        ownership = Ownership(cfg, index)
        changed = set()
        for name, mods in dups.items():
            kinds = {m: classify(args.version, name, m) for m in mods}
            kind = next((k for k in kinds.values() if k), None)
            if kind is None:
                print(f'  {name}: could not classify ({sorted(mods)}) — skipped')
                continue
            mods = sorted(mods)
            owner = mods[0]
            for other in mods[1:]:
                owner, _, signal = ownership.decide(owner, other, name)
            others_ = [m for m in mods if m != owner]
            print(f'  {name} [{kind}]: owner={owner} <- {others_} ({signal})')
            changed.update(apply_fix(cfg, name, kind, owner, others_))

        if not changed:
            print('No progress — remaining duplicates need manual attention.')
            sys.exit(1)

        if args.dry_run:
            print('\n[dry-run] derived changes for modules: '
                  f'{sorted(changed)} (not written)')
            return

        modules_yaml.dump(cfg, comments, cfg_path)
        regenerate(args.version, sorted(changed))

    print(f'Did not converge within {args.max_iters} iterations.')
    sys.exit(1)


if __name__ == '__main__':
    main()
