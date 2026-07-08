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
committed.

1. Create `configs/<version>/modules.yaml` by copying the previous version's file
   and updating `version`, `rootstrap_prefix`, and the module list by referring to
   the official [API docs](https://docs.tizen.org/application/native/api/iot-headed/latest)
   and the rootstrap (added/removed libraries and headers).

2. Generate the bindings. This renders the derived configs, runs symgen and
   ffigen for every module (in dependency order, so that symbol files exist
   before the modules that import them), renames anonymous structs/unions to
   module-unique names, converts Doxygen comments into Dartdoc format, and
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

### Inspecting the derived configs

To render the derived configs without running the generators:

```sh
python3 scripts/build_configs.py <version>            # writes to build/configs/<version>
python3 scripts/build_configs.py <version> --out-dir /tmp/rebuild
```

## Generating documentation

The `generate_doc_script.py` script generates markdown API documentation for all supported Tizen versions. It scans the `configs` directory and creates or overwrites `doc/tizen<version>_api.md` for each version.

Run the script with:

```sh
python3 scripts/generate_doc_script.py
```

## Handling Type Duplication Issues

When splitting single binding code into library-specific binding codes from version 0.5.2 onwards, type duplication issues may occur between binding codes. Here are common issues and their solutions. All solutions are expressed in `configs/<version>/modules.yaml`; the ffigen YAML shown below is what gets rendered from it.

### 1. Struct / Typedef / Union Type Duplication

**Issue**: When both `generated_bindings_A.dart` and `generated_bindings_B.dart` define `struct AA {...}` (or a typedef/union) and are exported through `tizen.dart`, a duplication error occurs.

**Solution**: Add a `deps` entry to module B in `modules.yaml`:

```yaml
- name: B
  ...
  deps:
    - A
```

This uses ffigen's symbol-file mechanism: module A's rendered config exports a
symbol file (`output.symbol-file` → `.symbols/A.yaml`) and module B's config
imports it (`import.symbol-files`). ffigen then references A's declarations
(`typedef AA = imp1.AA;`) instead of re-emitting them — for **every** type the
two modules share, so no per-type bookkeeping is needed. `generate_bindings.sh`
runs the modules in dependency order (`ffigen_order.txt`, providers first).

`scripts/resolve_type_dups.py <version>` derives these `deps` edges (plus the
enum/macro fixes below) automatically from `dart analyze` errors.

### 2. Enum Type Duplication

**Issue**: When both `generated_bindings_A.dart` and `generated_bindings_B.dart` define `enum {...} DD;` and are exported through `tizen.dart`, a duplication error occurs.

**Solution**: Add an `enum_renames` entry to module B (rename the enum to make it private by adding '_'):

```yaml
- name: B
  ...
  enum_renames:
    'DD': '_DD'
```

### 3. Unused Callback Definitions

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

### 4. Generic Type Issues with typedef

**Issue**: When there is code like `typedef __time_t time_t;` in a header file, generic type issues occur (generic types can only use basic types like int, double, or Pointer).

**Solution**: Add a `primitive_typedefs` entry mapping the typedefs to basic types:

```yaml
- name: notification
  ...
  primitive_typedefs:
    time_t: { c: Long, d: int }
    __time_t: { c: Long, d: int }
```

### 5. Unnamed Union Duplication

**Issue**: When unnamed unions are defined in C code, binding code generation automatically assigns names like `UnnamedUnion1`, causing duplication issues.

**Solution**: Handled automatically. `scripts/rename_unnamed.py` (run by
`generate_bindings.sh` after ffigen) prefixes every `UnnamedStructN` /
`UnnamedUnionN` with the module's class-name stem (e.g.
`CapiMediaCameraUnnamedUnion1`), making each one globally unique and nameable —
no `hide` needed.

### 6. Remaining Duplicate Exports

**Issue**: A top-level name (e.g. a macro constant emitted as `const int X = ...;`)
is declared by two modules that share no dependency edge.

**Solution**: Handled automatically. `generate_tizen.py` scans all binding files
for top-level declarations (classes, enums, typedefs, constants), keeps each
duplicated name on its owning module, and adds `hide` clauses to the other
modules' `export` lines in `tizen.dart`. Symbol-file typedef aliases
(`typedef X = impN.X;`) are recognized so the real declaration wins ownership.
