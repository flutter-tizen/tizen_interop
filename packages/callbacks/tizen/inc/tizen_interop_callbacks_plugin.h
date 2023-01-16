#ifndef FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_
#define FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_

#include <flutter_plugin_registrar.h>
#include <map>
#include <functional>

#include <dart_api.h>

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

inline Dart_Port send_port;

struct CallbackInfo {
  void *callbackPtr;
  void *actualUserData;
};

typedef std::function<void()> CallbackWrapper;
void RequestCallbackCall(CallbackWrapper *wrapper);

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
  char device_name[WIFI_DIRECT_MAX_DEVICE_NAME_LEN+1];  /**< Null-terminated device friendly name. */
  char mac_address[WIFI_DIRECT_MAC_ADDRESS_LEN+1];      /**< Null-terminated Device's P2P Device Address */
} wifi_direct_connection_state_cb_data_s_copy;

typedef enum {
  SOME_ENUM_0
} some_enum;

typedef void* void_pointer;

#endif  // FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_
