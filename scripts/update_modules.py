#!/usr/bin/env python3
# Bootstrap configs/<new>/modules.yaml from configs/<prev>/modules.yaml plus
# the new version's rootstrap.
#
#   python3 scripts/update_modules.py 11.0 --from 10.0
#
# What it does:
#   - carries every previous module forward, re-picking sonames and dropping
#     modules/headers whose library/header vanished from the new rootstrap
#   - discovers new pkg-config-backed libraries (diffed against the previous
#     version's rootstrap manifest when available) and synthesizes module
#     entries for them, marked "# NEW - review"
#   - updates the entrypoints sections the same way
#   - prints a REMOVED / UPDATED / ADDED / REVIEW / WARN report
#
# The output is a starting point: search for "# NEW - review" and prune or
# adjust before running generate_bindings.sh, then converge type duplicates
# with resolve_type_dups.py.

from __future__ import annotations

import argparse
import os
import re
import sys
from collections import Counter, OrderedDict

import modules_yaml
from modules_yaml import ROOT, lib_to_module_name, soname_of
from rootstrap_index import RootstrapIndex

# Library families that exist in rootstraps but are out of scope for
# tizen_interop (graphics/toolkit/system plumbing). Candidates are
# review-marked anyway; this list only trims obvious noise.
IGNORE_LIB_PATTERNS = [
    r'^libGL', r'^libEGL', r'^libSDL', r'^libcairo', r'^libdali',
    r'^libchromium', r'^libcurl', r'^libcrypto', r'^libssl', r'^libglib',
    r'^libgio', r'^libgobject', r'^libgmodule', r'^libgthread',
    r'^libecore', r'^libeina', r'^libevas', r'^libeet', r'^libedje',
    r'^libeldbus', r'^libefreet', r'^libelementary', r'^libemile',
    r'^libeo\b', r'^libethumb', r'^libefl', r'^libeeze', r'^libemotion',
    r'^libc\b', r'^libm\b', r'^libdl\b', r'^libpthread', r'^librt\b',
    r'^libstdc\+\+', r'^libgcc', r'^libz\b', r'^libxml2', r'^libsqlite',
    r'^libpng', r'^libjpeg', r'^libfreetype', r'^libfontconfig',
    r'^libharfbuzz', r'^libicu', r'^libdbus', r'^libsystemd', r'^libudev',
    r'^libwayland', r'^libxkbcommon', r'^libtbm', r'^libtdm', r'^libtpl',
]
_IGNORE_RE = re.compile('|'.join(IGNORE_LIB_PATTERNS))


class Report:
    def __init__(self):
        self.groups = OrderedDict((k, []) for k in
                                  ('REMOVED', 'UPDATED', 'ADDED', 'REVIEW', 'WARN'))

    def add(self, group, msg):
        self.groups[group].append(msg)

    def print(self):
        for group, msgs in self.groups.items():
            if not msgs:
                continue
            print(f'\n== {group} ({len(msgs)}) ==')
            for m in msgs:
                print(f'  {m}')


# -- carried modules -----------------------------------------------------------


def carry_module(m, index, report):
    """Validate/adjust one previous module against the new rootstrap.

    Returns the module (mutated) or None if it must be dropped.
    """
    name = m['name']

    if not m.get('no_library'):
        lib = m['library']
        base = re.sub(r'(\.so)(\.\d+)*$', r'\1', lib)
        if base not in index.lib_files:
            report.add('REMOVED', f'module {name}: library {lib} not in rootstrap')
            return None
        soname = soname_of(base, index.lib_files[base])
        if soname != lib:
            report.add('UPDATED', f'module {name}: {lib} -> {soname}')
            m['library'] = soname

    headers = m.get('headers')
    if headers:
        kept = []
        for h in headers:
            if index.header_exists(h):
                kept.append(h)
            else:
                report.add('REMOVED', f'module {name}: header {h} not in rootstrap')
        if not kept:
            report.add('REVIEW', f'module {name}: all headers vanished but the '
                                 f'library exists — check for relocated headers')
        m['headers'] = kept if kept else headers  # keep originals for review

    for pattern in m.get('include_directives_override') or []:
        if not index.expand_glob(pattern):
            report.add('REVIEW', f'module {name}: include_directives_override '
                                 f'{pattern!r} matches no header')

    for h in m.get('dummy_headers') or []:
        if not index.header_exists(h):
            report.add('REVIEW', f'module {name}: dummy_headers entry {h} '
                                 f'not in rootstrap')
    return m


