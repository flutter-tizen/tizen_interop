#ifndef _TIZEN_INTEROP_CALLBACKS_MACROS_H_
#define _TIZEN_INTEROP_CALLBACKS_MACROS_H_

#define EXPAND_LIST(...) __VA_ARGS__

#define GET_CALLBACK_ID(CB_NAME, OFFSET) __reserved_cb_id_array[BASE_CALLBACK_ID_##CB_NAME + OFFSET]

#define LDEBUG(...) LOG_DEBUG(__VA_ARGS__)
//#define LDEBUG(...)

// Note: CB_PARAMS_NAMES should be defined before calling PROXY_GROUP_*.

#define PROXY_GROUP_RETURN(CB_NAME, CB_RETURN, CB_PARAMS...) \
CB_RETURN platform_blocking_##CB_NAME(CB_PARAMS) { \
  int callbackId = reinterpret_cast<int>(user_data); \
  LDEBUG("enter <RETURN> id:%d", callbackId); \
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
  user_data = cbInfo.actualUserData; \
  if (gettid() == main_thread_id) { \
    LDEBUG("calling dart callback directly"); \
    return (reinterpret_cast<CB_NAME>(cbInfo.callbackPtr))(EXPAND_LIST(CB_PARAMS_NAMES)); \
  } \
  CB_RETURN dartCallbackRetVal = CB_RETURN(); \
  std::mutex mutex; \
  std::unique_lock<std::mutex> lock(mutex); \
  std::condition_variable cv; \
  bool dartCallbackFinished = false; \
\
  CallbackWrapper wrapper = \
      [&cbInfo, &dartCallbackRetVal, \
       EXPAND_LIST(CB_PARAMS_NAMES), \
       &cv, &dartCallbackFinished] { \
    CB_NAME local_cb_ptr = reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
    LDEBUG("calling local_cb_ptr() %p", local_cb_ptr); \
    dartCallbackRetVal = local_cb_ptr(EXPAND_LIST(CB_PARAMS_NAMES)); \
    dartCallbackFinished = true; \
    LDEBUG("calling notify_one()"); \
    cv.notify_one(); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LDEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
\
  LDEBUG("waiting for notification"); \
  while (!dartCallbackFinished) { \
    cv.wait(lock); \
  } \
  LDEBUG("exit, dartCallbackRetVal: %d", (int)dartCallbackRetVal); \
  return dartCallbackRetVal; \
} \
\
CB_RETURN platform_blocking_##CB_NAME##_0(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_1(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_2(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_3(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_4(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
}
// end of PROXY_GROUP_RETURN

#define PROXY_GROUP_BLOCKING(CB_NAME, CB_PARAMS...) \
void platform_blocking_##CB_NAME(CB_PARAMS) { \
  int callbackId = reinterpret_cast<int>(user_data); \
  LDEBUG("enter <BLOCKING> id:%d", callbackId); \
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
  user_data = cbInfo.actualUserData; \
  if (gettid() == main_thread_id) { \
    LDEBUG("calling dart callback directly"); \
    return (reinterpret_cast<CB_NAME>(cbInfo.callbackPtr))(EXPAND_LIST(CB_PARAMS_NAMES)); \
  } \
  std::mutex mutex; \
  std::unique_lock<std::mutex> lock(mutex); \
  std::condition_variable cv; \
  bool dartCallbackFinished = false; \
