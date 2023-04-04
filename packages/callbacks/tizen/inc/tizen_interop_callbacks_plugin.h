#ifndef FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_
#define FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_

#include <dart_api.h>
#include <flutter_plugin_registrar.h>

#include <functional>
#include <map>

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

#if defined(__cplusplus)
extern "C" {
#endif

FLUTTER_PLUGIN_EXPORT void TizenInteropCallbacksPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar);

#if defined(__cplusplus)
}  // extern "C"
#endif

// Information needed to call the callback registered by the user.
struct CallbackInfo {
  // The function pointer given to TizenInteropCallbacksRegisterWrappedCallback, should be a pointer created in Dart with ffi.Pointer.fromFunction()
  void *callback_ptr;
};

// Used to hold lamda capturing callback info and parameters.
typedef std::function<void()> CallbackWrapper;
/// Sends the given wrapped callback to Dart to be called from there.
void RequestCallbackCall(CallbackWrapper *wrapper);

// A few structures copied from Tizen Native API headers, as we need whole
// definion if it is used in callback signature directly and not as pointer.
typedef struct {
  double latitude;
  double longitude;
} location_coords_s_copy;

typedef struct {
  int x;
  int y;
} mv_point_s_copy;

typedef struct {
  mv_point_s_copy point;
  int width;
  int height;
} mv_rectangle_s_copy;

#define WIFI_DIRECT_MAX_DEVICE_NAME_LEN 32
#define WIFI_DIRECT_MAC_ADDRESS_LEN 18
typedef struct {
  char device_name[WIFI_DIRECT_MAX_DEVICE_NAME_LEN +
                   1]; /**< Null-terminated device friendly name. */
  char mac_address[WIFI_DIRECT_MAC_ADDRESS_LEN +
                   1]; /**< Null-terminated Device's P2P Device Address */
} wifi_direct_connection_state_cb_data_s_copy;

typedef enum { SOME_ENUM_0 } some_enum;

typedef void *void_pointer;

#endif  // FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_
