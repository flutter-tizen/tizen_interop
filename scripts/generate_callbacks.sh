#!/usr/bin/env bash
# Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -e

SCRIPT_DIR=$(dirname $(readlink -f $0))
CB_PACKAGE_ROOT="$SCRIPT_DIR/callbacks_generator"
ROOTSTRAPS="$SCRIPT_DIR/../rootstraps"
FOUND_COUNT=0

if [ "$1" = "-v" ] ; then
	set -x
	EXTRA_ARGS="-v"
fi

declare -A EXCLUDE HEADER_DEPS

if [ ! -d $ROOTSTRAPS ]; then
	echo "ERROR: Rootstraps directory not found"
	exit 1
fi

CONFIGS=""
for C in "$SCRIPT_DIR"/../configs/*/ffigen.yaml; do
	echo $C
	VERSION="${C%/ffigen.yaml}"
	VERSION="${VERSION##*/}"
	echo "==== Found Tizen $VERSION config"
	D="$ROOTSTRAPS/$VERSION"
	if [ -d "$D" ] ; then
		CONFIGS="-c $SCRIPT_DIR/../configs/$VERSION/ffigen.yaml $CONFIGS"
	else
		echo "ERROR: Rootstrap $ROOTSTRAPS/$VERSION not found"
	fi
done
if [ -z "$CONFIGS" ] ; then
	echo "ERROR: No rootstraps found. Run copy_rootstraps.sh first."
	exit 1
fi
TARGET="$SCRIPT_DIR/../packages/callbacks/tizen/generated/callbacks.cc"
"$CB_PACKAGE_ROOT"/gen_callbacks.py $CONFIGS -o "$TARGET"
