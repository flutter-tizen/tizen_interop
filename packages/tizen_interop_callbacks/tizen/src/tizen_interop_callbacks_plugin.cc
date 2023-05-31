// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "tizen_interop_callbacks_plugin.h"

#include <flutter/plugin_registrar.h>

#include <map>
#include <memory>
#include <string>

#include "log.h"
#include "macros.h"

// Maps unique callback registration ID to registered user callback.
std::map<uint32_t, CallbackPointer> callback_pointers;

// The thread where the plugin was initialized with
// TizenInteropCallbacksRegisterSendPort(). The callbacks provided by the user
// will be executed in it.
unsigned long interop_callbacks_thread_id = 0;

namespace {

// The port to communicate with isolate that initialized TizenInteropCallbacks.
Dart_Port send_port = 0;

uint32_t last_used_callback_id = 99;

class TizenInteropCallbacksPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrar *registrar) {
    auto plugin = std::make_unique<TizenInteropCallbacksPlugin>();
    registrar->AddPlugin(std::move(plugin));
  }

  TizenInteropCallbacksPlugin() {}

  virtual ~TizenInteropCallbacksPlugin() {}
};

}  // namespace

void TizenInteropCallbacksPluginRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  TizenInteropCallbacksPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrar>(registrar));
}

#include "generated_callbacks.cc"

void RequestCallbackCall(CallbackWrapper *wrapper) {
  LDEBUG("in RequestCallbackCall(), wrapper: %p", wrapper);

  Dart_CObject wrapper_cobj;
  wrapper_cobj.type = Dart_CObject_kInt64;
  wrapper_cobj.value.as_int64 = reinterpret_cast<intptr_t>(wrapper);

  bool posted = Dart_PostCObject_DL(send_port, &wrapper_cobj);
  if (!posted) {
    LOG_ERROR("Dart_PostCObject_DL(): message %p not posted.", wrapper);
    delete wrapper;
  }
  LDEBUG("after calling Dart_PostCObject_DL()");
}

intptr_t TizenInteropCallbacksInitDartApi(void *data) {
  auto error = Dart_InitializeApiDL(data);
  if (error) {
    LOG_ERROR("Dart_InitializeApiDL() failed.");
  }
  return error;
}

// Stores the SendPort ID created in Dart for communication. Returns non-zero if
// called twice.
int32_t TizenInteropCallbacksRegisterSendPort(Dart_Port port) {
  if (send_port) {
    if (interop_callbacks_thread_id != gettid()) {
      LOG_ERROR(
          "Attempted TizenInteropCallbacks initialization from another "
          "thread.");
      return 1;
    } else {
      LOG_WARN(
          "Attempted TizenInteropCallbacks initialization again - resetting.");
      send_port = port;
      callback_pointers.clear();
      return 2;
    }
  }
  send_port = port;
  interop_callbacks_thread_id = gettid();
  return 0;
}

// Finds an ID not existing in callback_pointers. Returns 0 on failure.
uint32_t FindFreeCallbackId() {
  uint32_t callback_id = ++last_used_callback_id;
  auto iter = callback_pointers.find(callback_id);
  if (!callback_id || iter != callback_pointers.end()) {
    // in an unusual case of wrapping or taken id, loop over used ones
    if (!callback_id) {
      iter = callback_pointers.find(++callback_id);
    }
    while (iter != callback_pointers.end() && iter->first == callback_id) {
      ++iter;
      ++callback_id;
    }
    last_used_callback_id = callback_id;
  }
  return callback_id;
}

RegistrationResult TizenInteropCallbacksRegisterWrappedCallback(
    void *user_callback, const char *proxy_name, int32_t proxy_num) {
  if (proxy_num < 0 || proxy_num >= kProxyInstanceCount) {
    LOG_ERROR("proxy_num %d is out of acceptable range.", proxy_num);
    return {nullptr, 0};
  }
  const auto &multi_proxy_iter = multi_proxy_map.find(std::string(proxy_name));
  if (multi_proxy_iter == multi_proxy_map.end()) {
    LOG_ERROR("Wrong proxy_name: %s", proxy_name);
    return {nullptr, 0};
  }

  uint32_t callback_id = FindFreeCallbackId();
  if (!callback_id) {
    LOG_ERROR("Failed to find unused callback ID for %s.", proxy_name);
    return {nullptr, 0};
  }

  LDEBUG("%s id: %d, user_callback: %p", proxy_name, callback_id,
         user_callback);
  callback_pointers[callback_id] = user_callback;

  // We are only expecting proxy_name to be either platform_blocking_{CALLBACK}
  // or platform_non_blocking_{CALLBACK}. Test the 9th character to check which
  // one is it, and depending on that remove the ..._blocking_ prefix which ends
  // at either 22nd (non_blocking variant) or 18th (blocking one) character.
  const auto &base_id_iter = reserved_base_id_map.find(
      std::string(proxy_name + ((proxy_name[9] == 'n') ? 22 : 18)));
  if (base_id_iter != reserved_base_id_map.end()) {
    int base_id = base_id_iter->second;
    LDEBUG("storing remap callback id %s: %d+%d -> %d",
           base_id_iter->first.c_str(), base_id, proxy_num, callback_id);
    reserved_callback_ids[base_id + proxy_num] = callback_id;
  }

  LDEBUG("will use proxy callback %p", multi_proxy_iter->second.mp[proxy_num]);
  return {multi_proxy_iter->second.mp[proxy_num], callback_id};
}

void TizenInteropCallbacksUnregisterWrappedCallback(uint32_t callback_id) {
  const auto &iter = callback_pointers.find(callback_id);
  if (iter != callback_pointers.end()) {
    callback_pointers.erase(callback_id);
  } else {
    LOG_WARN("Callback with id %d not found, ignoring.", callback_id);
  }
}

// Executes the given wrapper. It is called from Dart, so the wrapped code is
// executed in the proper thread.
void TizenInteropCallbacksRunCallback(CallbackWrapper *wrapper_pointer) {
  CallbackWrapper wrapper = *wrapper_pointer;
  LDEBUG("calling wrapper() at %p", wrapper_pointer);
  wrapper();
  LDEBUG("after calling wrapper()");
  delete wrapper_pointer;
}

// Returns true if the given platform callback exists. Used to check if
// non-blocking variant is available.
bool TizenInteropCallbacksProxyExists(const char *name) {
  return multi_proxy_map.count(std::string(name));
}
