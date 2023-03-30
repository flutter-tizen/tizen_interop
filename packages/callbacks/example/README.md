# tizen_interop_callbacks_example

Demonstrates how to use the tizen_interop_callbacks plugin.

## Getting Started

The application consists of 2 tabs showing:
- battery status
- camera preview resolutions.

### Battery
Here, a typical scenario is shown. We need to receive callbacks, but the Tizen Native API
invokes the callback from another thread. Attempt to use function pointer obtained
from [Pointer.fromFunction()](https://api.flutter.dev/flutter/dart-ffi/Pointer/fromFunction.html)
to [device_add_callback()](https://docs.tizen.org/application/native/api/mobile/4.0/group__CAPI__SYSTEM__DEVICE__CALLBACK__MODULE.html#ga89a756a9c46fb670f603d79b66af6cf0)
will cause error when callback is called.
Because of that, TizenInteropCallbacks is used to obtain native proxy callback runnable in any thread.

The app shows status of battery - battery level and if charger is connected.
The status is checked at start and then updated when callback with information
about change is called.

Not every Tizen device supports battery.

You can run the example on emulator and use the Control Panel to simulate
changes in charger/battery status.

### Camera preview resolutions
Here, a workaround for a locking issue is presented. Usually, a foreach API function would call the callback directly.
Then, TizenInteropCallbacks would not be needed at all.

[camera_foreach_supported_preview_resolution](https://docs.tizen.org/application/native/api/mobile/4.0/group__CAPI__MEDIA__CAMERA__CAPABILITY__MODULE.html#gaccca0251a0432ca8752be09b400b9b3b)
locks the calling thread and invokes the given callback in a another thread.
The callbacks are blocking as they need to return a `bool`.
Because of that we need TizenInteropCallbacks and we need to call the API
function in a different Isolate. That Isolate will be blocked while our main
Isolate is processing the callbacks.

TizenInteropCallbacks is only accessed in the main Isolate and
the RegisteredCallback is passed to the spawned Isolate.

Our Dart callback runs in the main Isolate, so we have full and safe access
to all of the objects.