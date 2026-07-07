#!/usr/bin/env python3
# Scan rootstraps/<version> and write configs/<version>/rootstrap_manifest.yaml.
#
# The manifest is the committed baseline that update_modules.py diffs new
# rootstraps against (rootstraps/ is gitignored and older SDKs may be
# uninstalled). Run this once per version right after copy_rootstrap.sh.

from __future__ import annotations

import argparse
import os
import sys

from rootstrap_index import ROOT, RootstrapIndex


def main():
    ap = argparse.ArgumentParser(
        description='Index a rootstrap into configs/<version>/rootstrap_manifest.yaml')
    ap.add_argument('version')
    ap.add_argument('--rootstrap', default=None,
                    help='Rootstrap dir. Default: rootstraps/<version>')
    ap.add_argument('--output', default=None,
                    help='Output path. Default: configs/<version>/rootstrap_manifest.yaml')
    args = ap.parse_args()

    rootstrap = args.rootstrap or os.path.join(ROOT, 'rootstraps', args.version)
    if not os.path.isdir(os.path.join(rootstrap, 'usr')):
        sys.exit(f'No rootstrap at {rootstrap}. Run scripts/copy_rootstrap.sh first.')
    out = args.output or os.path.join(ROOT, 'configs', args.version,
                                      'rootstrap_manifest.yaml')
    os.makedirs(os.path.dirname(out), exist_ok=True)

    idx = RootstrapIndex.scan(args.version, rootstrap)
    idx.to_manifest(out)
    print(f'Wrote {out}: {len(idx.lib_files)} libraries, '
          f'{len(idx.headers)} headers, {len(idx.pcs)} pkg-config files')


if __name__ == '__main__':
    main()
