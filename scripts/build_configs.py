#!/usr/bin/env python3
# Read configs/<version>/modules.yaml and emit:
#   - configs/<version>/symgen.yaml
#   - configs/<version>/entrypoints.h
#   - configs/<version>/entrypoints_<name>.h (for modules with force_types / extern_decls)
#   - configs/<version>/ffigen_<name>.yaml  (one per module)
#   - configs/<version>/ffigen_order.txt    (generation order: providers first)
#
# Cross-module shared types are deduplicated with ffigen's symbol-file
# mechanism: a module listed in another module's `deps` exports a symbol file
# (output.symbol-file), and the depending module imports it
# (import.symbol-files) so ffigen references the provider's declarations
# instead of re-emitting them.

from __future__ import annotations

import argparse
import os
import sys

import yaml

from modules_yaml import to_upper_camel as camel


# -- helpers -----------------------------------------------------------------

def dashed(name: str) -> str:
    return name.replace('_', '-')


def lib_human_name(module: dict) -> str:
    """Derive the library's 'human' name for description fields.
    Uses the actual library filename (preserving dash/underscore as in the .so).
    Falls back to the module name for no-library modules."""
    lib = module.get('library')
    if not lib:
        return module['name']
    n = lib
    if n.startswith('lib'):
        n = n[3:]
    # strip trailing .so(.N)*
    import re as _re
    n = _re.sub(r'(\.so)(\.[0-9]+)*$', '', n)
    return n


def sq(s: str) -> str:
    """Single-quote for YAML (escape single quotes by doubling)."""
    return "'" + s.replace("'", "''") + "'"


# -- symgen.yaml -------------------------------------------------------------

def render_symgen(cfg: dict) -> str:
    version = cfg['version']
    vnd = version.replace('.', '')
    year = cfg.get('symgen_copyright_year') or cfg.get('preamble_copyright_year', 2026)
    lines = []
    lines.append('preamble: |')
    lines.append(f'  // Copyright {year} Samsung Electronics Co., Ltd. All rights reserved.')
    lines.append('  // Use of this source code is governed by a BSD-style license that can be')
    lines.append('  // found in the LICENSE file.')
    lines.append('')
    lines.append(f"name: 'tizen{vnd}Symbols'")
    lines.append(f"output: 'lib/src/bindings/{version}/generated_symbols.dart'")
    lines.append(f"library-path: 'rootstraps/{version}/usr/lib'")
    lines.append('')
    lines.append('target-libraries:')
    # Align comments at column 48 for readability (matches existing style)
    COMMENT_COL = 48
    for m in cfg['modules']:
        if m.get('no_library'):
            continue
        lib = m['library']
        cat = m.get('_category', '')
        entry = f"  - {lib}"
        if cat:
            pad = max(1, COMMENT_COL - len(entry))
            entry = entry + (' ' * pad) + f"# {cat}"
        lines.append(entry)
    return '\n'.join(lines) + '\n'


# -- entrypoints.h -----------------------------------------------------------

def render_entrypoints_h(cfg: dict) -> str:
    lines = []
    first = True
    for sec in cfg['entrypoints']:
        if not first:
            lines.append('')
        first = False
        lines.append(f"// {sec['section']}")
        for it in sec['includes']:
            lines.append(f"#include <{it['header']}>")
    return '\n'.join(lines) + '\n'


# -- entrypoints_<name>.h ----------------------------------------------------

def render_module_entrypoint(module: dict) -> str | None:
    """Return file content, or None if no dummy entrypoint needed."""
    force_types = module.get('force_types') or []
    extern_decls = module.get('extern_decls') or []
    if not (force_types or extern_decls):
        return None

    name = module['name']
    headers = module.get('headers') or []
    title = module.get('dummy_title') or \
        ' '.join(w.capitalize() for w in name.split('_'))
    dummy_headers = module.get('dummy_headers') or headers[:1]

    lines = [f"// {title}"]
    for h in dummy_headers:
        lines.append(f"#include <{h}>")
    if force_types or extern_decls:
        lines.append('')
    for spec in force_types:
        if isinstance(spec, dict):
            t = spec['type']
            fname = spec.get('name', t)
            arg = spec.get('arg', 'x')
        else:
            t = spec
            fname = t
            arg = 'x'
        lines.append(f"void _force_generate_{fname}({t} {arg}) {{}}")
    for d in extern_decls:
        lines.append(f"extern {d};")
    return '\n'.join(lines) + '\n'


# -- ffigen_<name>.yaml ------------------------------------------------------

def _preamble(year: int) -> list[str]:
    return [
        'preamble: |',
        f'  // Copyright {year} Samsung Electronics Co., Ltd. All rights reserved.',
        '  // Use of this source code is governed by a BSD-style license that can be',
        '  // found in the LICENSE file.',
        '  // ignore_for_file: type=lint, unused_element, unused_field',
    ]