\
  CallbackWrapper wrapper = \
      [&cbInfo, EXPAND_LIST(CB_PARAMS_NAMES), &cv, &dartCallbackFinished] { \
    CB_NAME local_cb_ptr = reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
    LDEBUG("calling local_cb_ptr() %p", local_cb_ptr); \
    local_cb_ptr(EXPAND_LIST(CB_PARAMS_NAMES)); \
    dartCallbackFinished = true; \
    LDEBUG("calling notify_one()"); \
    cv.notify_one(); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LDEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
\
  LDEBUG("waiting for notification"); \
  while (!dartCallbackFinished) { \
    cv.wait(lock); \
  } \
  LDEBUG("exit"); \
} \
\
void platform_blocking_##CB_NAME##_0(CB_PARAMS) { \
  platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_1(CB_PARAMS) { \
  platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_2(CB_PARAMS) { \
  platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_3(CB_PARAMS) { \
  platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_4(CB_PARAMS) { \
  platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
}
// end of PROXY_GROUP_BLOCKING

#define PROXY_GROUP_NON_BLOCKING(CB_NAME, CB_PARAMS...) \
void platform_non_blocking_##CB_NAME(CB_PARAMS) { \
  int callbackId = reinterpret_cast<int>(user_data); \
  LDEBUG("enter <NON_BLOCKING> id:%d", callbackId); \
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
  CB_NAME local_cb_ptr = reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
  user_data = cbInfo.actualUserData; \
\
  CallbackWrapper wrapper = \
      [local_cb_ptr, EXPAND_LIST(CB_PARAMS_NAMES)] { \
    LDEBUG("calling local_cb_ptr() %p", local_cb_ptr); \
    local_cb_ptr(EXPAND_LIST(CB_PARAMS_NAMES)); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LDEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
} \
\
void platform_non_blocking_##CB_NAME##_0(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_1(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_2(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_3(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_4(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES)); \
}
// end of PROXY_GROUP_NON_BLOCKING

#define PROXY_GROUP_RETURN_NO_USER_DATA(CB_NAME, CB_RETURN, CB_PARAMS...) \
CB_RETURN platform_blocking_##CB_NAME(int callbackId, CB_PARAMS) { \
  LDEBUG("enter <RETURN_NO_USER_DATA> id:%d", callbackId); \
  if (gettid() == main_thread_id) { \
    CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
    LDEBUG("calling dart callback directly"); \
    return (reinterpret_cast<CB_NAME>(cbInfo.callbackPtr))(EXPAND_LIST(CB_PARAMS_NAMES)); \
  } \
  CB_RETURN dartCallbackRetVal = CB_RETURN(); \
  std::mutex mutex; \
  std::unique_lock<std::mutex> lock(mutex); \
  std::condition_variable cv; \
  bool dartCallbackFinished = false; \
\
  CallbackWrapper wrapper = \
      [callbackId, &dartCallbackRetVal, \
       EXPAND_LIST(CB_PARAMS_NAMES), \
       &cv, &dartCallbackFinished] { \
    CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
    CB_NAME local_cb_ptr = reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
    LDEBUG("calling local_cb_ptr() %p", local_cb_ptr); \
    dartCallbackRetVal = local_cb_ptr(EXPAND_LIST(CB_PARAMS_NAMES)); \
    dartCallbackFinished = true; \
    LDEBUG("calling notify_one()"); \
    cv.notify_one(); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LDEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
\
  LDEBUG("waiting for notification"); \
  while (!dartCallbackFinished) { \
    cv.wait(lock); \
  } \
  LDEBUG("exit, dartCallbackRetVal: %d", (int)dartCallbackRetVal); \
  return dartCallbackRetVal; \
} \
\
CB_RETURN platform_blocking_##CB_NAME##_0(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,0), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_1(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,1), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_2(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,2), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_3(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,3), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_4(CB_PARAMS) { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,4), EXPAND_LIST(CB_PARAMS_NAMES)); \
}
// end of PROXY_GROUP_RETURN_NO_USER_DATA

#define PROXY_GROUP_BLOCKING_NO_USER_DATA(CB_NAME, CB_PARAMS...) \
void platform_blocking_##CB_NAME(int callbackId, CB_PARAMS) { \
  LDEBUG("enter <BLOCKING_NO_USER_DATA> id:%d", callbackId); \
  if (gettid() == main_thread_id) { \
    CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
    LDEBUG("calling dart callback directly"); \
    return (reinterpret_cast<CB_NAME>(cbInfo.callbackPtr))(EXPAND_LIST(CB_PARAMS_NAMES)); \
  } \
  std::mutex mutex; \
  std::unique_lock<std::mutex> lock(mutex); \
  std::condition_variable cv; \
  bool dartCallbackFinished = false; \
\
  CallbackWrapper wrapper = \
      [callbackId, EXPAND_LIST(CB_PARAMS_NAMES), &cv, &dartCallbackFinished] { \
    CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
    CB_NAME local_cb_ptr = reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
    LDEBUG("calling local_cb_ptr() %p", local_cb_ptr); \
    local_cb_ptr(EXPAND_LIST(CB_PARAMS_NAMES)); \
    dartCallbackFinished = true; \
    LDEBUG("calling notify_one()"); \
    cv.notify_one(); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LDEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
\
  LDEBUG("waiting for notification"); \
  while (!dartCallbackFinished) { \
    cv.wait(lock); \
  } \
  LDEBUG("exit"); \
} \
\
void platform_blocking_##CB_NAME##_0(CB_PARAMS) { \
  platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,0), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_1(CB_PARAMS) { \
  platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,1), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_2(CB_PARAMS) { \
  platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,2), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_3(CB_PARAMS) { \
  platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,3), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_blocking_##CB_NAME##_4(CB_PARAMS) { \
  platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,4), EXPAND_LIST(CB_PARAMS_NAMES)); \
}
// end of PROXY_GROUP_BLOCKING_NO_USER_DATA

