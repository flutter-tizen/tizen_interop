import os
import sys
import re
import argparse

def to_camel_case(snake_str):
    components = snake_str.split('_')
    return components[0] + ''.join(x.title() for x in components[1:])

def to_upper_camel_case(snake_str):
    components = snake_str.split('_')
    return ''.join(x.title() for x in components)

def extract_top_level_names(content):
    """Return {name: 'real'|'alias'} for top-level exportable declarations.

    A `typedef X = impN.X;` is an alias re-exporting a symbol imported from
    another module (ffigen's symbol-file dedup); the real declaration lives in
    the imported module.
    """
    names = {}
    for m in re.finditer(r'^(?:final |base |sealed |abstract )*class (\w+)', content, re.M):
        names[m.group(1)] = 'real'
    for m in re.finditer(r'^enum (\w+)', content, re.M):
        names[m.group(1)] = 'real'
    for m in re.finditer(r'^typedef (\w+)\s*=\s*([^;]+);', content, re.M):
        name, rhs = m.group(1), m.group(2)
        if re.match(r'^\s*imp\d+\.', rhs):
            names[name] = 'alias'
        else:
            names.setdefault(name, 'real')
    # Top-level constants (ffigen emits #define macros and unnamed-enum members
    # as `const <type> NAME = ...;`). Two modules can define the same macro, so
    # these collide on export too.
    for m in re.finditer(r'^const\s+\S.*?\s(\w+)\s*=', content, re.M):
        names.setdefault(m.group(1), 'real')
    # Private identifiers (leading '_') are never exported, so they can neither
    # clash nor be hidden.
    return {n: k for n, k in names.items() if not n.startswith('_')}

def compute_hide_map(bindings_dir, filenames):
    """Map each binding filename -> sorted list of names to hide on export.

    When the same top-level name is exported by more than one module, keep it on
    its owning module (a real declaration; alphabetically first if several) and
    hide it on the rest so `tizen.dart` has no ambiguous exports.
    """
    decls = {}  # name -> {filename: 'real'|'alias'}
    for fn in filenames:
        with open(os.path.join(bindings_dir, fn), 'r') as f:
            for name, kind in extract_top_level_names(f.read()).items():
                decls.setdefault(name, {})[fn] = kind

    hide_map = {}
    for name, files in decls.items():
        if len(files) < 2:
            continue
        reals = sorted(fn for fn, kind in files.items() if kind == 'real')
        keep = reals[0] if reals else sorted(files)[0]
        for fn in files:
            if fn != keep:
                hide_map.setdefault(fn, set()).add(name)
    return {fn: sorted(names) for fn, names in hide_map.items()}

def parse_args():
    parser = argparse.ArgumentParser(description='Generate lib/<version>/tizen.dart')
    parser.add_argument('version', type=str, help='Tizen version (e.g. 6.5, 7.0)')
    return parser.parse_args()

