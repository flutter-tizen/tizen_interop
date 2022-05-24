#ifndef _ASYNC_CALLBACKS_MACROS_H_
#define _ASYNC_CALLBACKS_MACROS_H_

#ifndef EXPAND_LIST
#define EXPAND_LIST(...) __VA_ARGS__
#endif

// Note: CB_PARAMS_NAMES should be defined before calling PROXY_GROUP_FOREACH.

// foreach callbacks always return bool
#ifndef PROXY_GROUP_FOREACH
#define PROXY_GROUP_FOREACH(CB_NAME, CB_PARAMS...) \
bool platform_blocking_##CB_NAME(CB_PARAMS, void *reg_user_data) { \
  LOG_DEBUG("in platform_blocking_##CB_NAME"); \
\
  int dartCallbackRetVal = 0; \
\
  std::mutex mutex; \
  std::unique_lock<std::mutex> lock(mutex); \
  std::condition_variable cv; \
\
  bool dartCallbackFinished = false; \
\
  int callbackId = reinterpret_cast<int>(reg_user_data); \
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId]; \
\
  CB_NAME local_cb_ptr = \
    reinterpret_cast<CB_NAME>(cbInfo.callbackPtr); \
  void *actual_user_data = cbInfo.actualUserData; \
  CallbackWrapper wrapper = \
      [local_cb_ptr, &dartCallbackRetVal, \
       EXPAND_LIST(CB_PARAMS_NAMES), actual_user_data, \
       &cv, &dartCallbackFinished] { \
    LOG_DEBUG("calling local_cb_ptr()"); \
    dartCallbackRetVal = local_cb_ptr(EXPAND_LIST(CB_PARAMS_NAMES), actual_user_data); \
    dartCallbackFinished = true; \
    LOG_DEBUG("calling notify_one()"); \
    cv.notify_one(); \
  }; \
\
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper); \
  LOG_DEBUG("calling RequestCallbackCall()"); \
  RequestCallbackCall(wrapper_ptr); \
\
  LOG_DEBUG("waiting for notification"); \
  while (!dartCallbackFinished) { \
    cv.wait(lock); \
  } \
\
  LOG_DEBUG("notification received, dartCallbackRetVal: %d", dartCallbackRetVal); \
  return dartCallbackRetVal; \
} \
\
bool platform_blocking_##CB_NAME##_0(CB_PARAMS, void *reg_user_data) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES), reg_user_data); \
} \
bool platform_blocking_##CB_NAME##_1(CB_PARAMS, void *reg_user_data) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES), reg_user_data); \
} \
bool platform_blocking_##CB_NAME##_2(CB_PARAMS, void *reg_user_data) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES), reg_user_data); \
} \
bool platform_blocking_##CB_NAME##_3(CB_PARAMS, void *reg_user_data) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES), reg_user_data); \
} \
bool platform_blocking_##CB_NAME##_4(CB_PARAMS, void *reg_user_data) { \
  return platform_blocking_##CB_NAME(EXPAND_LIST(CB_PARAMS_NAMES), reg_user_data); \
}
#endif  // PROXY_GROUP_FOREACH

// PARAMS do not include the last parameter (user_data)
#ifndef MULTI_PROXY_DECLARATIONS
#define MULTI_PROXY_DECLARATIONS(RET_TYPE, CB_NAME, PARAMS...) \
RET_TYPE CB_NAME ## _0(PARAMS, void *reg_user_data); \
RET_TYPE CB_NAME ## _1(PARAMS, void *reg_user_data); \
RET_TYPE CB_NAME ## _2(PARAMS, void *reg_user_data); \
RET_TYPE CB_NAME ## _3(PARAMS, void *reg_user_data); \
RET_TYPE CB_NAME ## _4(PARAMS, void *reg_user_data);
#endif // MULTI_PROXY_DECLARATIONS

#endif // _ASYNC_CALLBACKS_MACROS_H_