#define PROXY_GROUP_NON_BLOCKING_NO_USER_DATA(CB_NAME, CB_PARAMS...) \
void platform_non_blocking_##CB_NAME(int callbackId, CB_PARAMS) { \
  LDEBUG("enter <NON_BLOCKING_NO_USER_DATA> id:%d", callbackId); \
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
  CB_NAME local_cb_ptr = reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
\
  CallbackWrapper wrapper = \
      [local_cb_ptr, EXPAND_LIST(CB_PARAMS_NAMES)] { \
    LDEBUG("calling local_cb_ptr() %p", local_cb_ptr); \
    local_cb_ptr(EXPAND_LIST(CB_PARAMS_NAMES)); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LDEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
} \
\
void platform_non_blocking_##CB_NAME##_0(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,0), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_1(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,1), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_2(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,2), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_3(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,3), EXPAND_LIST(CB_PARAMS_NAMES)); \
} \
void platform_non_blocking_##CB_NAME##_4(CB_PARAMS) { \
  platform_non_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,4), EXPAND_LIST(CB_PARAMS_NAMES)); \
}
// end of PROXY_GROUP_NON_BLOCKING_NO_USER_DATA

#define PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM(CB_NAME, CB_RETURN) \
CB_RETURN platform_blocking_##CB_NAME(int callbackId) { \
  LDEBUG("enter <RETURN_NO_USER_DATA_NO_PARAM> id:%d", callbackId); \
  if (gettid() == main_thread_id) { \
    CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
    LDEBUG("calling dart callback directly"); \
    return (reinterpret_cast<CB_NAME>(cbInfo.callbackPtr))(); \
  } \
  CB_RETURN dartCallbackRetVal = CB_RETURN(); \
  std::mutex mutex; \
  std::unique_lock<std::mutex> lock(mutex); \
  std::condition_variable cv; \
  bool dartCallbackFinished = false; \
\
  CallbackWrapper wrapper = \
      [callbackId, &dartCallbackRetVal, &cv, &dartCallbackFinished] { \
    CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
    CB_NAME local_cb_ptr = reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
    LDEBUG("calling local_cb_ptr() %p", local_cb_ptr); \
    dartCallbackRetVal = local_cb_ptr(); \
    dartCallbackFinished = true; \
    LDEBUG("calling notify_one()"); \
    cv.notify_one(); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LDEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
\
  LDEBUG("waiting for notification"); \
  while (!dartCallbackFinished) { \
    cv.wait(lock); \
  } \
  LDEBUG("exit, dartCallbackRetVal: %d", (int)dartCallbackRetVal); \
  return dartCallbackRetVal; \
} \
\
CB_RETURN platform_blocking_##CB_NAME##_0() { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,0)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_1() { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,1)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_2() { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,2)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_3() { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,3)); \
} \
CB_RETURN platform_blocking_##CB_NAME##_4() { \
  return platform_blocking_##CB_NAME(GET_CALLBACK_ID(CB_NAME,4)); \
}
// end of PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM

// CB_NAME does not contain indices
#define MULTI_PROXY_MAP_ENTRY(CB_NAME) \
  { std::string( #CB_NAME ), {{ \
    reinterpret_cast<void*>(CB_NAME ## _0), \
    reinterpret_cast<void*>(CB_NAME ## _1), \
    reinterpret_cast<void*>(CB_NAME ## _2), \
    reinterpret_cast<void*>(CB_NAME ## _3), \
    reinterpret_cast<void*>(CB_NAME ## _4), \
  }} },

typedef void* MultiProxyFunctions[PROXY_INSTANCES_COUNT];
struct MultiProxyFunctionsContainer {
  MultiProxyFunctions mp;
};

#endif // _TIZEN_INTEROP_CALLBACKS_MACROS_H_
