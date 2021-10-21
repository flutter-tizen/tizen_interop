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

entrypoints=$ROOT_DIR/configs/$version/entrypoints.h
rootstraps=$ROOT_DIR/rootstraps/$version

if [[ ! -f "$entrypoints" ]]; then
    echo "Not found $entrypoints"
    exit 1
fi

if [[ ! -d "$rootstraps" ]]; then
    echo "Not found $rootstraps"
    exit 1
fi

headers=$(cat $entrypoints | grep "#include" | sed -r 's/#include <(.+)>/\1/')

# print include-directives
find_files() {
    for x in $headers; do
        find $rootstraps -path "*/$x" \
            -not -path "*/linux/*" \
            -not -path "*/unicode/*" \
            | sed -e "s#^$rootstraps/usr/include/##"
    done | sort
}

find_directories() {
    for x in $(find_files | grep "/"); do
        dirname $x
    done | sort | uniq
}

echo "include-directives:"
for x in $(find_files | grep -v "/"); do
    echo "  - '**/$x'"
done
for x in $(find_directories); do
    echo "  - '**/$x/*.h'"
done

# print compiler-opts:
find_includes() {
    for x in $headers; do
        find $rootstraps -path "*/$x" \
            -not -path "*/linux/*" \
            -not -path "*/unicode/*" \
            -exec realpath --relative-to=$ROOT_DIR {} \; \
             | sed -e "s#$x\$##"
    done | sort | uniq
}

echo "compiler-opts:"
for x in $(find_includes); do
    echo "  - '-I./$x'"
done
