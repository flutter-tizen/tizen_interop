#include <mutex>
#include <condition_variable>

#include <media/camera.h>

#include "async_callbacks_plugin.h"

#include "log.h"

extern "C" {

bool platform_blocking_camera_supported_preview_resolution_cb(int width, int height, void *reg_user_data) {
  LOG_DEBUG("in platform_camera_supported_preview_resolution_cb");

  int dartCallbackRetVal = 0;

  std::mutex mutex;
  std::unique_lock<std::mutex> lock(mutex);
  std::condition_variable cv;

  bool dartCallbackFinished = false;

  int callbackId = reinterpret_cast<int>(reg_user_data);
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId];

  camera_supported_preview_resolution_cb local_cb_ptr =
    reinterpret_cast<camera_supported_preview_resolution_cb>(cbInfo.callbackPtr);
  void *actual_user_data = cbInfo.actualUserData;
  CallbackWrapper wrapper =
      [local_cb_ptr, &dartCallbackRetVal, width, height, actual_user_data, &cv, &dartCallbackFinished] {
    LOG_DEBUG("calling local_cb_ptr()");
    dartCallbackRetVal = local_cb_ptr(width, height, actual_user_data);
    dartCallbackFinished = true;
    LOG_DEBUG("calling notify_one()");
    cv.notify_one();
  };

  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper);
  LOG_DEBUG("calling RequestCallbackCall()");
  RequestCallbackCall(wrapper_ptr);

  LOG_DEBUG("waiting for notification");
  while (!dartCallbackFinished) {
    cv.wait(lock);
  }

  LOG_DEBUG("notification received, dartCallbackRetVal: %d", dartCallbackRetVal);
  return dartCallbackRetVal;
}

bool platform_blocking_camera_supported_preview_resolution_cb_0(int width, int height, void *reg_user_data) {
  return platform_blocking_camera_supported_preview_resolution_cb(width, height, reg_user_data);
}

bool platform_blocking_camera_supported_preview_resolution_cb_1(int width, int height, void *reg_user_data) {
  return platform_blocking_camera_supported_preview_resolution_cb(width, height, reg_user_data);
}

bool platform_blocking_camera_supported_preview_resolution_cb_2(int width, int height, void *reg_user_data) {
  return platform_blocking_camera_supported_preview_resolution_cb(width, height, reg_user_data);
}

bool platform_blocking_camera_supported_preview_resolution_cb_3(int width, int height, void *reg_user_data) {
  return platform_blocking_camera_supported_preview_resolution_cb(width, height, reg_user_data);
}

bool platform_blocking_camera_supported_preview_resolution_cb_4(int width, int height, void *reg_user_data) {
  return platform_blocking_camera_supported_preview_resolution_cb(width, height, reg_user_data);
}

// TODO maybe we could remove this macro and give names in the call itself
#define CB_PARAMS_NAMES width, height
PROXY_GROUP_FOREACH(camera_supported_capture_resolution_cb, int width, int height)
#undef CB_PARAMS_NAMES

} // extern "C"
