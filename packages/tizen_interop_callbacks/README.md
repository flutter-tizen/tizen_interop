# tizen_interop_callbacks

[![pub package](https://img.shields.io/pub/v/tizen_interop_callbacks.svg)](https://pub.dev/packages/tizen_interop_callbacks)

A Flutter plugin to resolve issues related to the error message: `Cannot invoke native callback outside an isolate`.

This package is designed to be used with the [`tizen_interop`](https://pub.dev/packages/tizen_interop) package.
Similarly to `tizen_interop`, this package has no build time dependency on a specific Tizen profile or version.

## Usage

1. Add this package and `tizen_interop` as dependencies in your `pubspec.yaml` file.

   ```yaml
   dependencies:
     ffi: ^2.0.1
     tizen_interop: ^0.4.0
     tizen_interop_callbacks: ^0.3.0
   ```

2. In your Dart code, import the packages:

   ```dart
   import 'dart:ffi';
   import 'package:tizen_interop/6.0/tizen.dart';
   import 'package:tizen_interop_callbacks/tizen_interop_callbacks.dart';
   ```

3. Instantiate the `TizenInteropCallbacks` class. This should be done in the root isolate - the thread where your `main()` is called.

   ```dart
   final callbacks = TizenInteropCallbacks();
   ```

4. Implement your callback in Dart and register it with `TizenInteropCallbacks`:

   ```dart
   final callback = _callbacks.register<Void Function(Int32, Pointer<Void>, Pointer<Void>)>(
     'device_changed_cb',
     Pointer.fromFunction(_batteryChanged),
   );
   ```

   The native function type to be used in `register<>()` can be obtained by checking
   the definition of the related callback type - the `device_changed_cb` in this case.

5. Pass the obtained callback pointer and user_data to the Native API function:

   > **Warning**
   >
   > Both `interopCallback` and `interopUserData` must be passed. The callback handling implementation relies on the `interopUserData`.
   > The only exceptions are a few callbacks that do not accept `user_data` parameters.

   ```dart
   final ret = tizen.device_add_callback(
     device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
     callback.interopCallback,
     callback.interopUserData,
   );
   ```
