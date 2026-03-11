#!/bin/bash
# Script to verify that all APIs defined in generated_symbols.dart are present in binding files
# Usage: ./scripts/verify_symbols_in_bindings.sh [version]
# Example: ./scripts/verify_symbols_in_bindings.sh 6.0

set -u

VERSION=${1:-"6.0"}
SYMBOLS_FILE="lib/src/bindings/$VERSION/generated_symbols.dart"
BINDING_DIR="lib/src/bindings/$VERSION"

echo "========================================="
echo "Tizen API Symbols Verification Tool"
echo "Version: $VERSION"
echo "========================================="
echo ""

# Check if symbols file exists
if [ ! -f "$SYMBOLS_FILE" ]; then
    echo "[ERROR] Symbols file not found: $SYMBOLS_FILE"
    exit 1
fi

echo "Loading symbols from $SYMBOLS_FILE..."
echo ""

# Function to extract module names from symbols file
get_module_names() {
    local symbols_file=$1
    # Find all const Map<String, List<String>> moduleNameSymbols = {
    grep -oE "const Map<String, List<String>> [a-zA-Z_][a-zA-Z0-9_]*Symbols = \{" "$symbols_file" | \
        sed 's/const Map<String, List<String>> \([a-zA-Z_][a-zA-Z0-9_]*\)Symbols = {/\1/'
}

# Function to extract API names from symbols file for a specific module
get_apis_from_symbols() {
    local symbols_file=$1
    local module_name=$2
    local map_name="${module_name}Symbols"
    
    # Extract the API list from the specific map
    # This is more complex - need to extract the content between 'moduleNameSymbols = {' and '};'
    awk "/const Map<String, List<String>> $map_name = \{/,/\};/" "$symbols_file" | \
        grep -E "^\s+'[a-z0-9_]+'" | \
        sed "s/.*'\([a-z0-9_]*\)'.*/\1/" | \
        sort
}

# Function to check if an API exists in binding file
check_api_in_binding() {
    local binding_file=$1
    local api_name=$2
    
    # Look for function definition in binding file
    # Pattern: return_type function_name( or similar patterns
    grep -E "^\s+(int|void|ffi\.Pointer|bool|double|tbm_surface_h|notification_h|device_policy_manager_h|dpm_password_iterator_h)(<[a-zA-Z_.<> ]+>)? $api_name\(|^\s+late final [a-zA-Z_]+Ptr = _lookup.*'$api_name'" "$binding_file" > /dev/null
    return $?
}

# Function to get the binding file name for a module
get_binding_file_name() {
    local module_name=$1
    # Convert module_name to binding file naming convention
    # Example: capiAppfwAppCommon -> generated_bindings_capi_appfw_app_common.dart
    echo "$module_name" | sed 's/\([a-z]\)\([A-Z]\)/\1_\L\2/g' | sed 's/^/generated_bindings_/' | sed 's/$/.dart/'
}

# Main verification
total_modules=0
passed_modules=0
failed_modules=0
total_apis=0
missing_apis=0

# Get all module names
modules=($(get_module_names "$SYMBOLS_FILE"))

echo "Found ${#modules[@]} modules to verify"
echo ""

for module_name in "${modules[@]}"; do
    binding_file_name=$(get_binding_file_name "$module_name")
    binding_file="$BINDING_DIR/$binding_file_name"
    
    total_modules=$((total_modules + 1))
    
    echo "Module: $module_name"
    echo "  Binding file: $binding_file_name"
    
    # Check if binding file exists
    if [ ! -f "$binding_file" ]; then
        echo "    [ERROR] Binding file not found"
        ((failed_modules++))
        echo ""
        continue
    fi
    
    # Get API list from symbols file
    apis=($(get_apis_from_symbols "$SYMBOLS_FILE" "$module_name"))
    api_count=${#apis[@]}
    
    if [ $api_count -eq 0 ]; then
        echo "    [WARN] No APIs found in symbols file for this module"
        echo ""
        continue
    fi
    
    echo "  APIs to verify: $api_count"
    total_apis=$((total_apis + api_count))
    
    # Check each API
    module_missing=0
    for api in "${apis[@]}"; do
        if ! check_api_in_binding "$binding_file" "$api"; then
            echo "    [MISSING] $api"
            ((module_missing++))
            ((missing_apis++))
        fi
    done
    
    if [ $module_missing -eq 0 ]; then
        echo "  [PASS] All $api_count APIs found"
        ((passed_modules++))
    else
        echo "  [FAIL] $module_missing of $api_count APIs missing"
        ((failed_modules++))
    fi
    echo ""
    echo "Next==>"
    echo ""
done

# Summary
echo "========================================="
echo "Summary"
echo "========================================="
echo "Total modules: $total_modules"
echo "Passed: $passed_modules"
echo "Failed: $failed_modules"
echo ""
echo "Total APIs checked: $total_apis"
echo "Missing APIs: $missing_apis"
echo "========================================="
echo ""

if [ $failed_modules -gt 0 ]; then
    echo "Some modules are missing APIs. Please review the output above."
else
    echo "누락된 API가 없습니다."
fi
exit 0
