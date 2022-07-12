#!/usr/bin/env bash
# Copyright 2021 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -e

SCRIPT_DIR=$(dirname $(readlink -f $0))

TARGET_PLATFORMS="4.0 5.0 5.5 6.0 6.5"

if [ ! -d $SCRIPT_DIR/../rootstraps ]; then
    echo "No rootstraps found. Run copy_rootstraps.sh first."
    exit 1
fi

for v in $TARGET_PLATFORMS; do
    dart run symgen --config $SCRIPT_DIR/../configs/$v/symgen.yaml
    dart run ffigen --config $SCRIPT_DIR/../configs/$v/ffigen.yaml
done
