#!/usr/bin/env bash
# Copyright 2026 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd -P)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd -P)"

command="${1:-verify}"
if [ "$#" -gt 0 ]; then
  shift
fi

version="6.0"
if [ "$#" -gt 0 ] && [ "${1#--}" = "$1" ]; then
  version="$1"
  shift
fi

cd "$ROOT_DIR"
dart run tool/prepare_pubdev_module_docs.dart "$command" --version "$version" "$@"
