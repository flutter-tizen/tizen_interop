// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TIZEN_INTEROP_CALLBACKS_MACROS_H_
#define TIZEN_INTEROP_CALLBACKS_MACROS_H_

#include <sys/syscall.h>
#include <unistd.h>

#include <condition_variable>
#include <cstdint>
#include <map>
#include <mutex>

#include "log.h"

static constexpr int32_t kProxyInstanceCount = 5;

// The function pointer given to TizenInteropCallbacksRegisterWrappedCallback.
// Should be a pointer created in Dart with Pointer.fromFunction().
typedef void *CallbackPointer;

// Sends the given wrapped callback to Dart to be called from there.
void RequestCallbackCall(CallbackWrapper *wrapper);

// Maps unique callback registration ID to registered user callback.
extern std::map<uint32_t, CallbackPointer> callback_pointers;

// The thread the plugin was initialized with
// TizenInteropCallbacksRegisterSendPort(). The callbacks provided by the user
// will be executed in it.
extern unsigned long interop_callbacks_thread_id;

#define gettid() syscall(SYS_gettid)

#define GET_CALLBACK_ID(CB_NAME, OFFSET) \
  reserved_callback_ids[BASE_CALLBACK_ID_##CB_NAME + OFFSET]

// Note: CB_PARAMS_NAMES should be defined before calling PROXY_GROUP_*.
#define PROXY_GROUP_RETURN(CB_NAME, CB_RETURN, CB_PARAMS...)                   \
  CB_RETURN platform_blocking_##CB_NAME(CB_PARAMS) {                           \
    if (!user_data || reinterpret_cast<uintptr_t>(user_data) > UINT32_MAX) {   \
      LOG_ERROR("Received bad user_data in %s: %p - ignoring.", #CB_NAME,      \
                user_data);                                                    \
      return CB_RETURN();                                                      \
    }                                                                          \
    uint32_t _callback_id =                                                    \
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(user_data));         \
    LDEBUG("enter <RETURN> id: %d", _callback_id);                             \
    auto _iter = callback_pointers.find(_callback_id);                         \
    if (_iter == callback_pointers.end()) {                                    \
      LOG_ERROR("No callback registered for id %d - ignoring.", _callback_id); \
      return CB_RETURN();                                                      \
    }                                                                          \
    CallbackPointer _callback = _iter->second;                                 \
    if (gettid() == interop_callbacks_thread_id) {                             \
      LDEBUG("calling Dart callback directly");                                \
      return (reinterpret_cast<CB_NAME>(_callback))(CB_PARAMS_NAMES);          \
    }                                                                          \
    CB_RETURN _return_value = CB_RETURN();                                     \
    std::mutex _mutex;                                                         \
    std::unique_lock<std::mutex> lock(_mutex);                                 \
    std::condition_variable _cv;                                               \
    bool _callback_finished = false;                                           \
                                                                               \
    CallbackWrapper _wrapper = [_callback, CB_PARAMS_NAMES, &_cv,              \
                                &_callback_finished, &_return_value] {         \
      CB_NAME local_callback = reinterpret_cast<CB_NAME>(_callback);           \
      LDEBUG("calling local_callback() %p, user_data: %p", local_callback,     \
             user_data);                                                       \
      if (local_callback) {                                                    \
        _return_value = local_callback(CB_PARAMS_NAMES);                       \
      }                                                                        \
      _callback_finished = true;                                               \
      LDEBUG("calling notify_one()");                                          \
      _cv.notify_one();                                                        \
    };                                                                         \
                                                                               \
    LDEBUG("calling RequestCallbackCall()");                                   \
    RequestCallbackCall(new CallbackWrapper(_wrapper));                        \
                                                                               \
    LDEBUG("waiting for notification");                                        \
    while (!_callback_finished) {                                              \
      _cv.wait(lock);                                                          \
    }                                                                          \
    LDEBUG("exit, return_value: %d", (int)_return_value);                      \
    return _return_value;                                                      \
  }                                                                            \
                                                                               \
  CB_RETURN platform_blocking_##CB_NAME##_0(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_1(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_2(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_3(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_4(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                       \
  }
