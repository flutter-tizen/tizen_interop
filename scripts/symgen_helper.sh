#!/bin/bash
SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=$(readlink -f $SCRIPT_DIR/..)

version=$1
if [ -z "$version" ]; then
  echo "$(basename $0) <version>"
  exit 1
fi

entrypoints=$ROOT_DIR/configs/$version/entrypoints.h
rootstraps=$ROOT_DIR/rootstraps/$version

show_loading() {
    while :; do
        for s in '|' '/' '-' '\' '|'; do
            printf "\rCollecting symbol information...  $s"
            sleep 0.2
        done
    done
}

show_loading &
LOADING_PID=$!

declare -A symbols


FILTER_SCRIPT="
import sys
import re

files = [line.strip() for line in sys.stdin]
groups = {}

pattern = re.compile(r'^(.*\.so)((\.[0-9]+)*)$')

for f in files:
    m = pattern.match(f)
    if m:
        base = m.group(1)
        if base not in groups:
            groups[base] = []
        groups[base].append(f)

for base, variants in sorted(groups.items()):
    versioned = [v for v in variants if v != base]
    selected = None
    if versioned:
        def version_key(v):
            ver_str = v[len(base)+1:]
            parts = [int(p) for p in ver_str.split('.') if p.isdigit()]
            return parts

        versioned.sort(key=version_key, reverse=True)
        versioned.sort(key=len)
        selected = versioned[0]
    else:
        if base in variants:
            selected = base

    if selected:
        print(selected)
"

while IFS= read -r so_file; do
    if file "$so_file" | grep -q 'ELF'; then
        while IFS= read -r symbol; do
            if [[ -n "$symbol" ]]; then
                symbols["$symbol"]+="$so_file "
            fi
        done < <(nm -gD "$so_file" | awk '{print $3}')
    else
        echo "Warning: $so_file is not a valid ELF file."
    fi
done < <(find "$rootstraps" -type f -name "*.so*" | python3 -c "$FILTER_SCRIPT")

kill $LOADING_PID
wait $LOADING_PID 2>/dev/null

echo -e "\n\n"

declare -a unique_so_file_list

add_symbol_file() {
    local value=$1
    local exists=0

    for item in "${unique_so_file_list[@]}"; do
        if [[ "$item" == "$value" ]]; then
            exists=1
            break
        fi
    done

    if [[ $exists -eq 0 ]]; then
        unique_so_file_list+=("$value")
    fi
}

file_from_entrypoints=$(grep -oP '#include\s*<\K[^>]*' "$entrypoints")

for header in $file_from_entrypoints; do
    header_file=""

    # First, try to find the header in `usr/include` directory
    potential_file=$(find "$rootstraps" -type f -path "*/usr/include/$header" -print -quit)
    if [ -f "$potential_file" ]; then
        header_file="$potential_file"
        echo "1.header: $header_file"
    fi

    # If not found in priority directories, fall back to searching by basename
    if [ ! -f "$header_file" ]; then
        header_file=$(find "$rootstraps" -type f -name "$(basename $header)" -print -quit)
        echo "2.header: $header_file"
    fi

    if [ ! -f "$header_file" ]; then
        continue
    fi

    functions=$(grep -oP '^(?:[A-Za-z0-9_]+\s+)*\w+\s+\K\w+(?=\s*\()' "$header_file")

    for symbol in $functions; do
        if [[ -n "${symbols[$symbol]}" ]]; then
            found_symbol_file=$(basename ${symbols[$symbol]})
            echo "$(basename $header_file) / $found_symbol_file"
            echo "$symbol"
            add_symbol_file $found_symbol_file
            break;
        fi
    done
done

echo "------------------------------------------"

for x in "${unique_so_file_list[@]}"; do
    echo "- $x"
done
