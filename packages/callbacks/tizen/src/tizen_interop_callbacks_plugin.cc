#include "tizen_interop_callbacks_plugin.h"

#include <dart_api_dl.h>
#include <dart_native_api.h>
#include <flutter/plugin_registrar.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <memory>
#include <string>

#include "log.h"
#define gettid() syscall(SYS_gettid)

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
Dart_Port send_port = 0;
unsigned long main_thread_id = 0;
unsigned int last_used_cb_id = 0;

struct RegistrationResult {
  void *callback;
  unsigned int id;
};

#include "../generated/callbacks.cc"
#include "dart_api_dl.c"

void RequestCallbackCall(CallbackWrapper *wrapper) {
  LOG_DEBUG_DETAIL("in RequestCallbackCall(), wrapper=%p", wrapper);
  intptr_t wrapper_intptr = reinterpret_cast<intptr_t>(wrapper);

  Dart_CObject ptr_obj;
  ptr_obj.type = Dart_CObject_kInt64;
  ptr_obj.value.as_int64 = wrapper_intptr;

  bool posted = Dart_PostCObject_DL(send_port, &ptr_obj);
  if (!posted) {
    LOG_ERROR("Dart_PostCObject_DL(): message %d not posted", wrapper_intptr);
  }
  LOG_DEBUG_DETAIL("after calling Dart_PostCObject_DL()");
}

extern "C" {

__attribute__((visibility("default"))) DART_EXPORT intptr_t
TizenInteropCallbacksInitDartApiDL(void *data) {
  LOG_DEBUG_DETAIL("in InitDartApiDL()");
  auto error = Dart_InitializeApiDL(data);
  if (error) {
    LOG_ERROR("Dart_InitializeApiDL() failed");
  }
  return error;
}

__attribute__((visibility("default"))) int32_t
TizenInteropCallbacksRegisterSendPort(Dart_Port port) {
  LOG_DEBUG_DETAIL("in RegisterSendPort() port=%" PRId64, port);
  if (send_port) {
    if (main_thread_id != gettid()) {
      LOG_ERROR(
          "Attempted TizenInteropCallbacks initialization from another "
          "thread.");
      return 1;
    } else {
      LOG_WARN("Attempted TizenInteropCallbacks initialization again.");
      return 2;
    }
  }
  send_port = port;
  main_thread_id = gettid();
  return 0;
}

__attribute__((visibility("default"))) RegistrationResult
TizenInteropCallbacksRegisterWrappedCallback(void *cb_ptr,
                                             bool use_id_for_userdata,
                                             void *actual_user_data,
                                             const char *proxy_name,
                                             int proxy_num) {
  unsigned int cb_id = ++last_used_cb_id;
  LOG_DEBUG_DETAIL("id:%d, cb_ptr=%p", cb_id, cb_ptr);
  if (proxy_num < 0 || proxy_num >= PROXY_INSTANCES_COUNT) {
    LOG_ERROR("proxy_num=%d outside of acceptable range", proxy_num);
    return RegistrationResult{nullptr, 0};
  }
  const auto &ptrit =
      __multi_proxy_name_to_ptr_map.find(std::string(proxy_name));
  if (ptrit == __multi_proxy_name_to_ptr_map.end()) {
    LOG_ERROR("Wrong proxy_name `%s`", proxy_name);
    return RegistrationResult{nullptr, 0};
  }
  if (use_id_for_userdata) {
    actual_user_data = (void *)cb_id;
  }
  __cb_id_to_info_map[cb_id] = CallbackInfo{cb_ptr, actual_user_data};

  // we are only expecting proxy_name to be either platform_blocking_{CALLBACK}
  // or platform_non_blocking_{CALLBACK} test the 9th character to check which
  // one is it, and depending on that remove the ..._blocking_ prefix which ends
  // at either 22nd (non_blocking variant) or 18th (blocking one) character.
  const auto &it = __reserved_base_id_map.find(
      std::string(proxy_name + ((proxy_name[9] == 'n') ? 22 : 18)));
  if (it != __reserved_base_id_map.end()) {
    LOG_DEBUG_DETAIL("storing remap callback id %s %d+%d -> %d",
                     it->first.c_str(), it->second, proxy_num, cb_id);
    __reserved_cb_id_array[it->second + proxy_num] = cb_id;
  }

  LOG_DEBUG_DETAIL(" will use proxy callback %p", ptrit->second.mp[proxy_num]);
  return RegistrationResult{ptrit->second.mp[proxy_num], cb_id};
}

__attribute__((visibility("default"))) void
TizenInteropCallbacksUnregisterWrappedCallback(int cb_id) {
  LOG_DEBUG_DETAIL("in UnregisterWrappedCallbackInNativeLayer");
  const auto &it = __cb_id_to_info_map.find(cb_id);
  if (it != __cb_id_to_info_map.end()) {
    __cb_id_to_info_map.erase(cb_id);
  } else {
    LOG_ERROR("Callback with id %d not found", cb_id);
  }
}

__attribute__((visibility("default"))) void TizenInteropCallbacksRunCallback(
    CallbackWrapper *wrapper_ptr) {
  CallbackWrapper wrapper = *wrapper_ptr;
  LOG_DEBUG_DETAIL("calling wrapper() at %p", wrapper_ptr);
  wrapper();
  LOG_DEBUG_DETAIL("after calling wrapper()");
  delete wrapper_ptr;
}

__attribute__((visibility("default"))) bool TizenInteropCallbacksProxyExists(
    char *name) {
  bool exists = __multi_proxy_name_to_ptr_map.count(name);
  LOG_DEBUG_DETAIL("checking if proxy %s exists: %d", name, exists);
  free(name);
  return exists;
}

__attribute__((visibility("default")))
int32_t TizenInteropCallbacksProxyInstancesCount = PROXY_INSTANCES_COUNT;

}  // extern "C"
