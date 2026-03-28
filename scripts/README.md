# tizen_interop tools

## Copying a rootstrap

1. Install a rootstrap of your target Tizen version (e.g. `IOT-Headed-6.0-NativeAppDevelopment-CLI`) using Tizen Package Manager.

2. Run scripts in this directory as follows, passing the version number as an argument.

   ```sh
   scripts/copy_rootstrap.sh <version>
   ```

## Generating bindings for a new Tizen version

1. Create a copy of any existing config in the `configs` directory with the new version number as the directory name.

2. Manually update `entrypoints.h` and `symgen.yaml` by referring to the official [API docs](https://docs.tizen.org/application/native/api/iot-headed/latest) and the rootstrap. (Run `symgen_helper.sh` to find out what to add to `symgen.yaml`. (`scripts/symgen_helper.sh <version>`))

3. The `configs/<version>` directory copied in step 1 contains `ffigen_*.yaml` files from the previous version. To update these to the new version, run:

   ```sh
   python3 scripts/generate_ffigens.py <version>
   ```

4. If there are newly created files (`ffigen_*.yaml`), manually update their `include-directives:` by referring to the output of `scripts/ffigen_helper.sh <version>` or `rootstrap/<version>`.

5. To generate binding code per target library, run:

   ```sh
   scripts/generate_bindings.sh <version>
   ```

6. Generate the main `lib/<version>/tizen.dart` file which exports all bindings and initializes module instances:

   ```sh
   python3 scripts/generate_tizen.py <version>
   ```

   This script scans `generated_symbols.dart` and all individual binding files to construct the Dart codebase cleanly.
   If errors occur when running `dart analyze lib/<version>/tizen.dart` after generation, please refer to the **Handling Type Duplication Issues** section below to resolve them.

7. Update callbacks data.

   * Run `./generate_callbacks.sh verify` to check type substitution.
     Build errors will have to be addressed by editing `gen_callbacks.py`.
     If substitution is not found or assert fails - edit the type mapping
     (see `CallbackDataCollector.type_substitute()` and maps used there: `KNOWN_TYPES`, `SPECIAL_TYPES`).
   * Run `./generate_callbacks.sh` to update `callbacks.cc` with callbacks data.

## Handling Type Duplication Issues

When splitting single binding code into library-specific binding codes from version 0.5.2 onwards, type duplication issues may occur between binding codes. Here are common issues and their solutions:

### 1. Struct Type Duplication

**Issue**: When both `generated_bindings_A.dart` and `generated_bindings_B.dart` define `struct AA {...}` and are exported through `tizen.dart`, a duplication error occurs.

**Solution**: Add the following to the `ffigen_B.yaml` file used to generate `generated_bindings_B.dart`:

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

**Solution**: Add the following to the `ffigen_B.yaml` file used to generate `generated_bindings_B.dart`:

```yaml
library-imports:
  A_Header: 'generated_bindings_A.dart'

type-map:
  typedef:
    'AA':
      lib: 'A_Header'
      c-type: 'AA'
      dart-type: 'AA'
```

### 3. Enum Type Duplication

**Issue**: When both `generated_bindings_A.dart` and `generated_bindings_B.dart` define `enum {...} DD;` and are exported through `tizen.dart`, a duplication error occurs.

**Solution**: Add the following to the `ffigen_B.yaml` file used to generate `generated_bindings_B.dart` (rename the enum to make it private by adding '_'):

```yaml
enums:
  rename:
    'DD' : '_DD'
```

### 4. Unused Callback Definitions

**Issue**: When a callback is only defined in a header but not actually used, ffigen does not generate it (ffigen does not generate unused functions or types).

**Solution**: Create a separate header file and define a temporary private function that uses the callback:

```c
// Temp_C.h
#include <app_common.h>
void _force_generate_app_event_cb(app_event_cb callback) {}
```

```yaml
# ffigen_C.yaml
entry-points:
  - 'entrypoints.h'
  - 'Temp_C.h'
include-directives:
  - '**/app_common.h'
  - '**/app_resource_manager.h'
  - 'Temp_C.h'
```

### 5. Generic Type Issues with typedef

**Issue**: When there is code like `typedef __time_t time_t;` in a header file, generic type issues occur (generic types can only use basic types like int, double, or Pointer).

**Solution**: Map directly to basic types as follows:

```yaml
library-imports:
  ffi_lib: 'dart:ffi'

type-map:
  typedef:
    'time_t':
      lib: 'ffi_lib'
      c-type: 'Long'
      dart-type: 'int'
    '__time_t':
      lib: 'ffi_lib'
      c-type: 'Long'
      dart-type: 'int'
```

### 6. Unnamed Union Duplication

**Issue**: When unnamed unions are defined in C code, binding code generation automatically assigns names like `UnnamedUnion1`, causing duplication issues.

**Solution**: Add `hide UnnamedUnion1, UnnamedStruct1` after export:

```dart
export '../../src/bindings/6.0/generated_bindings_capi_media_camera.dart'
    hide UnnamedUnion1, UnnamedStruct1;
```

## Generating documentation

The `generate_doc_script.py` script generates markdown API documentation for all supported Tizen versions. It scans the `configs` directory and creates or overwrites `doc/tizen<version>_api.md` for each version.

Run the script with:

```sh
python3 scripts/generate_doc_script.py
```
