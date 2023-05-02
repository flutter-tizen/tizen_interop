#ifndef FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_
#define FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_

#include <dart_api_dl.h>
#include <flutter_plugin_registrar.h>

#include <cstdint>
#include <functional>

#ifdef FLUTTER_PLUGIN_IMPL
#define FLUTTER_PLUGIN_EXPORT __attribute__((visibility("default")))
#else
#define FLUTTER_PLUGIN_EXPORT
#endif

struct RegistrationResult {
  void *callback;
  uint32_t id;
};

// Used to hold lambda capturing callback info and parameters.
typedef std::function<void()> CallbackWrapper;

#if defined(__cplusplus)
extern "C" {
#endif

FLUTTER_PLUGIN_EXPORT void TizenInteropCallbacksPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar);

FLUTTER_PLUGIN_EXPORT intptr_t TizenInteropCallbacksInitDartApiDL(void *data);

FLUTTER_PLUGIN_EXPORT int32_t
TizenInteropCallbacksRegisterSendPort(Dart_Port port);

FLUTTER_PLUGIN_EXPORT RegistrationResult
TizenInteropCallbacksRegisterWrappedCallback(void *user_callback,
                                             const char *proxy_name,
                                             int proxy_num);

FLUTTER_PLUGIN_EXPORT void TizenInteropCallbacksUnregisterWrappedCallback(
    uint32_t cb_id);

FLUTTER_PLUGIN_EXPORT void TizenInteropCallbacksRunCallback(
    CallbackWrapper *wrapper_pointer);

FLUTTER_PLUGIN_EXPORT bool TizenInteropCallbacksProxyExists(char *name);

#if defined(__cplusplus)
}  // extern "C"
#endif

#endif  // FLUTTER_PLUGIN_TIZEN_INTEROP_CALLBACKS_PLUGIN_H_
