#!/usr/bin/env python3
# One-shot migration helper.
# Reads existing configs/<version>/{symgen.yaml, entrypoints.h, ffigen_*.yaml,
# entrypoints_*.h} and emits configs/<version>/modules.yaml.
#
# Intended to be run once per version; the emitted file is then hand-reviewed
# and becomes the source of truth going forward.

from __future__ import annotations

import argparse
import os
import re
import sys
from collections import OrderedDict

import yaml


# -- utilities ---------------------------------------------------------------

def lib_to_module_name(libname: str) -> str:
    """libcapi-appfw-app-common.so.0 -> capi_appfw_app_common"""
    name = libname
    if name.startswith('lib'):
        name = name[3:]
    # strip trailing .so(.N)+
    name = re.sub(r'(\.so)(\.[0-9]+)*$', '', name)
    return name.replace('-', '_')


def header_to_stem(h: str) -> str:
    return os.path.splitext(os.path.basename(h))[0]


class PreservingOrderLoader(yaml.SafeLoader):
    pass


def _ordered_construct_mapping(loader, node):
    loader.flatten_mapping(node)
    return OrderedDict(loader.construct_pairs(node))


PreservingOrderLoader.add_constructor(
    yaml.resolver.BaseResolver.DEFAULT_MAPPING_TAG, _ordered_construct_mapping
)


def _ordered_dict_representer(dumper, data):
    return dumper.represent_mapping('tag:yaml.org,2002:map', data.items())


yaml.add_representer(OrderedDict, _ordered_dict_representer)


# -- parse symgen.yaml -------------------------------------------------------

def parse_symgen(path: str):
    """Return list of (libname, category_comment) in original order."""
    libs = []
    with open(path) as f:
        in_target = False
        for line in f:
            stripped = line.rstrip('\n')
            if stripped.startswith('target-libraries:'):
                in_target = True
                continue
            if not in_target:
                continue
            m = re.match(r'^\s*-\s+(\S+)\s*(?:#\s*(.*))?$', stripped)
            if m:
                libs.append((m.group(1), (m.group(2) or '').strip()))
            elif stripped.strip() and not stripped.lstrip().startswith('#'):
                break
    return libs


# -- parse entrypoints.h -----------------------------------------------------

def parse_entrypoints_h(path: str):
    """Return list of {section, includes: [{header}]} preserving order."""
    sections = []
    cur = None
    with open(path) as f:
        for line in f:
            line = line.rstrip('\n')
            s = line.strip()
            if not s:
                continue
            m_section = re.match(r'^//\s*(.+)$', s)
            if m_section and not s.lower().startswith('//deprecated'):
                name = m_section.group(1).strip()
                # ignore trailing "deprecated" inline comments not starting a new section
                # new section if not an include
                cur = {'section': name, 'includes': []}
                sections.append(cur)
                continue
            m_inc = re.match(r'^#include\s*<\s*([^>]+?)\s*>\s*(?://\s*(.*))?$', s)
            if m_inc and cur is not None:
                cur['includes'].append({'header': m_inc.group(1)})
    return sections


# -- parse a ffigen_*.yaml ---------------------------------------------------

PRIM_KEYS = {'Long', 'Int', 'UnsignedLong', 'UnsignedInt', 'Char', 'UnsignedChar',
             'Short', 'UnsignedShort', 'LongLong', 'UnsignedLongLong',
             'Float', 'Double', 'Bool', 'Size', 'IntPtr', 'UintPtr'}


def module_from_import_path(path: str) -> str | None:
    """'generated_bindings_capi_appfw_app_control.dart' -> capi_appfw_app_control"""
    stem = os.path.splitext(os.path.basename(path))[0]
    if stem.startswith('generated_bindings_'):
        return stem[len('generated_bindings_'):]
    return None