def strip_dead_imports(modules, removed_names, report):
    for m in modules:
        imports = m.get('imports')
        if not imports:
            continue
        kept = [imp for imp in imports if imp.get('from') not in removed_names]
        if len(kept) != len(imports):
            gone = [imp['from'] for imp in imports if imp.get('from') in removed_names]
            report.add('WARN', f"module {m['name']}: dropped imports from removed "
                               f"module(s) {gone} — types may re-duplicate; "
                               f"resolve_type_dups.py will re-derive")
            if kept:
                m['imports'] = kept
            else:
                del m['imports']


# -- candidate synthesis --------------------------------------------------------


def learn_category_votes(cfg):
    """token -> Counter(category prefix) learned from the previous config."""
    votes = {}
    for m in cfg['modules']:
        cat = (m.get('_category') or '').split(' / ')[0]
        if not cat:
            continue
        for tok in m['name'].split('_'):
            votes.setdefault(tok, Counter())[cat] += 1
    return votes


def predict_category(name, votes):
    """Return (category, confident)."""
    tally = Counter()
    for tok in name.split('_'):
        if tok in votes:
            tally.update(votes[tok])
    if not tally:
        return None, False
    cat, n = tally.most_common(1)[0]
    total = sum(tally.values())
    return cat, (n / total) >= 0.5 and n >= 2


def synthesize_module(base, index, votes, report):
    """Build a candidate module entry for a new library.

    Returns (entry, category, entrypoint_headers).
    """
    name = lib_to_module_name(base)
    entry = OrderedDict()
    entry['name'] = name
    entry['library'] = soname_of(base, index.lib_files[base])

    category, confident = predict_category(name, votes)
    if category and confident:
        entry['_category'] = category
    else:
        category = None

    pc = index.pc_by_lib.get(base)
    incdirs = []
    if pc:
        incdirs = [d for d in index.pcs[pc].includedirs
                   if d.rstrip('/') != 'usr/include']

    ep_headers = []

    # Tier 0: a single dedicated include dir owned only by this pc
    # -> include_directives_override glob (shortcut/openal/cion convention).
    if len(incdirs) == 1:
        d = incdirs[0].rstrip('/')
        rel = d[len('usr/include/'):] if d.startswith('usr/include/') else None
        if rel and len(index.includedir_owners(incdirs[0])) == 1:
            files = index.expand_glob(f'**/{rel}/*.h')
            if files:
                entry['include_directives_override'] = [f'**/{rel}/*.h']
                ep_headers = sorted({f.split('/')[-1] for f in files})
                report.add('ADDED', f'module {name} ({base}) [dedicated dir '
                                    f'usr/include/{rel}; add that dir to '
                                    f'common_include_dirs.tizen]')
                return entry, category, ep_headers

    # Tier 1..n: longest-prefix stem matching inside the pc's include dirs
    # (or, as a last resort, top-level usr/include on exact stem match only).
    stems = set()
    search_space = []
    for d in incdirs:
        rel = d.rstrip('/')
        rel = rel[len('usr/include/'):] if rel.startswith('usr/include/') else ''
        prefix = f'{rel}/' if rel else ''
        search_space.extend(h for h in index.headers
                            if h.startswith(prefix) and '/' not in h[len(prefix):])
    if not search_space:
        search_space = [h for h in index.headers if '/' not in h]

    tokens = name.split('_')
    for i in range(len(tokens)):
        want = '_'.join(tokens[i:])
        hits = sorted({h for h in search_space
                       if os.path.basename(h)[:-2] == want
                       or os.path.basename(h).startswith(want + '_')})
        if hits:
            stems.update(os.path.basename(h) for h in hits)
            break

    if stems:
        entry['headers'] = sorted(stems)
        ep_headers = sorted(stems)
        report.add('ADDED', f'module {name} ({base}) headers={sorted(stems)}')
    else:
        report.add('REVIEW', f'module {name} ({base}): no headers could be '
                             f'derived — fill in headers manually')
    return entry, category, ep_headers