def _compiler_opts(cfg: dict, module: dict) -> list[str]:
    lines = ['compiler-opts:']
    for opt in cfg.get('common_compiler_opts') or []:
        lines.append(f"  - {sq(opt)}")
    for opt in module.get('extra_compiler_opts') or []:
        lines.append(f"  - {sq(opt)}")
    # include dirs (grouped with comments)
    inc = cfg.get('common_include_dirs') or {}
    prefix = cfg['rootstrap_prefix']
    # Emit known groups in their conventional order, then any other group
    # present in modules.yaml (so a new include group is never silently
    # dropped just because it isn't listed here).
    known = [
        ('tizen', '# include Tizen API directories'),
        ('efl', '# include EFL directories'),
        ('glib', '# include glib directories'),
    ]
    known_keys = {k for k, _ in known}
    groups = known + [(k, f'# include {k} directories')
                      for k in inc if k not in known_keys]
    for key, comment in groups:
        paths = inc.get(key) or []
        if not paths:
            continue
        lines.append('')
        lines.append(f"  {comment}")
        for p in paths:
            full = f"-I./{prefix}/{p}"
            lines.append(f"  - {sq(full)}")
    return lines


def _symbol_import_section(module: dict) -> list[str]:
    """Return the import.symbol-files block for a module's deps, or []."""
    deps = module.get('deps') or []
    if not deps:
        return []
    lines = ['import:', '  symbol-files:']
    for dep in deps:
        lines.append(f"    - {sq(f'.symbols/{dep}.yaml')}")
    lines.append('')
    return lines


def _type_map_section(module: dict) -> list[str]:
    """Return library-imports + type-map blocks for primitive_typedefs, or []."""
    prim = module.get('primitive_typedefs') or {}
    if not prim:
        return []

    lines = []
    lines.append('library-imports:')
    lines.append("  ffi_lib: 'dart:ffi'")
    lines.append('')
    lines.append('type-map:')
    lines.append('  typedefs:')
    for key, spec in prim.items():
        lines.append(f"    {sq(key)}:")
        lines.append("      lib: 'ffi_lib'")
        lines.append(f"      c-type: {sq(spec['c'])}")
        lines.append(f"      dart-type: {sq(spec['d'])}")
    lines.append('')
    return lines


def _enums_section(cfg: dict, module: dict) -> list[str]:
    default = cfg.get('enum_rename_default') or {}
    extras = module.get('enum_renames') or {}
    if not default and not extras:
        return []
    lines = ['enums:', '  rename:']
    for k, v in default.items():
        lines.append(f"    {sq(k)}: {sq(v)}")
    for k, v in extras.items():
        lines.append(f"    {sq(k)}: {sq(v)}")
    return lines


def _macros_section(module: dict) -> list[str]:
    excludes = module.get('macro_excludes') or []
    if not excludes:
        return []
    lines = ['macros:', '  exclude:']
    for e in excludes:
        lines.append(f"    - {sq(e)}")
    return lines


def render_ffigen_yaml(cfg: dict, module: dict, output_prefix: str,
                       is_provider: bool) -> str:
    version = cfg['version']
    vnd = version.replace('.', '')
    name = module['name']
    cls = f"Tizen{vnd}{camel(name)}"
    desc = module.get('description') or (
        cfg.get('description_template', 'Dart bindings for Tizen {dashed} APIs.')
           .format(dashed=lib_human_name(module))
    )
    year = module.get('preamble_year') or cfg.get('preamble_copyright_year', 2026)

    lines = []
    lines.extend(_preamble(year))
    lines.append('')
    lines.append(f"name: {sq(cls)}")
    lines.append(f"description: {sq(desc)}")
    bindings_path = f'{output_prefix}/generated_bindings_{name}.dart'
    if is_provider:
        # Providers export a symbol file so that dependent modules reuse their
        # types instead of re-declaring them (ffigen symbol-file dedup).
        lines.append('output:')
        lines.append(f"  bindings: {sq(bindings_path)}")
        lines.append('  symbol-file:')
        lines.append(f"    output: {sq(f'.symbols/{name}.yaml')}")
        lines.append(f"    import-path: {sq(f'generated_bindings_{name}.dart')}")
    else:
        lines.append(f"output: {sq(bindings_path)}")
    lines.append('')
    lines.append('llvm-path:')
    lines.append(f"  - {sq(cfg.get('llvm_path', '/usr/lib/llvm-12'))}")
    lines.append('')

    # headers
    lines.append('headers:')
    lines.append('  entry-points:')
    lines.append(f"    - {sq('entrypoints.h')}")
    if (module.get('force_types') or []) or (module.get('extern_decls') or []):
        ep_file = f'entrypoints_{name}.h'
        lines.append(f"    - {sq(ep_file)}")
    # include-directives
    lines.append('  include-directives:')
    overrides = module.get('include_directives_override')
    if overrides:
        # override is authoritative; do not add dummy entrypoint automatically
        dirs = list(overrides)
    else:
        dirs = [f"**/{h}" for h in (module.get('headers') or [])]
        # append dummy entry-point header if present
        if (module.get('force_types') or []) or (module.get('extern_decls') or []):
            dirs.append(f"entrypoints_{name}.h")
    for d in dirs:
        lines.append(f"    - {sq(d)}")
    lines.append('')

    # symbol-file imports (cross-module type dedup)
    lines.extend(_symbol_import_section(module))

    # library-imports + type-map (dart:ffi primitive typedefs only)
    tm = _type_map_section(module)
    if tm:
        lines.extend(tm)

    # compiler-opts
    lines.extend(_compiler_opts(cfg, module))
    lines.append('')

    # enums
    lines.extend(_enums_section(cfg, module))

    # macros
    macros = _macros_section(module)
    if macros:
        lines.append('')
        lines.extend(macros)

    return '\n'.join(lines) + '\n'


