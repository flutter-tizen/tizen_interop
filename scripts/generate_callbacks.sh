#!/usr/bin/env bash
# Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -e

SCRIPT_DIR=$(dirname $(readlink -f $0))
GENERATOR_ROOT="$SCRIPT_DIR/callbacks_generator"
ROOTSTRAPS="$SCRIPT_DIR/../rootstraps"
FOUND_COUNT=0
TARGET="$SCRIPT_DIR/../packages/tizen_interop_callbacks/tizen/src/generated_callbacks.cc"

if [ "$1" == "-h" -o "$1" = "help" -o "$1" = "--help" ]; then
  echo "$0        - generates callbacks based on ffigen.yaml config files"
  echo "$0 verify - check type substitution, see this script source for more info"
  exit 0
elif [ "$1" = "verify" ]; then
  # The generator can output a compile time asserts to test if types we are substituting for
  # Tizen API types are of the same type - i.e. that our signatures are compatible with original
  # callbacks signatures.
  # When asserts are generated, the code is only useful for verification, not for calling callbacks.
  # Just the fact that the app with asserts is building means the signatures match.
  # Many combinations of profile and platform version cause issues with Tizen headers,
  # as not every header is available there, or they need to be included in specific order, etc.
  # Because of that a failing build does not always mean that our type substitution is wrong.
  VERIFY=yes
  ARCHS="${ARCHS:-arm arm64}" # arm64 x86
  PROFILES="${PROFILES:-common}" 	# mobile, wearable, tv
  declare -A SKIP_VERIFY_VERSIONS
  EXAMPLE_DIR="$SCRIPT_DIR/../packages/tizen_interop_callbacks/example"
  (cd "$EXAMPLE_DIR"; flutter-tizen pub get)
fi

if [ ! -d $ROOTSTRAPS ]; then
  echo "ERROR: Rootstraps directory not found."
  exit 1
fi

CONFIGS=""
declare -a VERIFY_RESULT
for C in "$SCRIPT_DIR"/../configs/*/ffigen.yaml; do
  echo $C
  VERSION="${C%/ffigen.yaml}"
  VERSION="${VERSION##*/}"
  echo "==== Found Tizen $VERSION config"
  D="$ROOTSTRAPS/$VERSION"
  if [ -d "$D" ]; then
    if [ "$VERIFY" = "yes" ]; then
      if [ -n "${SKIP_VERIFY_VERSIONS[$VERSION]}" ]; then
        VERIFY_RESULT[${#VERIFY_RESULT[@]}]="all   	-	$VERSION	skip"
        continue
      fi
      "$GENERATOR_ROOT/gen_callbacks.py" --asserts="$VERSION" -c $SCRIPT_DIR/../configs/$VERSION/ffigen.yaml -b $SCRIPT_DIR/../lib/src/bindings/$VERSION/generated_bindings.dart -o "$TARGET"
      sed -i '/manifest/ s/api-version="[0-9.]*"/api-version="'$VERSION'"/' "$EXAMPLE_DIR/tizen/tizen-manifest.xml"
      for PROFILE in $PROFILES; do
        for ARCH in $ARCHS; do
          echo -e "\e[32m$VERSION> flutter-tizen build tpk --device-profile $PROFILE --target-arch $ARCH\e[0m"
          LOGFILE="/tmp/tzincb-$PROFILE-$ARCH-$VERSION.log"
          (cd "$EXAMPLE_DIR"; flutter-tizen build tpk --device-profile $PROFILE --target-arch $ARCH --debug 2>&1 \
           | tee $LOGFILE)
          if grep -q "use of undeclared identifier" "$LOGFILE"; then
            RESULT="undeclared identifiers"
          elif grep -q "Wrong type substitution" "$LOGFILE"; then
            RESULT="ASSERTs failed"
          elif grep -q "Built.*callbacks_example.*.tpk" "$LOGFILE" ; then
            RESULT="ok"
          else
            RESULT="failed"
          fi
          VERIFY_RESULT[${#VERIFY_RESULT[@]}]="$PROFILE	$ARCH	$VERSION	$RESULT"
        done
      done
    else
      CONFIGS="-c $SCRIPT_DIR/../configs/$VERSION/ffigen.yaml -b $SCRIPT_DIR/../lib/src/bindings/$VERSION/generated_bindings.dart $CONFIGS"
    fi
  else
    echo "ERROR: Rootstrap $ROOTSTRAPS/$VERSION not found."
    exit 1
  fi
done
if [ "$VERIFY" == "yes" ]; then
  echo "======== Results of the verification"
  for x in "${!VERIFY_RESULT[@]}"; do printf "  %s\n" "${VERIFY_RESULT[$x]}" ; done
  exit
elif [ -z "$CONFIGS" ]; then
  echo "ERROR: No rootstrap found. Run copy_rootstrap.sh first."
  exit 1
fi
"$GENERATOR_ROOT/gen_callbacks.py" $CONFIGS -o "$TARGET"
