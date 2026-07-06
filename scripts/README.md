# tizen_interop tools

## Copying a rootstrap

1. Install a rootstrap of your target Tizen version (e.g. `IOT-Headed-6.0-NativeAppDevelopment-CLI`) using Tizen Package Manager.

2. Run scripts in this directory as follows, passing the version number as an argument.

   ```sh
   scripts/copy_rootstrap.sh <version>
   ```

## Generating bindings for a new Tizen version

The only hand-maintained config file per version is `configs/<version>/modules.yaml`.
Everything else (`symgen.yaml`, `entrypoints.h`, `entrypoints_*.h`, `ffigen_*.yaml`)
is rendered from it into `build/configs/<version>/` at generation time and is not
committed. See `doc/MODULES_SCHEMA.md` for the schema.

1. Create `configs/<version>/modules.yaml` by copying the previous version's file
   and updating `version`, `rootstrap_prefix`, and the module list by referring to
   the official [API docs](https://docs.tizen.org/application/native/api/iot-headed/latest)
   and the rootstrap (added/removed libraries and headers).

2. Generate the bindings. This renders the derived configs, runs symgen and
   ffigen for every module, converts Doxygen comments into Dartdoc format, and
   regenerates `lib/<version>/tizen.dart`:

   ```sh
   scripts/generate_bindings.sh <version>
   ```

   If errors occur when running `dart analyze lib/<version>/tizen.dart` after
   generation, refer to the **Handling Type Duplication Issues** section below.

3. Update callbacks data.

   * Run `./generate_callbacks.sh verify` to check type substitution.
     Build errors will have to be addressed by editing `gen_callbacks.py`.
     If substitution is not found or assert fails - edit the type mapping
     (see `CallbackDataCollector.type_substitute()` and maps used there: `KNOWN_TYPES`, `SPECIAL_TYPES`).
   * Run `./generate_callbacks.sh` to update `callbacks.cc` with callbacks data.

4. Check consistency between `modules.yaml` and the generated files (also run in CI):

   ```sh
   python3 scripts/check_consistency.py
   ```

### Inspecting or verifying the derived configs

To render the derived configs without running the generators:

```sh
python3 scripts/build_configs.py <version>            # writes to build/configs/<version>
python3 scripts/build_configs.py <version> --out-dir /tmp/rebuild
```

`verify_configs.py` compares two config directories for semantic YAML equality
(copyright years and comment spacing are normalized). It was used to prove that
`build_configs.py` round-trips the previously committed configs, and remains
useful when refactoring the generator:

```sh
python3 scripts/verify_configs.py <dir_a> <dir_b>
```

`import_configs.py` is the one-time migration helper that bootstrapped
`modules.yaml` from the old hand-written configs.

## Generating documentation

The `generate_doc_script.py` script generates markdown API documentation for all supported Tizen versions. It scans the `configs` directory and creates or overwrites `doc/tizen<version>_api.md` for each version.

Run the script with:

```sh
python3 scripts/generate_doc_script.py
```

## Handling Type Duplication Issues

When splitting single binding code into library-specific binding codes from version 0.5.2 onwards, type duplication issues may occur between binding codes. Here are common issues and their solutions. All solutions are expressed in `configs/<version>/modules.yaml`; the ffigen YAML shown below is what gets rendered from it.

### 1. Struct Type Duplication

**Issue**: When both `generated_bindings_A.dart` and `generated_bindings_B.dart` define `struct AA {...}` and are exported through `tizen.dart`, a duplication error occurs.

**Solution**: Add an `imports` entry to module B in `modules.yaml`:

```yaml
- name: B
  ...
  imports:
    - from: A
      as: A_Header
      structs:
        - AA
```

which renders into `ffigen_B.yaml` as:

```yaml
library-imports:
  A_Header: 'generated_bindings_A.dart'

type-map:
  structs:
    'AA':
      lib: 'A_Header'
      c-type: 'AA'
      dart-type: 'AA'
```

### 2. Typedef Type Duplication

**Issue**: When both `generated_bindings_A.dart` and `generated_bindings_B.dart` define `typedef AA BB` and are exported through `tizen.dart`, a duplication error occurs.

**Solution**: Same as above, using the `typedefs` list of the `imports` entry:

```yaml
- name: B
  ...
  imports:
    - from: A
      as: A_Header
      typedefs:
        - AA
```

### 3. Enum Type Duplication

**Issue**: When both `generated_bindings_A.dart` and `generated_bindings_B.dart` define `enum {...} DD;` and are exported through `tizen.dart`, a duplication error occurs.

**Solution**: Add an `enum_renames` entry to module B (rename the enum to make it private by adding '_'):

```yaml
- name: B
  ...
  enum_renames:
    'DD': '_DD'
```

### 4. Unused Callback Definitions

**Issue**: When a callback is only defined in a header but not actually used, ffigen does not generate it (ffigen does not generate unused functions or types).

**Solution**: Add a `force_types` entry to the module. This renders a dummy
`entrypoints_<name>.h` with private functions that use the types, and adds
it to the module's entry points:

```yaml
- name: capi_appfw_app_common
  ...
  force_types:
    - name: app_event_cb
      type: app_event_cb
      arg: callback
```

### 5. Generic Type Issues with typedef

**Issue**: When there is code like `typedef __time_t time_t;` in a header file, generic type issues occur (generic types can only use basic types like int, double, or Pointer).

**Solution**: Add a `primitive_typedefs` entry mapping the typedefs to basic types:

```yaml
- name: notification
  ...
  primitive_typedefs:
    time_t: { c: Long, d: int }
    __time_t: { c: Long, d: int }
```

### 6. Unnamed Union Duplication

**Issue**: When unnamed unions are defined in C code, binding code generation automatically assigns names like `UnnamedUnion1`, causing duplication issues.

**Solution**: Handled automatically. `generate_tizen.py` scans the binding files
for top-level `UnnamedUnionN`/`UnnamedStructN` declarations and, for every name
declared by more than one module, keeps it exported from the first module and
adds `hide` clauses to the others.
