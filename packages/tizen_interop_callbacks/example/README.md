# tizen_interop_callbacks_example

Demonstrates how to use the tizen_interop_callbacks plugin.

## Introduction

This application consists of 2 tabs showing:

### Battery status

Here, a typical scenario is shown. We need to receive callbacks, but the Tizen Native API
invokes the callback from another thread. Trying to pass a function pointer obtained
by [`Pointer.fromFunction()`](https://api.flutter.dev/flutter/dart-ffi/Pointer/fromFunction.html)
to [`device_add_callback()`](https://docs.tizen.org/application/native/api/mobile/5.5/group__CAPI__SYSTEM__DEVICE__CALLBACK__MODULE.html#ga89a756a9c46fb670f603d79b66af6cf0)
will cause an error when the callback is called.
Therefore, `TizenInteropCallbacks` is used to obtain a native proxy callback that can be run in any thread.

You can run the example on a Tizen emulator and use the Control Panel to simulate
changes to the battery level and status.

### Camera preview resolutions

Here, a workaround for a locking issue is presented. Usually, a foreach API function would call the callback synchronously.
Thus, `TizenInteropCallbacks` would not be needed at all.

However, [`camera_foreach_supported_preview_resolution()`](https://docs.tizen.org/application/native/api/mobile/5.5/group__CAPI__MEDIA__CAMERA__CAPABILITY__MODULE.html#gaccca0251a0432ca8752be09b400b9b3b)
locks the calling thread and invokes the given callback in another thread.
Therefore, we need to use `TizenInteropCallbacks` and call the API in a different isolate.
This isolate will be blocked while our root isolate is processing the callbacks.

Notice that `TizenInteropCallbacks` is only accessed in the root isolate and
the `RegisteredCallback` is passed to the spawned isolate.
Our Dart callback runs in the root isolate, so we have full and safe access
to all its objects.
