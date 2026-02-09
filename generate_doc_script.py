import re
import os

CONFIGS_DIR = 'configs'
OUTPUT_DIR = 'doc'

# Paths relative to the project root
# {ver} will be replaced by the version string (e.g. "6.0")
PATH_GENERATED_SYMBOLS = 'lib/src/bindings/{ver}/generated_symbols.dart'
PATH_SYMGEN_YAML = 'configs/{ver}/symgen.yaml'
PATH_TIZEN_DART = 'lib/{ver}/tizen.dart'
PATH_OUTPUT_MD = 'doc/tizen{ver}_api.md'

def parse_symgen_yaml(path):
    """
    Extracts library SO names and their descriptions.
    Returns: { "libname.so": "Description" }
    """
    mapping = {}
    try:
        with open(path, 'r') as f:
            for line in f:
                # Match: - libname.so ... # Description
                match = re.search(r'-\s+([\w\.\-]+)\s+.*#\s+(.*)', line)
                if match:
                    lib_name = match.group(1).strip()
                    desc = match.group(2).strip()
                    mapping[lib_name] = desc
    except FileNotFoundError:
        print(f"Warning: {path} not found.")
    return mapping

def parse_tizen_dart(path):
    """
    Extracts mapping from symbol-map-variable-name to getter-name.
    Returns: { "accountsSvcSymbols": "tizenAccountsSvc" }
    """
    mapping = {}
    try:
        with open(path, 'r') as f:
            content = f.read()
        
        # Matches: Tizen60Native get tizenAccountsSvc => ... _getTizenNative(accountsSvcSymbols);
        # Handling multiline with non-greedy match across newlines
        # Adjusted regex to be more generic for different class names (TizenXNative)
        pattern = re.compile(r'Tizen\w+Native\s+get\s+(\w+)\s*=>.*?_getTizenNative\s*\(\s*(\w+)\s*\)', re.DOTALL)
        
        for match in pattern.finditer(content):
            getter_name = match.group(1)
            var_name = match.group(2)
            mapping[var_name] = getter_name
    except FileNotFoundError:
        print(f"Warning: {path} not found.")
    
    return mapping

def parse_generated_symbols(path):
    """
    Extracts structure: { "mapVarName": { "libName": [symbols] } }
    """
    data = {}
    current_map_var = None
    current_lib = None
    
    try:
        with open(path, 'r') as f:
            for line in f:
                line = line.strip()
                
                # Start of a map definition
                # const Map<String, List<String>> accountsSvcSymbols = {
                map_match = re.search(r'const\s+Map<.*?>\s+(\w+)\s*=\s*\{', line)
                if map_match:
                    current_map_var = map_match.group(1)
                    data[current_map_var] = {}
                    continue
                
                if current_map_var:
                    # Library key: 'libaccounts-svc.so.0': [
                    lib_match = re.search(r"'([\w\.\-]+)'\s*:\s*\[", line)
                    if lib_match:
                        current_lib = lib_match.group(1)
                        if current_lib not in data[current_map_var]:
                           data[current_map_var][current_lib] = []
                        continue
                    
                    # Symbol string: 'account_connect',
                    if current_lib and line.startswith("'") and (line.endswith("',") or line.endswith("'")):
                        symbol = line.strip("',")
                        data[current_map_var][current_lib].append(symbol)
                    
                    # End of list or map
                    if line.startswith("],"):
                        current_lib = None
                    if line.startswith("};"):
                        current_map_var = None
    except FileNotFoundError:
        print(f"Warning: {path} not found.")

    return data

def process_version(ver):
    print(f"Processing version: {ver}")
    
    file_generated_symbols = PATH_GENERATED_SYMBOLS.format(ver=ver)
    file_symgen_yaml = PATH_SYMGEN_YAML.format(ver=ver)
    file_tizen_dart = PATH_TIZEN_DART.format(ver=ver)
    file_output = PATH_OUTPUT_MD.format(ver=ver)

    # Check existence
    if not (os.path.exists(file_generated_symbols) and os.path.exists(file_symgen_yaml) and os.path.exists(file_tizen_dart)):
        print(f"Skipping {ver}: One or more required files missing.")
        return

    # 1. Parse configs
    lib_desc_map = parse_symgen_yaml(file_symgen_yaml)
    
    # 2. Parse tizen.dart
    var_to_getter_map = parse_tizen_dart(file_tizen_dart)
    
    # 3. Parse generated_symbols
    symbols_data = parse_generated_symbols(file_generated_symbols)
    
    # 4. Generate Rows
    # Flatten to list first to handle lookbehind
    data_rows = []
    for var_name, libs in symbols_data.items():
        getter_name = var_to_getter_map.get(var_name, var_name)
        
        for lib_name, symbols in libs.items():
            lib_desc = lib_desc_map.get(lib_name, lib_name)
            for symbol in symbols:
                data_rows.append((lib_desc, getter_name, symbol))
    
    rows = []
    last_lib = None
    last_var = None
    
    for lib, var, sym in data_rows:
        display_lib = lib
        display_var = var
        
        if lib == last_lib:
            display_lib = ""
            if var == last_var:
                display_var = ""
        
        rows.append(f"| {display_lib} | {display_var} | {sym} |")
        
        last_lib = lib
        last_var = var
    
    # 5. Write File
    os.makedirs(os.path.dirname(file_output), exist_ok=True)
    with open(file_output, 'w') as f:
        f.write("| Library name | Variable name | Symbol name |\n")
        f.write("| --- | --- | --- |\n")
        f.write("\n".join(rows))
        f.write("\n")
    
    print(f"Generated {file_output} with {len(rows)} rows.")

def main():
    if not os.path.isdir(CONFIGS_DIR):
        print(f"Error: {CONFIGS_DIR} directory not found.")
        return

    # Find all subdirectories in configs/ that look like version numbers
    versions = []
    for entry in os.listdir(CONFIGS_DIR):
        if os.path.isdir(os.path.join(CONFIGS_DIR, entry)):
            versions.append(entry)
    
    versions.sort()
    print(f"Found potential versions: {versions}")
    
    for ver in versions:
        process_version(ver)

if __name__ == "__main__":
    main()
