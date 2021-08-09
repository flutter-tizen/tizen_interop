#!/usr/bin/env bash
# Copyright 2021 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -e

SCRIPT_DIR=$(dirname $(readlink -f $0))

if [[ -z $TIZEN_STUDIO ]]; then
    if [[ -d $HOME/tizen-studio ]]; then
        TIZEN_STUDIO=$HOME/tizen-studio
    else
        echo "Not found the Tizen Studio. Please set the TIZEN_STUDIO environment variable."
        exit 1
    fi
fi

# Copy rootstraps from Tizen Studio.
OUTDIR=$SCRIPT_DIR/rootstraps
mkdir -p $OUTDIR

cp -fr $TIZEN_STUDIO/platforms/tizen-4.0/wearable/rootstraps/wearable-4.0-device.core $OUTDIR

# Generate binding code.
dart run symgen --config configs/4.0/wearable/symgen.yaml
dart run ffigen --config configs/4.0/wearable/ffigen.yaml
