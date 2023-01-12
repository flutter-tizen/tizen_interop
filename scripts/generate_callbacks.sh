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
EXCLUDE[6.5]="-e peripheral_io.h,system/update_control.h"
HEADER_DEPS[6.5]="-p iotcon/iotcon-client.h=iotcon/iotcon-errors.h"

if [ -d $ROOTSTRAPS ]; then
	for D in $ROOTSTRAPS/*; do
		VERSION="${D##*/}"
		TARGET="$SCRIPT_DIR/../packages/callbacks/tizen/generated/callbacks_$VERSION.cc"
		echo "==== Generating callbacks for Tizen $VERSION: ${TARGET##*/../}"
		CONFIG="$SCRIPT_DIR/../configs/$VERSION/ffigen.yaml"
		if [ ! -f "$CONFIG" ] ; then
			echo "ERROR: Config file not found $CONFIG"
			continue
		fi
		FOUND_COUNT=$(( $FOUND_COUNT + 1))
		"$CB_PACKAGE_ROOT"/gen_callbacks.py $EXTRA_ARGS ${EXCLUDE[$VERSION]} ${HEADER_DEPS[$VERSION]} \
			-c "$CONFIG" > "$TARGET"
	done
fi

if [ $FOUND_COUNT -eq 0 ] ; then
	echo "ERROR: No rootstraps found. Run copy_rootstraps.sh first."
	exit 1
fi
