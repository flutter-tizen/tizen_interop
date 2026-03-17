# tizen_interop tools

## Generating bindings from source

1. Install a rootstrap of your target Tizen version (e.g. `IOT-Headed-6.0-NativeAppDevelopment-CLI`) using Tizen Package Manager.

2. Run scripts in this directory as follows, passing the version number as an argument.

   ```sh
   scripts/copy_rootstrap.sh <version>
   scripts/generate_bindings.sh <version>
   ```

## Adding new Tizen version support

1. Create a copy of any existing config in the `configs` directory with the new version number as the directory name.

2. Manually update `entrypoints.h` and `symgen.yaml` by referring to the official [API docs](https://docs.tizen.org/application/native/api/iot-headed/latest) and the rootstrap. (Run `symgen_helper.sh` to find out what to add to `symgen.yaml`. (`scripts/symgen_helper.sh <version>`))

3. Run `ffigen_helper.sh` to generate the contents of the `ffigen.yaml` file.

   ```sh
   scripts/ffigen_helper.sh <version>
   ```

4. Update callbacks data.

   * Run `./generate_callbacks.sh verify` to check type substitution.
     Build errors will have to be addressed by editing `gen_callbacks.py`.
     If substitution is not found or assert fails - edit the type mapping
     (see `CallbackDataCollector.type_substitute()` and maps used there: `KNOWN_TYPES`, `SPECIAL_TYPES`).
   * Run `./generate_callbacks.sh` to update `callbacks.cc` with callbacks data.

## Generating documentation

The `generate_doc_script.py` script generates markdown API documentation for all supported Tizen versions. It scans the `configs` directory and creates or overwrites `doc/tizen<version>_api.md` for each version.

Run the script with:

```sh
python3 scripts/generate_doc_script.py
```

## Preparing module-scoped pub.dev docs

`pub.dev` generates API docs only from the uploaded package contents. To avoid
publishing one oversized API page for `package:tizen_interop/6.0/tizen.dart`,
prepare a publish-time docs library and a root `dartdoc_options.yaml`
before publishing.

Use:

```sh
scripts/prepare_pubdev_module_docs.sh prepare 6.0
```

This generates:

1. A docs-only library at `lib/6.0/tizen_docs.dart`
2. A publish-time `dartdoc_options.yaml`

The generated `dartdoc_options.yaml` is intentionally scoped to the docs-only
library:

* groups APIs under version/module topic pages such as `Tizen 6.0 / accounts_svc`
* excludes the original monolithic `tizen_interop` library
* includes only the generated docs library
* reuses the shared topic markdown at `doc/dartdoc/module_topic.md`

Running `prepare` again for another version updates the same root
`dartdoc_options.yaml` so it covers all currently prepared versions. For
example, running `prepare 6.0` and then `prepare 6.5` produces one
`dartdoc_options.yaml` containing both `Tizen 6.0 / ...` and
`Tizen 6.5 / ...` module topic entries.

To verify the exact publish-time setup:

```sh
scripts/prepare_pubdev_module_docs.sh verify 6.0
```

`verify` prepares the docs library, runs `dart doc --validate-links`,
runs `dart pub publish --dry-run`, and then removes the generated publish-time
files again. Pass `--keep-generated` if the package should remain in the
publish-ready state after verification. If other versions are already prepared,
their generated `dartdoc_options.yaml` entries stay in place and only the
verified version is cleaned up.

To remove the generated publish-time files:

```sh
scripts/prepare_pubdev_module_docs.sh clean 6.0
```

`clean` removes only the generated files for that version and rebuilds the root
`dartdoc_options.yaml` from any remaining prepared versions. When the last
prepared version is cleaned, the original `dartdoc_options.yaml` is restored
if one existed before preparation.

If a symbol from `generated_symbols.dart` is not found in
`generated_bindings.dart` and appears callback-related, the generated docs
namespace points readers to `package:tizen_interop_callbacks` so callback APIs
can be checked through `TizenInteropCallbacks.register()`,
`RegisteredCallback.interopCallback`, and
`RegisteredCallback.interopUserData`.