def parse_ffigen_yaml(path: str, version: str, config_dir: str):
    """Extract module-level info from a ffigen_XXX.yaml."""
    with open(path) as f:
        d = yaml.load(f, Loader=PreservingOrderLoader)

    result = {}

    # headers -> include-directives to decide directive override
    hdrs = d.get('headers') or {}
    inc_dirs = list(hdrs.get('include-directives') or [])
    entry_pts = list(hdrs.get('entry-points') or [])

    # Strip entrypoints_<name>.h (with or without '**/' prefix) from
    # include-directives; both forms appear historically.
    core_inc_dirs = []
    for d_ in inc_dirs:
        tail = d_[3:] if d_.startswith('**/') else d_
        if tail.startswith('entrypoints') and tail.endswith('.h'):
            continue
        core_inc_dirs.append(d_)

    # Derive header list: default rule produces '**/<basename>' for each header.
    # We treat the include-directives as the authoritative list and reverse:
    # '**/foo.h' -> header file 'foo.h'
    reverse_headers = []
    glob_like = []
    for d_ in core_inc_dirs:
        m = re.match(r"^\*\*/(.+)$", d_)
        if m:
            tail = m.group(1)
            if '*' in tail:
                glob_like.append(d_)
            else:
                reverse_headers.append(tail)
        else:
            glob_like.append(d_)

    result['headers'] = reverse_headers
    if glob_like:
        # include-directives override needed (e.g. openal '**/AL/*.h')
        result['_include_override'] = list(core_inc_dirs)

    # extra entrypoint file?
    extra_eps = [ep for ep in entry_pts if ep != 'entrypoints.h']
    if extra_eps:
        # parse the extra ep file for force_types / extern_decls
        force_types = []
        extern_decls = []
        dummy_title = None
        dummy_headers = []
        for ep in extra_eps:
            p = os.path.join(config_dir, ep)
            if not os.path.exists(p):
                continue
            content = open(p).read()
            # First line "// Title"
            lines_ = content.splitlines()
            if lines_ and lines_[0].startswith('//'):
                dummy_title = lines_[0][2:].strip()
            # #include <...>
            for m in re.finditer(r'#include\s*<\s*([^>]+)\s*>', content):
                dummy_headers.append(m.group(1))
            # void _force_generate_<fname>(<type> <arg>) {}
            for m in re.finditer(
                r'void\s+_force_generate_(\w+)\s*\(\s*([\w_]+)\s+(\w+)\s*\)\s*\{\s*\}',
                content):
                fname, t, arg = m.group(1), m.group(2), m.group(3)
                if fname == t and arg == 'x':
                    force_types.append(t)  # default form, short representation
                else:
                    force_types.append({'type': t, 'name': fname, 'arg': arg})
            # extern function declarations (with or without 'extern' keyword)
            for m in re.finditer(
                r'^\s*(?:extern\s+)?(?:int|void|long|unsigned\s+\w+)\s+\w+\s*\([^)]*\)\s*;',
                content, re.M):
                line = m.group(0).strip().rstrip(';').strip()
                if line.startswith('extern '):
                    line = line[len('extern '):]
                extern_decls.append(line)
        if force_types:
            result['force_types'] = force_types
        if extern_decls:
            result['extern_decls'] = extern_decls
        if dummy_title:
            result['dummy_title'] = dummy_title
        if dummy_headers and dummy_headers != (result.get('headers') or [])[:1]:
            # only save if it differs from the default (first header)
            result['dummy_headers'] = dummy_headers

    # imports / primitive_typedefs / typedef_renames
    lib_imports = d.get('library-imports') or {}
    type_map = d.get('type-map') or {}
    alias_to_module = {}
    for alias, p in lib_imports.items():
        if p == 'dart:ffi':
            alias_to_module[alias] = '__ffi__'
        else:
            alias_to_module[alias] = module_from_import_path(p) or p

    # collect imports by (module, alias)
    imports_map = OrderedDict()
    primitive_typedefs = OrderedDict()

    for kind in ('typedefs', 'structs', 'unions'):
        entries = type_map.get(kind) or {}
        for key, spec in entries.items():
            lib_alias = spec.get('lib')
            c_type = spec.get('c-type')
            dart_type = spec.get('dart-type')
            mod = alias_to_module.get(lib_alias)

            if mod == '__ffi__':
                # primitive_typedefs
                primitive_typedefs[key] = {'c': c_type, 'd': dart_type}
                continue

            if mod is None:
                # unknown alias -- keep as raw
                continue

            imp_key = (mod, lib_alias)
            bucket = imports_map.setdefault(imp_key, {
                'typedefs': [], 'structs': [], 'unions': [],
                'typedef_renames': OrderedDict(),
                'struct_renames': OrderedDict(),
                'union_renames': OrderedDict(),
            })
            if key == c_type == dart_type:
                bucket[kind].append(key)
            else:
                # rename case: recorder_video_data_s -> camera_preview_data_s
                rename_key = {'typedefs': 'typedef_renames',
                              'structs': 'struct_renames',
                              'unions': 'union_renames'}[kind]
                bucket[rename_key][key] = c_type  # dart_type assumed == c_type

    # serialize imports into list form
    imports_out = []
    for (mod, alias), bucket in imports_map.items():
        item = OrderedDict()
        item['from'] = mod
        if alias != mod:
            item['as'] = alias
        if bucket['typedefs']:
            item['typedefs'] = bucket['typedefs']
        if bucket['structs']:
            item['structs'] = bucket['structs']
        if bucket['unions']:
            item['unions'] = bucket['unions']
        if bucket['typedef_renames']:
            item['typedef_renames'] = dict(bucket['typedef_renames'])
        if bucket['struct_renames']:
            item['struct_renames'] = dict(bucket['struct_renames'])
        if bucket['union_renames']:
            item['union_renames'] = dict(bucket['union_renames'])
        imports_out.append(item)
    if imports_out:
        result['imports'] = imports_out
    if primitive_typedefs:
        result['primitive_typedefs'] = dict(primitive_typedefs)

    # enum_renames (exclude default "_+(.*)": "$1")
    enums = d.get('enums') or {}
    rename = enums.get('rename') or {}
    extra_enums = {k: v for k, v in rename.items() if k != '_+(.*)'}
    if extra_enums:
        result['enum_renames'] = extra_enums

    # macros.exclude
    macros = d.get('macros') or {}
    if macros.get('exclude'):
        result['macro_excludes'] = list(macros['exclude'])

    # extra_compiler_opts (diff from baseline)
    copts = list(d.get('compiler-opts') or [])
    # baseline compiler-opts starts with -m32, -Wno-...setjmp, then include paths.
    # Anything between those flags and the first '-I./' that is NOT baseline is extra.
    base_flags = {'-m32', '-Wno-incomplete-setjmp-declaration'}
    extra = []
    for opt in copts:
        if opt in base_flags:
            continue
        if opt.startswith('-I./'):
            break
        extra.append(opt)
    if extra:
        result['extra_compiler_opts'] = extra

    # preamble year
    pre = d.get('preamble') or ''
    m = re.search(r'Copyright\s+(\d{4})', pre)
    if m:
        result['_preamble_year'] = int(m.group(1))

    # name prefix version
    name = d.get('name') or ''
    m = re.search(r'Tizen(\d+)', name)
    if m:
        result['_name_version'] = m.group(1)

    # description override: only keep if it deviates from the default template
    desc = d.get('description') or ''
    result['_description_raw'] = desc
    return result