// end of PROXY_GROUP_RETURN

#define PROXY_GROUP_BLOCKING(CB_NAME, CB_PARAMS...)                            \
  void platform_blocking_##CB_NAME(CB_PARAMS) {                                \
    if (!user_data || reinterpret_cast<uintptr_t>(user_data) > UINT32_MAX) {   \
      LOG_ERROR("Received bad user_data in %s: %p - ignoring.", #CB_NAME,      \
                user_data);                                                    \
      return;                                                                  \
    }                                                                          \
    uint32_t _callback_id =                                                    \
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(user_data));         \
    LDEBUG("enter <BLOCKING> id: %d", _callback_id);                           \
    auto _iter = callback_pointers.find(_callback_id);                         \
    if (_iter == callback_pointers.end()) {                                    \
      LOG_ERROR("No callback registered for id %d - ignoring.", _callback_id); \
      return;                                                                  \
    }                                                                          \
    CallbackPointer _callback = _iter->second;                                 \
    if (gettid() == interop_callbacks_thread_id) {                             \
      LDEBUG("calling Dart callback directly");                                \
      return (reinterpret_cast<CB_NAME>(_callback))(CB_PARAMS_NAMES);          \
    }                                                                          \
    std::mutex _mutex;                                                         \
    std::unique_lock<std::mutex> lock(_mutex);                                 \
    std::condition_variable _cv;                                               \
    bool _callback_finished = false;                                           \
                                                                               \
    CallbackWrapper _wrapper = [_callback, CB_PARAMS_NAMES, &_cv,              \
                                &_callback_finished] {                         \
      CB_NAME local_callback = reinterpret_cast<CB_NAME>(_callback);           \
      LDEBUG("calling local_callback() %p, user_data: %p", local_callback,     \
             user_data);                                                       \
      if (local_callback) {                                                    \
        local_callback(CB_PARAMS_NAMES);                                       \
      }                                                                        \
      _callback_finished = true;                                               \
      LDEBUG("calling notify_one()");                                          \
      _cv.notify_one();                                                        \
    };                                                                         \
                                                                               \
    LDEBUG("calling RequestCallbackCall()");                                   \
    RequestCallbackCall(new CallbackWrapper(_wrapper));                        \
                                                                               \
    LDEBUG("waiting for notification");                                        \
    while (!_callback_finished) {                                              \
      _cv.wait(lock);                                                          \
    }                                                                          \
    LDEBUG("exit");                                                            \
  }                                                                            \
                                                                               \
  void platform_blocking_##CB_NAME##_0(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                              \
  }                                                                            \
  void platform_blocking_##CB_NAME##_1(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                              \
  }                                                                            \
  void platform_blocking_##CB_NAME##_2(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                              \
  }                                                                            \
  void platform_blocking_##CB_NAME##_3(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                              \
  }                                                                            \
  void platform_blocking_##CB_NAME##_4(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(CB_PARAMS_NAMES);                              \
  }
// end of PROXY_GROUP_BLOCKING

