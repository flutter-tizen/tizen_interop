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
dart run ffigen --config $ROOT_DIR/configs/$version/ffigen.yaml --ignore-source-errors
