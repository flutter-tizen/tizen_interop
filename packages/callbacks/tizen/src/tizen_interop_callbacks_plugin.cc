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

// maps unique callback registration id to registered user callback
std::map<uint32_t, CallbackInfo> __cb_id_to_info_map;
// The port to communicate with Isolate that initialized TizenInteropCallbacks
Dart_Port send_port = 0;
// Thread the plugin was initialized with
// TizenInteropCallbacksRegisterSendPort(). The callbacks provided by the user
// will be executed in it.
unsigned long interop_callbacks_thread_id = 0;
uint32_t last_used_cb_id = 0;

struct RegistrationResult {
  void *callback;
  uint32_t id;
};

#include "../generated/callbacks.cc"
#include "dart_api_dl.c"

void RequestCallbackCall(CallbackWrapper *wrapper) {
  LDEBUG("in RequestCallbackCall(), wrapper=%p", wrapper);
  intptr_t wrapper_intptr = reinterpret_cast<intptr_t>(wrapper);

  Dart_CObject ptr_obj;
  ptr_obj.type = Dart_CObject_kInt64;
  ptr_obj.value.as_int64 = wrapper_intptr;

  bool posted = Dart_PostCObject_DL(send_port, &ptr_obj);
  if (!posted) {
    LOG_ERROR("Dart_PostCObject_DL(): message %" PRIxPTR " not posted",
              wrapper_intptr);
    delete wrapper;
  }
  LDEBUG("after calling Dart_PostCObject_DL()");
}

extern "C" {

__attribute__((visibility("default"))) DART_EXPORT intptr_t
TizenInteropCallbacksInitDartApiDL(void *data) {
  LDEBUG("in InitDartApiDL()");
  auto error = Dart_InitializeApiDL(data);
  if (error) {
    LOG_ERROR("Dart_InitializeApiDL() failed");
  }
  return error;
}

// Stores the SendPort id created in Dart for communication. Returns non-zero if
// called twice.
__attribute__((visibility("default"))) int32_t
TizenInteropCallbacksRegisterSendPort(Dart_Port port) {
  LDEBUG("in RegisterSendPort() port=%" PRId64, port);
  if (send_port) {
    if (interop_callbacks_thread_id != gettid()) {
      LOG_ERROR(
          "Attempted TizenInteropCallbacks initialization from another "
          "thread.");
      return 1;
    } else {
      LOG_WARN("Attempted TizenInteropCallbacks initialization again.");
      send_port = port;
      return 2;
    }
  }
  send_port = port;
  interop_callbacks_thread_id = gettid();
  return 0;
}

// Finds an ID not existing in __cb_id_to_info_map. Returns 0 on failure.
uint32_t find_free_callback_registration_id() {
  uint32_t cb_id = ++last_used_cb_id;
  std::map<uint32_t, CallbackInfo>::iterator it;
  const auto end = __cb_id_to_info_map.end();
  if (!cb_id || ((it = __cb_id_to_info_map.find(cb_id)) != end)) {
    // in and unusual case of wrapping or taken id, loop over used ones
    if (!cb_id) it = __cb_id_to_info_map.find(++cb_id);
    while (it != end && it->first == cb_id) {
      ++it;
      ++cb_id;
    }
    if (!cb_id) {
      // ended up back with 0? try again from the beginning
      it = __cb_id_to_info_map.find(++cb_id);
      while (it != end && it->first == cb_id) {
        ++it;
        ++cb_id;
      }
      // if cb_id is 0 at that point, nothing can be done
    }
    last_used_cb_id = cb_id;
  }
  return cb_id;
}

__attribute__((visibility("default"))) RegistrationResult
TizenInteropCallbacksRegisterWrappedCallback(void *user_callback,
                                             const char *proxy_name,
                                             int proxy_num) {
  if (proxy_num < 0 || proxy_num >= PROXY_INSTANCES_COUNT) {
    LOG_ERROR("proxy_num=%d outside of acceptable range", proxy_num);
    return RegistrationResult{nullptr, 0};
  }
  const auto &multi_proxy_map_it =
      __multi_proxy_name_to_ptr_map.find(std::string(proxy_name));
  if (multi_proxy_map_it == __multi_proxy_name_to_ptr_map.end()) {
    LOG_ERROR("Wrong proxy_name `%s`", proxy_name);
    return RegistrationResult{nullptr, 0};
  }

  uint32_t cb_id = find_free_callback_registration_id();
  if (!cb_id) {
    LOG_ERROR("Failed to find unused registration id for %s", proxy_name);
    return RegistrationResult{nullptr, 0};
  }

  LDEBUG("%s id:%" PRIu32 ", user_callback=%p", proxy_name, cb_id,
         user_callback);
  __cb_id_to_info_map[cb_id] = CallbackInfo{user_callback};

  // we are only expecting proxy_name to be either platform_blocking_{CALLBACK}
  // or platform_non_blocking_{CALLBACK} test the 9th character to check which
  // one is it, and depending on that remove the ..._blocking_ prefix which ends
  // at either 22nd (non_blocking variant) or 18th (blocking one) character.
  const auto &base_id_map_it = __reserved_base_id_map.find(
      std::string(proxy_name + ((proxy_name[9] == 'n') ? 22 : 18)));
  if (base_id_map_it != __reserved_base_id_map.end()) {
    LDEBUG("storing remap callback id %s %d+%d -> %" PRIu32,
           base_id_map_it->first.c_str(), base_id_map_it->second, proxy_num,
           cb_id);
    __reserved_cb_id_array[base_id_map_it->second + proxy_num] = cb_id;
  }

  LDEBUG("will use proxy callback %p",
         multi_proxy_map_it->second.mp[proxy_num]);
  return RegistrationResult{multi_proxy_map_it->second.mp[proxy_num], cb_id};
}

__attribute__((visibility("default"))) void
TizenInteropCallbacksUnregisterWrappedCallback(uint32_t cb_id) {
  LDEBUG("in UnregisterWrappedCallbackInNativeLayer");
  const auto &it = __cb_id_to_info_map.find(cb_id);
  if (it != __cb_id_to_info_map.end()) {
    __cb_id_to_info_map.erase(cb_id);
  } else {
    LOG_WARN("Callback with id %" PRIu32 " not found, ignoring", cb_id);
  }
}

// Executes the given wrapper. It is called from Dart, so the wrapped code is
// executed in the proper thread.
__attribute__((visibility("default"))) void TizenInteropCallbacksRunCallback(
    CallbackWrapper *wrapper_pointer) {
  CallbackWrapper wrapper = *wrapper_pointer;
  LDEBUG("calling wrapper() at %p", wrapper_pointer);
  wrapper();
  LDEBUG("after calling wrapper()");
  delete wrapper_pointer;
}

// Returns true if the given platform callback exists. Used to check if
// non-blocking variant is available.
__attribute__((visibility("default"))) bool TizenInteropCallbacksProxyExists(
    char *name) {
  bool exists = __multi_proxy_name_to_ptr_map.count(name);
  LDEBUG("checking if proxy %s exists: %d", name, exists);
  free(name);
  return exists;
}

// Exposes the value as symbol in so to Dart, ensuring it's same everywhere.
__attribute__((visibility("default")))
int32_t TizenInteropCallbacksProxyInstancesCount = PROXY_INSTANCES_COUNT;

}  // extern "C"
