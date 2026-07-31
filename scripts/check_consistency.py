#!/usr/bin/env python3
# Check that configs/<version>/modules.yaml and the committed generated files
# under lib/ agree with each other. Intended for CI (does not require
# rootstraps or regeneration).
#
# Checks per version:
#   1. Every module in modules.yaml has lib/src/bindings/<version>/
#      generated_bindings_<name>.dart, and vice versa.
#   2. lib/<version>/tizen.dart imports/exports exactly the binding files.
#   3. modules.yaml survives the shared load/dump round trip byte-for-byte.
#   4. Every deps entry names an existing module and the graph is acyclic
#      (ffigen runs providers before consumers).

from __future__ import annotations

import os
import re
import sys

import modules_yaml
import yaml

ROOT = os.path.dirname(os.path.dirname(os.path.realpath(__file__)))


def check_version(version: str) -> list[str]:
    errors = []
    cfg_path = os.path.join(ROOT, 'configs', version, 'modules.yaml')
    bindings_dir = os.path.join(ROOT, 'lib', 'src', 'bindings', version)
    tizen_dart = os.path.join(ROOT, 'lib', version, 'tizen.dart')

    if not modules_yaml.roundtrip_check(cfg_path):
        errors.append(f'{version}: modules.yaml does not round-trip through '
                      'scripts/modules_yaml.py')

    with open(cfg_path) as f:
        cfg = yaml.safe_load(f)
    module_names = {m['name'] for m in cfg['modules']}

    # 1. modules.yaml <-> generated_bindings_*.dart
    binding_names = set()
    for fname in os.listdir(bindings_dir):
        m = re.fullmatch(r'generated_bindings_(\w+)\.dart', fname)
        if m:
            binding_names.add(m.group(1))
    for name in sorted(module_names - binding_names):
        errors.append(f'{version}: module "{name}" in modules.yaml has no '
                      f'generated_bindings_{name}.dart')
    for name in sorted(binding_names - module_names):
        errors.append(f'{version}: generated_bindings_{name}.dart has no '
                      f'module entry in modules.yaml')

    # 2. tizen.dart imports exactly the binding files
    with open(tizen_dart) as f:
        tz = f.read()
    imported = set(re.findall(r"generated_bindings_(\w+)\.dart", tz))
    for name in sorted(binding_names - imported):
        errors.append(f'{version}: lib/{version}/tizen.dart does not reference '
                      f'generated_bindings_{name}.dart')
    for name in sorted(imported - binding_names):
        errors.append(f'{version}: lib/{version}/tizen.dart references missing '
                      f'generated_bindings_{name}.dart')

    # 4. deps point at existing modules and form a DAG
    deps = {m['name']: list(m.get('deps') or []) for m in cfg['modules']}
    for name, dlist in sorted(deps.items()):
        for d in dlist:
            if d not in module_names:
                errors.append(f'{version}: module "{name}" deps on unknown '
                              f'module "{d}"')
    done: set[str] = set()
    remaining = {n for n, dl in deps.items()}
    while remaining:
        ready = {n for n in remaining
                 if all(d in done or d not in module_names for d in deps[n])}
        if not ready:
            errors.append(f'{version}: dependency cycle among '
                          f'{", ".join(sorted(remaining))}')
            break
        done |= ready
        remaining -= ready

    return errors


def main():
    versions = sys.argv[1:]
    if not versions:
        configs_dir = os.path.join(ROOT, 'configs')
        versions = sorted(
            v for v in os.listdir(configs_dir)
            if os.path.exists(os.path.join(configs_dir, v, 'modules.yaml')))
    all_errors = []
    for v in versions:
        all_errors.extend(check_version(v))
    for e in all_errors:
        print(f'ERROR: {e}')
    if all_errors:
        sys.exit(1)
    print(f'OK: {len(versions)} version(s) consistent '
          f'({", ".join(versions)})')


if __name__ == '__main__':
    main()
