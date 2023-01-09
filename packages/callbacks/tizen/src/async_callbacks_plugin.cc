#include "async_callbacks_plugin.h"

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <system_info.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <string>

#include "log.h"

#include "dart_api_dl.c"


namespace {

class AsyncCallbacksPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrar *registrar) {
    auto channel =
        std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
            registrar->messenger(), "async_callbacks",
            &flutter::StandardMethodCodec::GetInstance());

    auto plugin = std::make_unique<AsyncCallbacksPlugin>();

    channel->SetMethodCallHandler(
        [plugin_pointer = plugin.get()](const auto &call, auto result) {
          plugin_pointer->HandleMethodCall(call, std::move(result));
        });

    registrar->AddPlugin(std::move(plugin));
  }

  AsyncCallbacksPlugin() {}

  virtual ~AsyncCallbacksPlugin() {}

 private:
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {
    const auto &method_name = method_call.method_name();

    // Replace "getPlatformVersion" check with your plugin's method.
    if (method_name == "getPlatformVersion") {
      char *value = nullptr;
      int ret = system_info_get_platform_string(
          "http://tizen.org/feature/platform.version", &value);
      if (ret == SYSTEM_INFO_ERROR_NONE) {
        result->Success(flutter::EncodableValue(std::string(value)));
      } else {
        result->Error(std::to_string(ret), "Failed to get platform version.");
      }
      if (value) {
        free(value);
      }
    } else {
      result->NotImplemented();
    }
  }
};

}  // namespace

void AsyncCallbacksPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  AsyncCallbacksPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrar>(registrar));
}

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
void *RegisterWrappedCallbackInNativeLayer(int cb_id,  void *cb_ptr, void *actual_user_data,
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