#define PROXY_GROUP_NON_BLOCKING(CB_NAME, CB_PARAMS...)                        \
  void platform_non_blocking_##CB_NAME(CB_PARAMS) {                            \
    if (!user_data || reinterpret_cast<uintptr_t>(user_data) > UINT32_MAX) {   \
      LOG_ERROR("Received bad user_data in %s: %p - ignoring.", #CB_NAME,      \
                user_data);                                                    \
      return;                                                                  \
    }                                                                          \
    uint32_t _callback_id =                                                    \
        static_cast<uint32_t>(reinterpret_cast<uintptr_t>(user_data));         \
    LDEBUG("enter <NON_BLOCKING> id: %d", _callback_id);                       \
    auto _iter = callback_pointers.find(_callback_id);                         \
    if (_iter == callback_pointers.end()) {                                    \
      LOG_ERROR("No callback registered for id %d - ignoring.", _callback_id); \
      return;                                                                  \
    }                                                                          \
    CallbackPointer _callback = _iter->second;                                 \
                                                                               \
    CallbackWrapper _wrapper = [_callback, CB_PARAMS_NAMES] {                  \
      CB_NAME local_callback = reinterpret_cast<CB_NAME>(_callback);           \
      LDEBUG("calling local_callback() %p, user_data: %p", local_callback,     \
             user_data);                                                       \
      if (local_callback) {                                                    \
        local_callback(CB_PARAMS_NAMES);                                       \
      }                                                                        \
    };                                                                         \
                                                                               \
    LDEBUG("calling RequestCallbackCall()");                                   \
    RequestCallbackCall(new CallbackWrapper(_wrapper));                        \
  }                                                                            \
                                                                               \
  void platform_non_blocking_##CB_NAME##_0(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_1(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_2(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_3(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_4(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(CB_PARAMS_NAMES);                          \
  }
// end of PROXY_GROUP_NON_BLOCKING

#define PROXY_GROUP_RETURN_NO_USER_DATA(CB_NAME, CB_RETURN, CB_PARAMS...)      \
  CB_RETURN platform_blocking_##CB_NAME(uint32_t _callback_id, CB_PARAMS) {    \
    LDEBUG("enter <RETURN_NO_USER_DATA> id: %d", _callback_id);                \
    auto _iter = callback_pointers.find(_callback_id);                         \
    if (_iter == callback_pointers.end()) {                                    \
      LOG_ERROR("No callback registered for id %d - ignoring.", _callback_id); \
      return CB_RETURN();                                                      \
    }                                                                          \
    CallbackPointer _callback = _iter->second;                                 \
    if (gettid() == interop_callbacks_thread_id) {                             \
      LDEBUG("calling Dart callback directly");                                \
      return (reinterpret_cast<CB_NAME>(_callback))(CB_PARAMS_NAMES);          \
    }                                                                          \
    CB_RETURN _return_value = CB_RETURN();                                     \
    std::mutex _mutex;                                                         \
    std::unique_lock<std::mutex> lock(_mutex);                                 \
    std::condition_variable _cv;                                               \
    bool _callback_finished = false;                                           \
                                                                               \
    CallbackWrapper _wrapper = [_callback, CB_PARAMS_NAMES, &_cv,              \
                                &_callback_finished, &_return_value] {         \
      CB_NAME local_callback = reinterpret_cast<CB_NAME>(_callback);           \
      LDEBUG("calling local_callback() %p", local_callback);                   \
      if (local_callback) {                                                    \
        _return_value = local_callback(CB_PARAMS_NAMES);                       \
      }                                                                        \
      _callback_finished = true;                                               \
      LDEBUG("calling notify_one()");                                          \
      _cv.notify_one();                                                        \
    };                                                                         \
                                                                               \
    LDEBUG("calling RequestCallbackCall()");                                   \
    RequestCallbackCall(new CallbackWrapper(_wrapper));                        \
                                                                               \
    LDEBUG("waiting for notification");                                        \
    while (!_callback_finished) {                                              \
      _cv.wait(lock);                                                          \
    }                                                                          \
    LDEBUG("exit, return_value: %d", (int)_return_value);                      \
    return _return_value;                                                      \
  }                                                                            \
                                                                               \
  CB_RETURN platform_blocking_##CB_NAME##_0(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 0),            \
                                       CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_1(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 1),            \
                                       CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_2(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 2),            \
                                       CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_3(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 3),            \
                                       CB_PARAMS_NAMES);                       \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_4(CB_PARAMS) {                       \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 4),            \
                                       CB_PARAMS_NAMES);                       \
  }
// end of PROXY_GROUP_RETURN_NO_USER_DATA

