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
    unnamed_decls = {}  # filename -> [UnnamedUnion1, UnnamedStruct1, ...]

    for filename in sorted(os.listdir(bindings_dir)):
        if filename.startswith('generated_bindings_') and filename.endswith('.dart'):
            filepath = os.path.join(bindings_dir, filename)
            with open(filepath, 'r') as f:
                content = f.read()

            # Collect top-level UnnamedUnionN/UnnamedStructN declarations.
            # ffigen assigns these names to unnamed C unions/structs, so the
            # same name may be declared by multiple modules and must be hidden
            # from all but one export to avoid ambiguous_export errors.
            decls = re.findall(
                r'^(?:final\s+)?class\s+(Unnamed(?:Union|Struct)\d+)\b',
                content, re.MULTILINE)
            if decls:
                # Union names first, then struct names (matches existing style)
                unnamed_decls[filename] = sorted(
                    set(decls), key=lambda n: (not n.startswith('UnnamedUnion'), n))

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

    # For each Unnamed* name declared by multiple files, keep it exported from
    # the first file (sorted order) and hide it from the others.
    owner = {}
    for filename in sorted(unnamed_decls):
        for name in unnamed_decls[filename]:
            owner.setdefault(name, filename)
    hides = {}
    for filename, names in unnamed_decls.items():
        hidden = [n for n in names if owner[n] != filename]
        if hidden:
            hides[filename] = hidden

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
