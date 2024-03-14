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

if [[ -z $TIZEN_SDK ]]; then
  if [[ -d $HOME/tizen-studio ]]; then
    TIZEN_SDK=$HOME/tizen-studio
  else
    echo "Could not locate Tizen SDK. Set TIZEN_SDK to specify the installed path."
    exit 1
  fi
fi

if [ "$version" = "8.0" ]; then
  rootstrap=$TIZEN_SDK/platforms/tizen-$version/tizen/rootstraps/tizen-$version-device.core
else
  rootstrap=$TIZEN_SDK/platforms/tizen-$version/iot-headed/rootstraps/iot-headed-$version-device.core
fi
if [ ! -d $rootstrap ]; then
  if [ "$version" = "8.0" ]; then
    echo "Rootstrap not installed: Tizen-$version-NativeAppDevelopment-CLI"
  else
    echo "Rootstrap not installed: IOT-Headed-$version-NativeAppDevelopment-CLI"
  fi
  exit 1
fi

outdir=$ROOT_DIR/rootstraps/$version
rm -fr $outdir
mkdir -p $outdir
cp -fr $rootstrap/usr $outdir
