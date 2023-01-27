# tizen_interop_callbacks

A tizen_interop_callbacks plugin has been create to solve the issue relate to error message: `Cannot invoke native callback outside an isolate`.

All callbacks from common profile (IoT) for Tizen 4.0 ~ 6.5
are available and can be used on any platform.
Similarly to tizen_interop itself, there is no build-time dependency.

## Getting Started

See TizenInteropCallbacks class documentation.

1. Add this package to your application dependencies - pubspec.yaml. tizen_interop will be needed too:
``` yaml
  ffi: ^2.0.1
  tizen_interop: ^0.2.2
  tizen_interop_callbacks:  ^0.1.0
```

2. In your Dart code import the packages:
``` dart
import 'dart:ffi';
import 'package:tizen_interop/6.5/tizen.dart';
import 'package:tizen_interop_callbacks/tizen_interop_callbacks.dart';
```

3. Instantiate the TizenInteropCallbacks class. It should be done in your main thread - the thread your `main()` entry point is called.
``` dart
final callbacks = TizenInteropCallbacks();
```

4. Implement your callback in dart and register it with TizenInteropCallbacks:
``` dart
var levelCb = callbacks.register<Void Function(Int32, Pointer<Void>, Pointer<Void>)>(
  'device_changed_cb', Pointer.fromFunction(_batteryChanged));
```

The native function type to be used in `callbacks.register<>()` can be obtained by checking
the definition of related callback type - the `device_changed_cb` in this case.

5. Pass the obtained callback pointer and user data to Native API set/add callback function:
``` dart
ret = tizen.device_add_callback(
  device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
  levelCb.regCallbackPtr,
  levelCb.regUserData);
```

Both `regCallbackPtr` and `regUserData` must be used. The callbacks handling implementation relies on the `regUserData`.
The only exception are the few callbacks that do not have a user_data parameter.
