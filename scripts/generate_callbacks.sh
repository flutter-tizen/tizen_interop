#!/usr/bin/env bash
# Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

#set -e

SCRIPT_DIR=$(dirname $(readlink -f $0))
CB_PACKAGE_ROOT="$SCRIPT_DIR/callbacks_generator"
ROOTSTRAPS="$SCRIPT_DIR/../rootstraps"
FOUND_COUNT=0
TARGET="$SCRIPT_DIR/../packages/callbacks/tizen/generated/callbacks.cc"

if [ "$1" = "verify" ] ; then
	VERIFY=yes
	#set -e
    ARCHS="${ARCHS:-arm}" # arm64 x86
    PROFILES="${PROFILES:-common}" 	# mobile, wearable, tv
	declare -A SKIP_VERIFY_VERSIONS
    #SKIP_VERIFY_VERSIONS[4.0]=skip
    EXAMPLE_DIR="$SCRIPT_DIR/../packages/callbacks/example"
	(cd "$EXAMPLE_DIR"; flutter-tizen pub get)
fi
if [ "$1" = "-v" ] ; then
	set -x
	EXTRA_ARGS="-v"
	shift
fi

if [ ! -d $ROOTSTRAPS ]; then
	echo "ERROR: Rootstraps directory not found"
	exit 1
fi

CONFIGS=""
for C in "$SCRIPT_DIR"/../configs/*/ffigen.yaml; do
	echo $C
	VERSION="${C%/ffigen.yaml}"
	VERSION="${VERSION##*/}"
    if [ -n "${SKIP_VERIFY_VERSIONS[VERSION]}" ] ; then continue; fi
	echo "==== Found Tizen $VERSION config"
	D="$ROOTSTRAPS/$VERSION"
	if [ -d "$D" ] ; then
        if [ "$VERIFY" = "yes" ] ; then
			"$CB_PACKAGE_ROOT"/gen_callbacks.py --asserts -c $SCRIPT_DIR/../configs/$VERSION/ffigen.yaml -o "$TARGET"
            sed -i '/manifest/ s/api-version="[0-9.]*"/api-version="'$VERSION'"/' "$EXAMPLE_DIR/tizen/tizen-manifest.xml"
			for PROFILE in $PROFILES ; do
				for ARCH in $ARCHS ; do
					echo "$VERSION>  flutter-tizen build tpk --device-profile $PROFILE --target-arch $ARCH"
					(cd "$EXAMPLE_DIR"; flutter-tizen build tpk --device-profile $PROFILE --target-arch $ARCH --debug)
				done
			done
		else
			CONFIGS="-c $SCRIPT_DIR/../configs/$VERSION/ffigen.yaml $CONFIGS"
		fi
	else
		echo "ERROR: Rootstrap $ROOTSTRAPS/$VERSION not found"
	fi
done
if [ -z "$CONFIGS" ] ; then
	echo "ERROR: No rootstraps found. Run copy_rootstraps.sh first."
	exit 1
fi
if [ "$VERIFY" == "yes" ] ; then
	exit
fi
"$CB_PACKAGE_ROOT"/gen_callbacks.py $CONFIGS -o "$TARGET"
