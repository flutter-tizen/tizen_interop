#!/usr/bin/env python3
# Copyright 2026 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import argparse
import os
import re
import subprocess

TEMPLATE = """preamble: |
  // Copyright 2026 Samsung Electronics Co., Ltd. All rights reserved.
  // Use of this source code is governed by a BSD-style license that can be
  // found in the LICENSE file.
  // ignore_for_file: type=lint, unused_element, unused_field

name: 'Tizen{non_pointed_version}{camel_name}'

description: 'Dart bindings for Tizen {dashed_name} APIs.'

output: '../../lib/src/bindings/{version}/generated_bindings_{snake_name}.dart'

llvm-path:
  - '/usr/lib/llvm-12'

headers:
  entry-points:
    - 'entrypoints.h'
  include-directives:{include_directives}

compiler-opts:
  - '-m32'
  - '-Wno-incomplete-setjmp-declaration'

  # include Tizen API directories
{compiler_opts_dirs}

  # include EFL directories
  - '-I./rootstraps/{version}/usr/include/ecore-imf-1/'
  - '-I./rootstraps/{version}/usr/include/efl-1/'
  - '-I./rootstraps/{version}/usr/include/eina-1/'
  - '-I./rootstraps/{version}/usr/include/eina-1/eina/'
  - '-I./rootstraps/{version}/usr/include/emile-1/'
  - '-I./rootstraps/{version}/usr/include/eo-1/'
  - '-I./rootstraps/{version}/usr/include/evas-1/'

  # include glib directories
  - '-I./rootstraps/{version}/usr/include/glib-2.0/'
  - '-I./rootstraps/{version}/usr/lib/glib-2.0/include/'

enums:
  rename:
    '_+(.*)': '$1'
"""

def get_camel_name(dashed_name):
    return "".join(word.capitalize() for word in re.split(r'[-_]', dashed_name) if word)

def get_snake_name(dashed_name):
    return dashed_name.replace('-', '_')

def parse_target_libraries(symgen_path):
    target_libs = []
    with open(symgen_path, 'r') as f:
        in_target_libs = False
        for line in f:
            stripped = line.strip()
            if stripped.startswith('target-libraries:'):
                in_target_libs = True
                continue
            if in_target_libs:
                if stripped.startswith('-'):
                    lib_str = stripped.split('- ')[1].split()[0]
                    if lib_str.startswith('lib'):
                        lib_str = lib_str[len('lib'):]
                    if '.so' in lib_str:
                        lib_str = lib_str.split('.so')[0]
                    target_libs.append(lib_str)
                elif stripped and not re.match(r'^[#]', stripped):
                    in_target_libs = False
    return target_libs

def run_ffigen_helper(version):
    script_dir = os.path.dirname(os.path.realpath(__file__))
    script_path = os.path.join(script_dir, 'ffigen_helper.sh')
    
    print(f"Running {script_path} {version}...")
    res = subprocess.run([script_path, version], capture_output=True, text=True)
    if res.returncode != 0:
        print(f"Error running ffigen_helper.sh:\n{res.stderr}")
        return [], []
    
    include_directives = []
    compiler_opts = []
    
    mode = None
    for line in res.stdout.splitlines():
        if line.startswith('include-directives:'):
            mode = 'include'
            continue
        elif line.startswith('compiler-opts:'):
            mode = 'compiler'
            continue
        
        if mode == 'include' and line.strip().startswith("- '**/"):
            include_directives.append(line.strip())
        elif mode == 'compiler' and "- '-I./" in line:
            compiler_opts.append(line.strip())
            
    return include_directives, compiler_opts



def guess_base_version(content):
    m = re.search(r'bindings/(\d+\.\d+)/', content)
    if m:
        return m.group(1)
    m = re.search(r'rootstraps/(\d+\.\d+)/', content)
    if m:
        return m.group(1)
    return None

def main():
    parser = argparse.ArgumentParser(description="Automate ffigen_XXX.yaml generation")
    parser.add_argument('version', help='New Tizen version (e.g. 6.5)')
    args = parser.parse_args()

    version = args.version
    non_pointed_version = version.replace('.', '')
    
    script_dir = os.path.dirname(os.path.realpath(__file__))
    root_dir = os.path.dirname(script_dir)
    config_dir = os.path.join(root_dir, 'configs', version)
    symgen_path = os.path.join(config_dir, 'symgen.yaml')
    
    if not os.path.exists(symgen_path):
        print(f"Error: {symgen_path} does not exist.")
        return

    target_libs = parse_target_libraries(symgen_path)
    
    all_include_directives, compiler_opts_dirs = run_ffigen_helper(version)
    if not compiler_opts_dirs:
        print("Warning: compiler-opts are empty from ffigen_helper.sh output!")
        
    compiler_opts_str_raw = "\n".join([f"  {opt}" for opt in compiler_opts_dirs])
    
    existing_files = [f for f in os.listdir(config_dir) if (f.startswith('ffigen_')) and f.endswith('.yaml')]
    
    if 'ffigen_time.yaml' in existing_files and 'time' not in target_libs:
        target_libs.append('time')

    created_files = []
    deleted_files = []
    
    for lib in target_libs:
        lib_snake = lib.replace('-', '_')
        filename = f"ffigen_{lib_snake}.yaml"
        filepath = os.path.join(config_dir, filename)
        
        if filename in existing_files:
            existing_files.remove(filename)
            with open(filepath, 'r') as f:
                content = f.read()
            
            base_version = guess_base_version(content)
            if base_version and base_version != version:
                base_non_pointed_version = base_version.replace('.', '')
                content = content.replace(f'/{base_version}/', f'/{version}/')
                content = content.replace(f'Tizen{base_non_pointed_version}', f'Tizen{non_pointed_version}')
            
            pattern = re.compile(
                r'(#[ \t]*include Tizen API directories\n)(.*?)(?=\n[ \t]*#[ \t]*include |\n[ \t]*enums:|\Z)', 
                re.DOTALL
            )
            
            if pattern.search(content):
                content = pattern.sub(lambda m: m.group(1) + compiler_opts_str_raw, content)
            else:
                print(f"[{filename}] Warning: '# include Tizen API directories' not found.")
                
            with open(filepath, 'w') as f:
                f.write(content)
                
        else:
            created_files.append(filename)
            includes_str = "\n    -"
                
            file_content = TEMPLATE.format(
                non_pointed_version=non_pointed_version,
                camel_name=get_camel_name(lib),
                dashed_name=lib,
                version=version,
                snake_name=get_snake_name(lib),
                include_directives=includes_str,
                compiler_opts_dirs=compiler_opts_str_raw
            )
            with open(filepath, 'w') as f:
                f.write(file_content)

    for f in existing_files:
        if f == 'ffigen.yaml' or f == 'symgen.yaml':
            continue
        try:
            os.remove(os.path.join(config_dir, f))
            deleted_files.append(f)
        except OSError as e:
            print(f"Error removing {f}: {e}")

    print("\n--- Summary ---")
    print(f"Created {len(created_files)} files:")
    for f in created_files:
        print(f"  + {f}")
        
    print(f"\nDeleted {len(deleted_files)} files:")
    for f in deleted_files:
        print(f"  - {f}")

    print("\nSuccess. Run formatters or test with `dart run ffigen` to verify.")

if __name__ == '__main__':
    main()
