#include "tizen_interop_callbacks_plugin.h"

#include <flutter/plugin_registrar.h>
#include <../../../../../dart-sdk/include/dart_native_api.h>
#include <../../../../../dart-sdk/include/dart_api_dl.h>

#include <memory>
#include <string>

#include "log.h"

namespace {

class TizenInteropCallbacksPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrar *registrar) {
    auto plugin = std::make_unique<TizenInteropCallbacksPlugin>();
    registrar->AddPlugin(std::move(plugin));
  }

  TizenInteropCallbacksPlugin() {}

  virtual ~TizenInteropCallbacksPlugin() {}

 private:
};

}  // namespace

void TizenInteropCallbacksPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  TizenInteropCallbacksPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrar>(registrar));
}

std::map<int, CallbackInfo> __cb_id_to_info_map;

#include "dart_api_dl.c"
#undef TIZEN_DEPRECATION
#undef DEPRECATION_WARNING 
#include "../generated/callbacks_6.5.cc"

void RequestCallbackCall(CallbackWrapper *wrapper) {
  LOG_DEBUG("in RequestCallbackCall()");
  intptr_t wrapper_intptr = reinterpret_cast<intptr_t>(wrapper);

  Dart_CObject ptr_obj;
  ptr_obj.type = Dart_CObject_kInt64;
  ptr_obj.value.as_int64 = wrapper_intptr;

  bool posted = Dart_PostCObject_DL(send_port, &ptr_obj);
  if (!posted) {
    LOG_ERROR("Dart_PostCObject_DL(): message %d not posted", wrapper_intptr);
  }
  LOG_DEBUG("after calling Dart_PostCObject_DL()");
}

extern "C" {

__attribute__((visibility("default")))
DART_EXPORT intptr_t InitDartApiDL(void *data) {
  LOG_DEBUG("in InitDartApiDL()");
  auto error = Dart_InitializeApiDL(data);
  if (error) {
    LOG_ERROR("Dart_InitializeApiDL() failed");
  }
  return error;
}

__attribute__((visibility("default")))
void RegisterSendPort(Dart_Port port) {
  LOG_DEBUG("in RegisterSendPort()  port=%" PRId64, port);
  send_port = port;
}

__attribute__((visibility("default")))
void *RegisterWrappedCallbackInNativeLayer(int cb_id, void *cb_ptr, void *actual_user_data,
    const char *multi_proxy_name) {
  LOG_DEBUG("in RegisterWrappedCallbackInNativeLayer");
  __cb_id_to_info_map[cb_id] = CallbackInfo{cb_ptr, actual_user_data};
  return __multi_proxy_name_to_ptr_map[std::string(multi_proxy_name)];
}

__attribute__((visibility("default")))
void UnregisterWrappedCallbackInNativeLayer(int cb_id) {
  LOG_DEBUG("in UnregisterWrappedCallbackInNativeLayer");
  auto it = __cb_id_to_info_map.find(cb_id);
  if (it != __cb_id_to_info_map.end()) {
    __cb_id_to_info_map.erase(cb_id);
  } else {
    LOG_DEBUG("callback with id %d not found", cb_id);
  }
}

__attribute__((visibility("default")))
void RunCallbackInNativeLayer(CallbackWrapper *wrapper_ptr) {
  LOG_DEBUG("in RunCallbackInNativeLayer()");
  CallbackWrapper wrapper = *wrapper_ptr;
  LOG_DEBUG("calling wrapper()");
  wrapper();
  LOG_DEBUG("after calling wrapper()");
  delete wrapper_ptr;
}

} // extern "C"
