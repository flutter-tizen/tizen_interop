# tizen_interop

This package provides Dart bindings and utility functions for using Tizen native APIs.

## ❗ Experimental ❗

This package is in experimental stage. It is not intended for production use.
Only specific versions and profiles of Tizen are supported, and some binding APIs may be missing or have errors.
Graphics and WebView related APIs are not provided. 

## Example

```dart
import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'package:tizen_interop/4.0/wearable/tizen.dart';

String? getApplicationName() {
  String? appName;
  using((Arena arena) {
    Pointer<Pointer<Int8>> namePtr = arena();
    tizen.app_get_name(namePtr);
    appName = namePtr.value.toDartString();
    malloc.free(namePtr.value);
  });
  return appName;
}
```