def main():
    args = parse_args()
    version = args.version
    version_nodot = version.replace('.', '')
    
    # Paths
    project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    target_dir = os.path.join(project_root, 'lib', version)
    bindings_dir = os.path.join(project_root, 'lib', 'src', 'bindings', version)
    symbols_file = os.path.join(bindings_dir, 'generated_symbols.dart')
    
    if not os.path.exists(bindings_dir):
        print(f"Error: Bindings directory not found: {bindings_dir}")
        sys.exit(1)
        
    if not os.path.exists(symbols_file):
        print(f"Error: Symbols file not found: {symbols_file}")
        sys.exit(1)
        
    os.makedirs(target_dir, exist_ok=True)
    target_file = os.path.join(target_dir, 'tizen.dart')
    
    # 1. Parse generated_symbols.dart to get symbol map names
    symbol_maps = {}
    with open(symbols_file, 'r') as f:
        content = f.read()
    
    # regex to find const Map<String, List<String>> XXXSymbols = {
    symbol_matches = re.findall(r'const\s+Map<String,\s*List<String>>\s+(\w+Symbols)\s*=', content)
    for sym in symbol_matches:
        base_name = sym[:-7] # remove 'Symbols'
        # Convert to upper camel case to match class name suffix
        if '_' in base_name:
            # Handle cases like mv_barcode_detector -> MvBarcodeDetector
            upper_camel = to_upper_camel_case(base_name)
        else:
            # Handle cases like accountsSvc -> AccountsSvc
            upper_camel = base_name[0].upper() + base_name[1:]
        symbol_maps[upper_camel] = sym
        
    # 2. Parse generated_bindings_*.dart files
    bindings = []
    extra_exports = []  # files without a symbol map (no getter), exported last

    for filename in sorted(os.listdir(bindings_dir)):
        if filename.startswith('generated_bindings_') and filename.endswith('.dart'):
            filepath = os.path.join(bindings_dir, filename)
            with open(filepath, 'r') as f:
                content = f.read()

            # Find class name
            class_match = re.search(r'class\s+Tizen' + version_nodot + r'([A-Za-z0-9_]+)\s*\{', content)
            if not class_match:
                extra_exports.append(filename)
                continue

            class_suffix = class_match.group(1)
            class_name = f"Tizen{version_nodot}{class_suffix}"


            # Match with symbol map
            symbol_map_name = symbol_maps.get(class_suffix)
            if not symbol_map_name:
                extra_exports.append(filename)
                continue

            # e.g., accountsSvc
            var_base = class_suffix[0].lower() + class_suffix[1:]

            bindings.append({
                'filename': filename,
                'class_name': class_name,
                'class_suffix': class_suffix,
                'symbol_map': symbol_map_name,
                'var_base': var_base
            })

    # Sort bindings by filename
    bindings.sort(key=lambda x: x['filename'])

    # When a top-level name is exported by more than one module (e.g. a struct
    # shared via symbol-file import, re-exported as a typedef alias, or a
    # duplicated macro constant), keep it on its owner and hide it elsewhere to
    # avoid ambiguous exports.
    all_files = [b['filename'] for b in bindings] + extra_exports
    hides = compute_hide_map(bindings_dir, all_files)

    def export_line(filename):
        path = f"../../src/bindings/{version}/{filename}"
        if filename in hides:
            return f"export '{path}' hide {', '.join(hides[filename])};"
        return f"export '{path}';"


    # 3. Generate tizen.dart
    lines = []
    version_underscored = version.replace('.', '_')
    lines.append(f"/// Tizen Interop for Tizen {version}.")
    lines.append(f"library tizen_interop_{version_underscored};")
    lines.append("")
    lines.append("import 'dart:ffi';")
    lines.append("")
    lines.append(f"import '../../src/bindings/{version}/generated_symbols.dart';")
    
    for b in bindings:
        lines.append(f"import '../../src/bindings/{version}/{b['filename']}';")
        
    lines.append("import '../../src/lookup_provider.dart';")
    lines.append("")
    lines.append("export '../../src/extensions.dart';")
    
    for b in bindings:
        lines.append(export_line(b['filename']))
    for filename in extra_exports:
        lines.append(export_line(filename))

    lines.append("")
    lines.append("final _lookupProvider = LookupProvider();")
    lines.append("")
    lines.append("S _getTizenInstance<S>(Map<String, List<String>> symbolMap,")
    lines.append("    S Function(Pointer<T> Function<T extends NativeType>(String)) fromLookup) {")
    lines.append("  return fromLookup(")
    lines.append("    <T extends NativeType>(String symbolName) {")
    lines.append("      _lookupProvider.registerSymbols(symbolMap);")
    lines.append("      return _lookupProvider.lookup<T>(symbolName);")
    lines.append("    },")
    lines.append("  );")
    lines.append("}")
    
    for b in bindings:
        lines.append("")
        var_name = b['var_base']
        lines.append(f"{b['class_name']}? _tizen{b['class_suffix']};")
        lines.append(f"{b['class_name']} get tizen{b['class_suffix']} =>")
        lines.append(f"    _tizen{b['class_suffix']} ??= _getTizenInstance(")
        lines.append(f"        {b['symbol_map']}, {b['class_name']}.fromLookup)!;")
            
    with open(target_file, 'w') as f:
        f.write("\n".join(lines) + "\n")
        
    # Formatting
    os.system(f"dart format {target_file}")
    
    print(f"Successfully generated {target_file}")

if __name__ == '__main__':
    main()
