#ifndef FLUTTER_PLUGIN_ASYNC_CALLBACKS_PLUGIN_H_
#define FLUTTER_PLUGIN_ASYNC_CALLBACKS_PLUGIN_H_

#include <functional>
#include <map>

#include <flutter_plugin_registrar.h>

#include "device.h"
#include "camera.h"

#include "log.h"

#include <../../../../../dart-sdk/include/dart_api.h>
#include <../../../../../dart-sdk/include/dart_native_api.h>
#include <../../../../../dart-sdk/include/dart_api_dl.h>

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

inline Dart_Port send_port;

struct CallbackInfo {
  void *callbackPtr;
  void *actualUserData;
};

inline std::map<int, CallbackInfo> __cb_id_to_info_map;

// CB_NAME does not contain indices
#define MULTI_PROXY_MAP_ENTRY(CB_NAME) \
  { std::string(#CB_NAME "_0"), \
    reinterpret_cast<void*>(CB_NAME ## _0) }, \
  { std::string(#CB_NAME "_1"), \
    reinterpret_cast<void*>(CB_NAME ## _1) }, \
  { std::string(#CB_NAME "_2"), \
    reinterpret_cast<void*>(CB_NAME ## _2) }, \
  { std::string(#CB_NAME "_3"), \
    reinterpret_cast<void*>(CB_NAME ## _3) }, \
  { std::string(#CB_NAME "_4"), \
    reinterpret_cast<void*>(CB_NAME ## _4) },


inline std::map<std::string, void*> __multi_proxy_name_to_ptr_map = {
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_preview_resolution_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_camera_supported_capture_resolution_cb)
  MULTI_PROXY_MAP_ENTRY(platform_blocking_device_changed_cb)
  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_device_changed_cb)
};

typedef std::function<void()> CallbackWrapper;
void RequestCallbackCall(CallbackWrapper *wrapper);

#if defined(__cplusplus)
extern "C" {
#endif

FLUTTER_PLUGIN_EXPORT void AsyncCallbacksPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar);


#if defined(__cplusplus)
}  // extern "C"
#endif

#endif  // FLUTTER_PLUGIN_ASYNC_CALLBACKS_PLUGIN_H_