# -- dependency graph ----------------------------------------------------------

def topo_order(cfg: dict) -> list[str]:
    """Return module names in generation order: providers before consumers.

    A module that imports another module's symbol file can only be generated
    after that symbol file exists, so ffigen must run providers first.
    Kahn's algorithm with alphabetical tie-break for determinism; exits on
    unknown deps or cycles.
    """
    names = [m['name'] for m in cfg['modules']]
    deps = {m['name']: list(m.get('deps') or []) for m in cfg['modules']}
    known = set(names)
    for name, dlist in deps.items():
        for d in dlist:
            if d not in known:
                sys.exit(f"module {name}: unknown dep '{d}'")

    ordered = []
    done = set()
    remaining = sorted(names)
    while remaining:
        progressed = False
        for name in list(remaining):
            if all(d in done for d in deps[name]):
                ordered.append(name)
                done.add(name)
                remaining.remove(name)
                progressed = True
        if not progressed:
            sys.exit(f"dependency cycle among: {', '.join(remaining)}")
    return ordered


# -- main --------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(
        description='Build symgen.yaml + entrypoints.h + ffigen_*.yaml from modules.yaml')
    ap.add_argument('version')
    ap.add_argument('--out-dir', default=None,
                    help='Output dir. Default: build/configs/<version>/')
    ap.add_argument('--dry-run', action='store_true',
                    help='Print file names without writing')
    args = ap.parse_args()

    version = args.version
    script_dir = os.path.dirname(os.path.realpath(__file__))
    root = os.path.dirname(script_dir)
    cfg_dir = os.path.join(root, 'configs', version)
    modules_path = os.path.join(cfg_dir, 'modules.yaml')
    if not os.path.exists(modules_path):
        sys.exit(f'Not found: {modules_path}')

    with open(modules_path) as f:
        cfg = yaml.safe_load(f)

    if cfg['version'] != version:
        sys.exit(f"version mismatch in modules.yaml ({cfg['version']}) vs arg ({version})")

    out_dir = args.out_dir or os.path.join(root, 'build', 'configs', version)
    # ffigen resolves the 'output' path relative to the config file location.
    output_prefix = os.path.relpath(
        os.path.join(root, 'lib', 'src', 'bindings', version), out_dir)

    def write(name, content):
        path = os.path.join(out_dir, name)
        if args.dry_run:
            print(f'[dry-run] would write {path} ({len(content)} bytes)')
            return
        os.makedirs(os.path.dirname(path) or '.', exist_ok=True)
        with open(path, 'w') as f:
            f.write(content)

    # symgen.yaml
    write('symgen.yaml', render_symgen(cfg))

    # entrypoints.h
    write('entrypoints.h', render_entrypoints_h(cfg))

    # Providers are the modules some other module depends on; they must emit
    # a symbol file, and ffigen must process them before their consumers.
    providers = {d for m in cfg['modules'] for d in (m.get('deps') or [])}
    order = topo_order(cfg)

    # module ffigen yamls + dummy entrypoints
    for m in cfg['modules']:
        write(f"ffigen_{m['name']}.yaml",
              render_ffigen_yaml(cfg, m, output_prefix,
                                 is_provider=m['name'] in providers))
        ep = render_module_entrypoint(m)
        if ep:
            write(f"entrypoints_{m['name']}.h", ep)

    # generation order for generate_bindings.sh (one config filename per line)
    write('ffigen_order.txt',
          '\n'.join(f'ffigen_{name}.yaml' for name in order) + '\n')

    if not args.dry_run:
        print(f'Wrote symgen.yaml, entrypoints.h, ffigen_order.txt, '
              f'{len(cfg["modules"])} ffigen_*.yaml to {out_dir}')


if __name__ == '__main__':
    main()