#define PROXY_GROUP_BLOCKING_NO_USER_DATA(CB_NAME, CB_PARAMS...)               \
  void platform_blocking_##CB_NAME(uint32_t _callback_id, CB_PARAMS) {         \
    LDEBUG("enter <BLOCKING_NO_USER_DATA> id: %d", _callback_id);              \
    auto _iter = callback_pointers.find(_callback_id);                         \
    if (_iter == callback_pointers.end()) {                                    \
      LOG_ERROR("No callback registered for id %d - ignoring.", _callback_id); \
      return;                                                                  \
    }                                                                          \
    CallbackPointer _callback = _iter->second;                                 \
    if (gettid() == interop_callbacks_thread_id) {                             \
      LDEBUG("calling Dart callback directly");                                \
      return (reinterpret_cast<CB_NAME>(_callback))(CB_PARAMS_NAMES);          \
    }                                                                          \
    std::mutex _mutex;                                                         \
    std::unique_lock<std::mutex> lock(_mutex);                                 \
    std::condition_variable _cv;                                               \
    bool _callback_finished = false;                                           \
                                                                               \
    CallbackWrapper _wrapper = [_callback, CB_PARAMS_NAMES, &_cv,              \
                                &_callback_finished] {                         \
      CB_NAME local_callback = reinterpret_cast<CB_NAME>(_callback);           \
      LDEBUG("calling local_callback() %p", local_callback);                   \
      if (local_callback) {                                                    \
        local_callback(CB_PARAMS_NAMES);                                       \
      }                                                                        \
      _callback_finished = true;                                               \
      LDEBUG("calling notify_one()");                                          \
      _cv.notify_one();                                                        \
    };                                                                         \
                                                                               \
    LDEBUG("calling RequestCallbackCall()");                                   \
    RequestCallbackCall(new CallbackWrapper(_wrapper));                        \
                                                                               \
    LDEBUG("waiting for notification");                                        \
    while (!_callback_finished) {                                              \
      _cv.wait(lock);                                                          \
    }                                                                          \
    LDEBUG("exit");                                                            \
  }                                                                            \
                                                                               \
  void platform_blocking_##CB_NAME##_0(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 0), CB_PARAMS_NAMES); \
  }                                                                            \
  void platform_blocking_##CB_NAME##_1(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 1), CB_PARAMS_NAMES); \
  }                                                                            \
  void platform_blocking_##CB_NAME##_2(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 2), CB_PARAMS_NAMES); \
  }                                                                            \
  void platform_blocking_##CB_NAME##_3(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 3), CB_PARAMS_NAMES); \
  }                                                                            \
  void platform_blocking_##CB_NAME##_4(CB_PARAMS) {                            \
    platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 4), CB_PARAMS_NAMES); \
  }
// end of PROXY_GROUP_BLOCKING_NO_USER_DATA

#define PROXY_GROUP_NON_BLOCKING_NO_USER_DATA(CB_NAME, CB_PARAMS...)           \
  void platform_non_blocking_##CB_NAME(uint32_t _callback_id, CB_PARAMS) {     \
    LDEBUG("enter <NON_BLOCKING_NO_USER_DATA> id: %d", _callback_id);          \
    auto _iter = callback_pointers.find(_callback_id);                         \
    if (_iter == callback_pointers.end()) {                                    \
      LOG_ERROR("No callback registered for id %d - ignoring.", _callback_id); \
      return;                                                                  \
    }                                                                          \
    CallbackPointer _callback = _iter->second;                                 \
                                                                               \
    CallbackWrapper _wrapper = [_callback, CB_PARAMS_NAMES] {                  \
      CB_NAME local_callback = reinterpret_cast<CB_NAME>(_callback);           \
      LDEBUG("calling local_callback() %p", local_callback);                   \
      if (local_callback) {                                                    \
        local_callback(CB_PARAMS_NAMES);                                       \
      }                                                                        \
    };                                                                         \
                                                                               \
    LDEBUG("calling RequestCallbackCall()");                                   \
    RequestCallbackCall(new CallbackWrapper(_wrapper));                        \
  }                                                                            \
                                                                               \
  void platform_non_blocking_##CB_NAME##_0(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 0),               \
                                    CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_1(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 1),               \
                                    CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_2(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 2),               \
                                    CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_3(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 3),               \
                                    CB_PARAMS_NAMES);                          \
  }                                                                            \
  void platform_non_blocking_##CB_NAME##_4(CB_PARAMS) {                        \
    platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 4),               \
                                    CB_PARAMS_NAMES);                          \
  }