def discover_candidates(index, prev_universe, carried_bases, report):
    new_bases = {b for b in index.lib_files if index.pc_by_lib.get(b)}
    if prev_universe is not None:
        baseline = set(prev_universe.lib_files)
    else:
        baseline = set()
        report.add('WARN', 'no previous rootstrap manifest — candidate list '
                           'will be noisy (availability, not curation). '
                           'Run scan_rootstrap.py for the previous version '
                           'while its SDK is installed.')
    candidates = sorted(
        b for b in new_bases - baseline - carried_bases
        if not _IGNORE_RE.match(b))
    return candidates


# -- entrypoints ----------------------------------------------------------------


def update_entrypoints(cfg, index, additions, report):
    """Prune vanished includes; insert new modules' headers per section.

    Returns (pruned, inserted): pruned header names (their sidecar comments
    must be dropped — dump() refuses to lose comments silently) and headers
    actually inserted (only those get "# NEW - review" markers).
    """
    pruned = set()
    inserted = []
    for sec in cfg['entrypoints']:
        kept = []
        for it in sec['includes']:
            if index.header_exists(it['header']):
                kept.append(it)
            else:
                pruned.add(it['header'])
                report.add('REMOVED',
                           f"entrypoints [{sec['section']}]: {it['header']}")
        sec['includes'] = kept
    return pruned, inserted

    by_section = {s['section']: s for s in cfg['entrypoints']}
    for category, headers in additions:
        if not headers:
            continue
        section = by_section.get(category)
        if section is None:
            section = by_section.get('Uncategorized')
            if section is None:
                section = OrderedDict(section='Uncategorized', includes=[])
                cfg['entrypoints'].append(section)
                by_section['Uncategorized'] = section
        existing = {it['header'] for it in section['includes']}
        for h in headers:
            if h in existing:
                continue
            item = OrderedDict(header=h)
            pos = next((i for i, it in enumerate(section['includes'])
                        if it['header'] > h), len(section['includes']))
            section['includes'].insert(pos, item)
            inserted.append(h)
            report.add('ADDED', f"entrypoints [{section['section']}]: {h}")


# -- main ------------------------------------------------------------------------


