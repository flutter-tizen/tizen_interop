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
        echo "Could not find 'Tizen Studio'. Set TIZEN_STUDIO to locate the installed path."
        exit 1
    fi
fi

# Rootstraps for Tizen platform
OUTDIR=$SCRIPT_DIR/../rootstraps
rm -fr $OUTDIR

VERSIONS="4.0 5.0 5.5 6.0"
for v in $VERSIONS; do
    rootstrap=$TIZEN_STUDIO/platforms/tizen-$v/iot-headed/rootstraps/iot-headed-$v-device.core
    if [ ! -d $rootstrap ]; then
        echo "No installed rootstrap: IOT-Headed-$v-NativeAppDevelopment-CLI"
        exit 1
    fi
    mkdir -p $OUTDIR/$v    
    cp -fr $rootstrap/usr $OUTDIR/$v
done

