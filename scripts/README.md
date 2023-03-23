# tizen_interop tools

## Generating bindings from source

1. Install a rootstrap of your target Tizen version (e.g. `IOT-Headed-4.0-NativeAppDevelopment-CLI`) using Tizen Package Manager.

2. Run scripts in this directory as follows, passing the version number as an argument.

   ```sh
   scripts/copy_rootstrap.sh <version>
   scripts/generate_bindings.sh <version>
   ```

## Adding new Tizen version support

1. Create a copy of any existing config in the `configs` directory with the new version number as the directory name.

2. Manually update `entrypoints.h` and `symgen.yaml` by referring to the official [API docs](https://docs.tizen.org/application/native/api/iot-headed/latest) and the rootstrap.

3. Run `ffigen_helper.sh` to generate the contents of the `ffigen.yaml` file.

   ```sh
   scripts/ffigen_helper.sh <version>
   ```