# -- parse baseline include_dirs from any ffigen yaml -----------------------

EFL_MARKERS = ('ecore-imf-1', 'efl-1', 'eina-1', 'emile-1', 'eo-1',
               'evas-1', 'edje-1', 'ecore-1', 'ecore-x-1', 'ecore-con-1')
GLIB_MARKERS = ('glib-2.0', 'gobject-2.0')


def classify_include_path(p: str) -> str:
    if any(m in p for m in EFL_MARKERS):
        return 'efl'
    if any(m in p for m in GLIB_MARKERS):
        return 'glib'
    return 'tizen'


def parse_baseline_include_dirs(any_ffigen_path: str):
    """Extract the grouped include paths by classifying each -I path.
    Uses YAML parser for robustness; does not depend on comment markers."""
    with open(any_ffigen_path) as f:
        d = yaml.safe_load(f)
    copts = d.get('compiler-opts') or []
    groups = OrderedDict([('tizen', []), ('efl', []), ('glib', [])])
    for opt in copts:
        if not opt.startswith('-I./'):
            continue
        # strip '-I./' + leading 'rootstraps/<v>/'
        p = opt[len('-I./'):]
        p = re.sub(r'^rootstraps/[\d.]+/', '', p)
        g = classify_include_path(p)
        if p not in groups[g]:
            groups[g].append(p)
    return groups


