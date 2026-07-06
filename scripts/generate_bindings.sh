#!/usr/bin/env bash
# Copyright 2021 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -e

SCRIPT_DIR=$(dirname $(readlink -f $0))
ROOT_DIR=$(readlink -f $SCRIPT_DIR/..)

version=$1
if [ -z "$version" ]; then
  echo "$(basename $0) <version>"
  exit 1
fi

if [ ! -d $ROOT_DIR/rootstraps/$version ]; then
  echo "No rootstrap found. Run copy_rootstrap.sh first."
  exit 1
fi

# Render symgen.yaml, entrypoints*.h, and ffigen_*.yaml from modules.yaml.
config_dir="$ROOT_DIR/build/configs/$version"
python3 "$SCRIPT_DIR/build_configs.py" "$version" --out-dir "$config_dir"

dart run symgen --config "$config_dir/symgen.yaml"

echo "Running ffigen for module-specific configs..."
count=0

for config_file in "$config_dir"/ffigen_*.yaml; do
    [ -e "$config_file" ] || continue

    count=$((count + 1))
    filename=$(basename "$config_file")
    echo "[$count] Processing $filename..."
    dart run ffigen --config "$config_file" --ignore-source-errors
done

if [ $count -eq 0 ]; then
    echo "Error: No ffigen config files found in $config_dir"
    exit 1
fi

echo "Completed $count module(s)"

echo "Converting doxygen descriptions..."
dart run "$SCRIPT_DIR/convert_description.dart" "$version"

echo "Regenerating lib/$version/tizen.dart..."
python3 "$SCRIPT_DIR/generate_tizen.py" "$version"
