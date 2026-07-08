#!/usr/bin/env python3
# Copyright 2026 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Give ffigen's anonymous structs/unions a module-unique name.

ffigen names anonymous (tag-less) structs/unions `UnnamedStruct<N>` /
`UnnamedUnion<N>` per file, and this naming bypasses its rename config
(compounddecl_parser uses an incremental namer, not renameUsingConfig). Across
modules these identical names are DIFFERENT types, so re-exporting them through
tizen.dart collides and they have to be `hide`-n — which also makes them
unnameable from the consumer.

These types are file-local (location-based, never shared via symbol-file import),
so renaming them within each generated binding — declaration and all references —
is safe and self-contained. We prefix each with the module's class-name stem
(e.g. UnnamedUnion1 -> CapiMediaCameraUnnamedUnion1), making every one globally
unique and nameable, with no hide needed.

Usage: python3 scripts/rename_unnamed.py <version>
"""

import glob
import os
import re
import sys

from modules_yaml import to_upper_camel as camel


def main():
    if len(sys.argv) != 2:
        print('usage: rename_unnamed.py <version>', file=sys.stderr)
        return 1
    version = sys.argv[1]
    root = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))
    bindings_dir = os.path.join(root, 'lib', 'src', 'bindings', version)

    pattern = re.compile(r'\bUnnamed(Struct|Union)(\d+)\b')
    changed = 0
    for path in sorted(glob.glob(os.path.join(bindings_dir,
                                              'generated_bindings_*.dart'))):
        mid = re.search(r'generated_bindings_(.+)\.dart', path).group(1)
        prefix = camel(mid)
        with open(path) as f:
            content = f.read()
        new = pattern.sub(rf'{prefix}Unnamed\1\2', content)
        if new != content:
            with open(path, 'w') as f:
                f.write(new)
            changed += 1
    print(f'Renamed anonymous structs/unions in {changed} file(s).')
    return 0


if __name__ == '__main__':
    sys.exit(main())