// end of PROXY_GROUP_NON_BLOCKING_NO_USER_DATA

#define PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(CB_NAME, CB_RETURN)           \
  CB_RETURN platform_blocking_##CB_NAME(uint32_t _callback_id) {               \
    LDEBUG("enter <RETURN_NO_USER_DATA_NO_PARAM> id: %d", _callback_id);       \
    auto _iter = callback_pointers.find(_callback_id);                         \
    if (_iter == callback_pointers.end()) {                                    \
      LOG_ERROR("No callback registered for id %d - ignoring.", _callback_id); \
      return CB_RETURN();                                                      \
    }                                                                          \
    CallbackPointer _callback = _iter->second;                                 \
    if (gettid() == interop_callbacks_thread_id) {                             \
      LDEBUG("calling Dart callback directly");                                \
      return (reinterpret_cast<CB_NAME>(_callback))();                         \
    }                                                                          \
    CB_RETURN _return_value = CB_RETURN();                                     \
    std::mutex _mutex;                                                         \
    std::unique_lock<std::mutex> lock(_mutex);                                 \
    std::condition_variable _cv;                                               \
    bool _callback_finished = false;                                           \
                                                                               \
    CallbackWrapper _wrapper = [_callback, &_cv, &_callback_finished,          \
                                &_return_value] {                              \
      CB_NAME local_callback = reinterpret_cast<CB_NAME>(_callback);           \
      LDEBUG("calling local_callback() %p", local_callback);                   \
      if (local_callback) _return_value = local_callback();                    \
      _callback_finished = true;                                               \
      LDEBUG("calling notify_one()");                                          \
      _cv.notify_one();                                                        \
    };                                                                         \
                                                                               \
    LDEBUG("calling RequestCallbackCall()");                                   \
    RequestCallbackCall(new CallbackWrapper(_wrapper));                        \
                                                                               \
    LDEBUG("waiting for notification");                                        \
    while (!_callback_finished) {                                              \
      _cv.wait(lock);                                                          \
    }                                                                          \
    LDEBUG("exit, return_value: %d", (int)_return_value);                      \
    return _return_value;                                                      \
  }                                                                            \
                                                                               \
  CB_RETURN platform_blocking_##CB_NAME##_0() {                                \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 0));           \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_1() {                                \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 1));           \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_2() {                                \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 2));           \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_3() {                                \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 3));           \
  }                                                                            \
  CB_RETURN platform_blocking_##CB_NAME##_4() {                                \
    return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME, 4));           \
  }
// end of PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM

// CB_NAME does not contain indices.
#define MULTI_PROXY_MAP_ENTRY(CB_NAME)        \
  {std::string(#CB_NAME),                     \
   {{                                         \
       reinterpret_cast<void *>(CB_NAME##_0), \
       reinterpret_cast<void *>(CB_NAME##_1), \
       reinterpret_cast<void *>(CB_NAME##_2), \
       reinterpret_cast<void *>(CB_NAME##_3), \
       reinterpret_cast<void *>(CB_NAME##_4), \
   }}},

typedef void *MultiProxyFunctions[kProxyInstanceCount];

struct MultiProxyFunctionsContainer {
  MultiProxyFunctions mp;
};

#endif  // TIZEN_INTEROP_CALLBACKS_MACROS_H_