def main():
    ap = argparse.ArgumentParser(
        description='Bootstrap configs/<new>/modules.yaml from a previous version')
    ap.add_argument('new_version')
    ap.add_argument('--from', dest='prev_version', required=True,
                    metavar='PREV_VERSION')
    ap.add_argument('--rootstrap', default=None,
                    help='New rootstrap dir or manifest file. '
                         'Default: rootstraps/<new>')
    ap.add_argument('--prev-universe', default=None,
                    help='Previous rootstrap manifest (or dir) for candidate '
                         'diffing. Default: configs/<prev>/rootstrap_manifest.yaml '
                         'or rootstraps/<prev> when present')
    ap.add_argument('--output', default=None,
                    help='Default: configs/<new>/modules.yaml')
    ap.add_argument('--dry-run', action='store_true',
                    help='Print the report without writing')
    ap.add_argument('--no-candidates', action='store_true',
                    help='Skip new-module discovery')
    ap.add_argument('--suggest-carried-headers', action='store_true',
                    help='Also suggest new headers for carried modules')
    args = ap.parse_args()

    prev_path = os.path.join(ROOT, 'configs', args.prev_version, 'modules.yaml')
    if not os.path.isfile(prev_path):
        sys.exit(f'No previous config at {prev_path}')
    cfg, comments = modules_yaml.load(prev_path)

    rootstrap = args.rootstrap or os.path.join(ROOT, 'rootstraps', args.new_version)
    if not os.path.exists(rootstrap):
        sys.exit(f'No rootstrap at {rootstrap}. Run scripts/copy_rootstrap.sh '
                 f'and scripts/scan_rootstrap.py first.')
    index = RootstrapIndex.open(args.new_version, rootstrap)

    prev_universe = None
    pu = args.prev_universe
    if pu is None:
        for cand in (os.path.join(ROOT, 'configs', args.prev_version,
                                  'rootstrap_manifest.yaml'),
                     os.path.join(ROOT, 'rootstraps', args.prev_version)):
            if os.path.exists(cand):
                pu = cand
                break
    if pu:
        prev_universe = RootstrapIndex.open(args.prev_version, pu)

    report = Report()

    # top-level
    cfg['version'] = args.new_version
    cfg['rootstrap_prefix'] = f'rootstraps/{args.new_version}'
    inc_dirs = cfg.get('common_include_dirs') or {}
    for group, dirs in inc_dirs.items():
        for d in list(dirs):
            full = os.path.join(rootstrap if os.path.isdir(rootstrap)
                                else os.path.join(ROOT, 'rootstraps', args.new_version),
                                d.rstrip('/'))
            if os.path.isdir(rootstrap) and not os.path.isdir(full):
                dirs.remove(d)
                report.add('REMOVED', f'common_include_dirs.{group}: {d}')

    # carried modules
    kept_modules = []
    removed_names = set()
    for m in cfg['modules']:
        result = carry_module(m, index, report)
        if result is None:
            removed_names.add(m['name'])
        else:
            kept_modules.append(result)
    strip_dead_imports(kept_modules, removed_names, report)
    cfg['modules'] = kept_modules

    # candidates
    new_module_marks = []
    ep_additions = []
    if not args.no_candidates:
        votes = learn_category_votes(cfg)
        carried_bases = {
            re.sub(r'(\.so)(\.\d+)*$', r'\1', m['library'])
            for m in kept_modules if not m.get('no_library')}
        for base in discover_candidates(index, prev_universe, carried_bases,
                                        report):
            entry, category, ep_headers = synthesize_module(
                base, index, votes, report)
            cat_key = category or 'Uncategorized'
            pos = len(cfg['modules'])
            for i, m in enumerate(cfg['modules']):
                mc = (m.get('_category') or '').split(' / ')[0]
                if mc == category:
                    pos = i + 1
            cfg['modules'].insert(pos, entry)
            new_module_marks.append(entry['name'])
            ep_additions.append((cat_key, ep_headers))

    # entrypoints
    pruned_headers, inserted_headers = update_entrypoints(
        cfg, index, ep_additions, report)
    if pruned_headers:
        comments = [(k, c) for k, c in comments
                    if not any(k == f'  - header: {h}' for h in pruned_headers)]

    # suggestions for carried modules
    if args.suggest_carried_headers:
        for m in kept_modules:
            headers = m.get('headers')
            if not headers:
                continue
            stem_dirs = {os.path.dirname(next(iter(index._resolve(h)), ''))
                         for h in headers}
            prefix = m['name'].split('_')[-1]
            for d in stem_dirs:
                pfx = f'{d}/' if d else ''
                for h in sorted(index.headers):
                    if (h.startswith(pfx) and '/' not in h[len(pfx):]
                            and os.path.basename(h).startswith(prefix + '_')
                            and os.path.basename(h) not in headers):
                        report.add('REVIEW', f"module {m['name']}: rootstrap has "
                                             f"{h} not in headers (suggestion)")

    # attach "# NEW - review" markers via the comment sidecar
    for name in new_module_marks:
        comments.append((f'- name: {name}', '# NEW - review'))
    for h in inserted_headers:
        comments.append((f'  - header: {h}', '# NEW - review'))

    report.print()

    out = args.output or os.path.join(ROOT, 'configs', args.new_version,
                                      'modules.yaml')
    if args.dry_run:
        print(f'\n[dry-run] would write {out} '
              f'({len(cfg["modules"])} modules)')
        return
    os.makedirs(os.path.dirname(out), exist_ok=True)

    # The sidecar re-attaches comments to the first matching line; new-module
    # markers may collide with same-named lines, so sort marker entries after
    # the original ones is unnecessary: dump() consumes in order, and original
    # comments come first in the list.
    modules_yaml.dump(cfg, comments, out)
    print(f'\nWrote {out} ({len(cfg["modules"])} modules). '
          f'Search "# NEW - review" before generating bindings.')


if __name__ == '__main__':
    main()
