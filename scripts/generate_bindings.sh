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

dart run symgen --config $ROOT_DIR/configs/$version/symgen.yaml

if [ -f "$ROOT_DIR/configs/$version/ffigen.yaml" ]; then
    echo "Running ffigen with single config file..."
    dart run ffigen --config $ROOT_DIR/configs/$version/ffigen.yaml --ignore-source-errors
else
    echo "Running ffigen for module-specific configs..."
    config_dir="$ROOT_DIR/configs/$version"
    count=0

    for config_file in "$config_dir"/ffigen-*.yaml; do
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
fi