# -- main --------------------------------------------------------------------

def main():
    ap = argparse.ArgumentParser(
        description='Reverse-encode existing configs/<version> into modules.yaml')
    ap.add_argument('version', help='e.g. 10.0')
    ap.add_argument('--output', '-o', default=None,
                    help='Output path. Default: configs/<version>/modules.yaml')
    args = ap.parse_args()

    version = args.version
    script_dir = os.path.dirname(os.path.realpath(__file__))
    root = os.path.dirname(script_dir)
    cfg_dir = os.path.join(root, 'configs', version)
    if not os.path.isdir(cfg_dir):
        sys.exit(f'Not found: {cfg_dir}')

    symgen_path = os.path.join(cfg_dir, 'symgen.yaml')
    eps_path = os.path.join(cfg_dir, 'entrypoints.h')
    if not os.path.exists(symgen_path) or not os.path.exists(eps_path):
        sys.exit('symgen.yaml or entrypoints.h missing')

    libs = parse_symgen(symgen_path)
    lib_to_module = {l: lib_to_module_name(l) for l, _ in libs}
    module_to_lib = {m: l for l, m in lib_to_module.items()}

    sections = parse_entrypoints_h(eps_path)

    # pick one simple ffigen as baseline for include_dirs
    baseline_candidate = None
    for f in sorted(os.listdir(cfg_dir)):
        if f.startswith('ffigen_') and f.endswith('.yaml'):
            baseline_candidate = os.path.join(cfg_dir, f)
            break
    if not baseline_candidate:
        sys.exit('No ffigen_*.yaml found')
    include_dirs = parse_baseline_include_dirs(baseline_candidate)

    # helper to compute default description for a module (matches build_configs)
    def _lib_human_name(lib, mod):
        if not lib:
            return mod
        n = lib
        if n.startswith('lib'):
            n = n[3:]
        n = re.sub(r'(\.so)(\.[0-9]+)*$', '', n)
        return n

    def _default_desc(lib, mod):
        return f"Dart bindings for Tizen {_lib_human_name(lib, mod)} APIs."

    # gather modules: iterate symgen order
    modules = []
    seen = set()
    for lib, category in libs:
        mod = lib_to_module[lib]
        ff_path = os.path.join(cfg_dir, f'ffigen_{mod}.yaml')
        if not os.path.exists(ff_path):
            print(f'WARN: no ffigen file for {mod} ({lib})', file=sys.stderr)
            continue
        seen.add(mod)
        info = parse_ffigen_yaml(ff_path, version, cfg_dir)
        entry = OrderedDict()
        entry['name'] = mod
        entry['library'] = lib
        if category:
            entry['_category'] = category
        if '_preamble_year' in info:
            entry['_year'] = info['_preamble_year']
        # preserve description only when it deviates from the default
        raw_desc = info.get('_description_raw') or ''
        if raw_desc and raw_desc != _default_desc(lib, mod):
            entry['description'] = raw_desc
        if info.get('headers'):
            entry['headers'] = info['headers']
        if '_include_override' in info:
            entry['include_directives_override'] = info['_include_override']
        if 'extra_compiler_opts' in info:
            entry['extra_compiler_opts'] = info['extra_compiler_opts']
        if 'imports' in info:
            entry['imports'] = info['imports']
        if 'primitive_typedefs' in info:
            entry['primitive_typedefs'] = info['primitive_typedefs']
        if 'enum_renames' in info:
            entry['enum_renames'] = info['enum_renames']
        if 'macro_excludes' in info:
            entry['macro_excludes'] = info['macro_excludes']
        if 'force_types' in info:
            entry['force_types'] = info['force_types']
        if 'extern_decls' in info:
            entry['extern_decls'] = info['extern_decls']
        if 'dummy_title' in info:
            entry['dummy_title'] = info['dummy_title']
        if 'dummy_headers' in info:
            entry['dummy_headers'] = info['dummy_headers']
        modules.append(entry)

    # Also pick up ffigen files that don't correspond to any target-library
    # (e.g. ffigen_time.yaml with no_library=true).
    for fname in sorted(os.listdir(cfg_dir)):
        if not (fname.startswith('ffigen_') and fname.endswith('.yaml')):
            continue
        mod = fname[len('ffigen_'):-len('.yaml')]
        if mod in seen:
            continue
        ff_path = os.path.join(cfg_dir, fname)
        info = parse_ffigen_yaml(ff_path, version, cfg_dir)
        entry = OrderedDict()
        entry['name'] = mod
        entry['no_library'] = True
        raw_desc = info.get('_description_raw') or ''
        if raw_desc and raw_desc != _default_desc(None, mod):
            entry['description'] = raw_desc
        if info.get('headers'):
            entry['headers'] = info['headers']
        if 'primitive_typedefs' in info:
            entry['primitive_typedefs'] = info['primitive_typedefs']
        if 'imports' in info:
            entry['imports'] = info['imports']
        if 'enum_renames' in info:
            entry['enum_renames'] = info['enum_renames']
        if 'macro_excludes' in info:
            entry['macro_excludes'] = info['macro_excludes']
        if '_preamble_year' in info:
            entry['_year'] = info['_preamble_year']
        modules.append(entry)

    # Determine the dominant copyright year from the existing ffigen files and
    # keep per-module overrides only where a module deviates from it.
    year_counts = {}
    for entry in modules:
        y = entry.get('_year')
        if y is not None:
            year_counts[y] = year_counts.get(y, 0) + 1
    default_year = max(year_counts, key=lambda y: year_counts[y]) \
        if year_counts else 2026
    for entry in modules:
        y = entry.pop('_year', None)
        if y is not None and y != default_year:
            entry['preamble_year'] = y

    # Take llvm-path from the existing ffigen files rather than assuming one.
    llvm_path = '/usr/lib/llvm-12'
    for fname in sorted(os.listdir(cfg_dir)):
        if fname.startswith('ffigen_') and fname.endswith('.yaml'):
            with open(os.path.join(cfg_dir, fname)) as f:
                m = re.search(r"llvm-path:\s*\n\s*-\s*'([^']+)'", f.read())
            if m:
                llvm_path = m.group(1)
                break

    # Assemble top-level
    top = OrderedDict()
    top['version'] = version
    top['llvm_path'] = llvm_path
    top['rootstrap_prefix'] = f'rootstraps/{version}'
    top['preamble_copyright_year'] = default_year
    top['description_template'] = 'Dart bindings for Tizen {dashed} APIs.'
    top['common_compiler_opts'] = ['-m32', '-Wno-incomplete-setjmp-declaration']
    top['common_include_dirs'] = include_dirs
    top['enum_rename_default'] = {'_+(.*)': '$1'}
    top['entrypoints'] = [
        {'section': s['section'], 'includes': s['includes']} for s in sections
    ]
    top['modules'] = modules

    out_path = args.output or os.path.join(cfg_dir, 'modules.yaml')
    with open(out_path, 'w') as f:
        yaml.dump(top, f, sort_keys=False, default_flow_style=False,
                  allow_unicode=True, width=200)
    print(f'Wrote {out_path}  ({len(modules)} modules)')


if __name__ == '__main__':
    main()
