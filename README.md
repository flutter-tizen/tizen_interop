# tizen_interop

This package provides Dart bindings and utility functions for using Tizen native APIs.

## Example

```dart
import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'package:tizen_interop/4.0/wearable/tizen.dart';

String? getApplicationName() {
  String? appName;
  using((Arena arena) {
    Pointer<Pointer<Int8>> namePtr = arena.allocate(sizeOf<Pointer>());
    tizen.app_get_name(namePtr);
    appName = namePtr.value.toDartString();
    malloc.free(namePtr.value);
  });
  return appName;
}
```
