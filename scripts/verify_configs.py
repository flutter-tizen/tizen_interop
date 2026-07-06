#!/usr/bin/env python3
# Compare two configs/<version>/ directories by YAML semantic equality.
# The preamble copyright year is normalized (intentional unification).

from __future__ import annotations

import argparse
import os
import re
import sys

import yaml


def norm_preamble(s: str) -> str:
    return re.sub(r'Copyright\s+\d{4}', 'Copyright YYYY', s or '')


def _norm_entrypoint_glob(p: str) -> str:
    """Normalize '**/entrypoints_<name>.h' -> 'entrypoints_<name>.h'.
    Both forms are equivalent to ffigen but historically inconsistent."""
    if p.startswith('**/entrypoints') and p.endswith('.h'):
        return p[3:]
    return p


def load_ffigen(path):
    with open(path) as f:
        d = yaml.safe_load(f)
    # Normalize preamble year
    if 'preamble' in d:
        d['preamble'] = norm_preamble(d['preamble'])
    # Normalize include-directives glob for entrypoint headers
    hdrs = (d.get('headers') or {})
    if 'include-directives' in hdrs:
        hdrs['include-directives'] = [
            _norm_entrypoint_glob(x) for x in hdrs['include-directives']
        ]
    return d


def dict_diff(a, b, path=''):
    """Return a list of human-readable diff strings."""
    diffs = []
    if type(a) != type(b):
        diffs.append(f"{path}: type differs ({type(a).__name__} vs {type(b).__name__})")
        return diffs
    if isinstance(a, dict):
        keys = set(a.keys()) | set(b.keys())
        for k in sorted(keys):
            sub = f"{path}.{k}" if path else k
            if k not in a:
                diffs.append(f"{sub}: missing in A")
            elif k not in b:
                diffs.append(f"{sub}: missing in B")
            else:
                diffs.extend(dict_diff(a[k], b[k], sub))
    elif isinstance(a, list):
        if len(a) != len(b):
            diffs.append(f"{path}: list length {len(a)} vs {len(b)}")
        for i, (x, y) in enumerate(zip(a, b)):
            diffs.extend(dict_diff(x, y, f"{path}[{i}]"))
    else:
        if a != b:
            diffs.append(f"{path}: {a!r} vs {b!r}")
    return diffs


def norm_c_include_comment(content: str) -> str:
    """Normalize // comment spacing in C include lines."""
    lines = []
    for line in content.splitlines():
        m = re.match(r'^(#include\s*<[^>]+>)\s*//\s*(.*)$', line)
        if m:
            line = f"{m.group(1)}  // {m.group(2).strip()}"
        lines.append(line)
    return '\n'.join(lines) + '\n'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('a', help='First configs/<version>/ dir (e.g. original)')
    ap.add_argument('b', help='Second configs/<version>/ dir (e.g. regenerated)')
    args = ap.parse_args()

    total = 0
    failed = 0

    # ffigen_*.yaml
    for fname in sorted(os.listdir(args.a)):
        if not (fname.startswith('ffigen_') and fname.endswith('.yaml')):
            continue
        pa = os.path.join(args.a, fname)
        pb = os.path.join(args.b, fname)
        total += 1
        if not os.path.exists(pb):
            print(f"MISSING in B: {fname}")
            failed += 1
            continue
        da = load_ffigen(pa)
        db = load_ffigen(pb)
        diffs = dict_diff(da, db)
        if diffs:
            failed += 1
            print(f"\n[DIFF] {fname}:")
            for d in diffs[:10]:
                print(f"  {d}")
            if len(diffs) > 10:
                print(f"  ... {len(diffs)-10} more")

    # symgen.yaml
    pa = os.path.join(args.a, 'symgen.yaml')
    pb = os.path.join(args.b, 'symgen.yaml')
    if os.path.exists(pa) and os.path.exists(pb):
        with open(pa) as f: da = yaml.safe_load(f)
        with open(pb) as f: db = yaml.safe_load(f)
        # normalize preamble year
        if 'preamble' in da: da['preamble'] = norm_preamble(da['preamble'])
        if 'preamble' in db: db['preamble'] = norm_preamble(db['preamble'])
        diffs = dict_diff(da, db)
        total += 1
        if diffs:
            failed += 1
            print(f"\n[DIFF] symgen.yaml:")
            for d in diffs[:20]:
                print(f"  {d}")

    # entrypoints.h (normalize // comment spacing)
    for hdr in ['entrypoints.h']:
        pa = os.path.join(args.a, hdr)
        pb = os.path.join(args.b, hdr)
        if os.path.exists(pa) and os.path.exists(pb):
            ca = norm_c_include_comment(open(pa).read())
            cb = norm_c_include_comment(open(pb).read())
            total += 1
            if ca != cb:
                failed += 1
                print(f"\n[DIFF] {hdr} (after // comment normalization)")
                import difflib
                for line in list(difflib.unified_diff(ca.splitlines(), cb.splitlines(),
                                                       fromfile='A', tofile='B', lineterm=''))[:40]:
                    print(f"  {line}")

    print(f"\n--- Summary ---")
    print(f"Total files checked: {total}")
    print(f"Failed: {failed}")
    if failed == 0:
        print("OK: semantic equivalence achieved.")
    sys.exit(0 if failed == 0 else 1)


if __name__ == '__main__':
    main()
