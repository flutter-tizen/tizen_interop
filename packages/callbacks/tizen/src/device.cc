#include <mutex>
#include <condition_variable>

#include <device/callback.h>

#include "async_callbacks_plugin.h"

#include "log.h"

extern "C" {

__attribute__((visibility("default")))
void platform_blocking_device_changed_cb(device_callback_e type, void *value, void *reg_user_data) {
  LOG_DEBUG("inside platform_battery_charging_changed_cb");
  printf("in platform_battery_charging_changed_cb()\n");

  std::mutex mutex;
  std::unique_lock<std::mutex> lock(mutex);
  std::condition_variable cv;

  bool dartCallbackFinished = false;

  int callbackId = reinterpret_cast<int>(reg_user_data);
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId];
  device_changed_cb local_cb_ptr =
    reinterpret_cast<device_changed_cb>(cbInfo.callbackPtr);
  void *actual_user_data = cbInfo.actualUserData;
  CallbackWrapper wrapper = [local_cb_ptr, type, value, actual_user_data, &cv, &dartCallbackFinished] {
    LOG_DEBUG("calling local_cb_ptr()");
    local_cb_ptr(type, value, actual_user_data);
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
}

void platform_blocking_device_changed_cb_0(device_callback_e type, void *value, void *reg_user_data) {
  platform_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_blocking_device_changed_cb_1(device_callback_e type, void *value, void *reg_user_data) {
  platform_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_blocking_device_changed_cb_2(device_callback_e type, void *value, void *reg_user_data) {
  platform_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_blocking_device_changed_cb_3(device_callback_e type, void *value, void *reg_user_data) {
  platform_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_blocking_device_changed_cb_4(device_callback_e type, void *value, void *reg_user_data) {
  platform_blocking_device_changed_cb(type, value, reg_user_data);
}

__attribute__((visibility("default")))  // if we're going to use multi proxies, is this needed?
void platform_non_blocking_device_changed_cb(device_callback_e type, void *value, void *reg_user_data) {
  LOG_DEBUG("inside platform_battery_charging_changed_cb");
  printf("in platform_battery_charging_changed_cb()\n");

  int callbackId = reinterpret_cast<int>(reg_user_data);
  CallbackInfo cbInfo = __cb_id_to_info_map[callbackId];
  device_changed_cb local_cb_ptr =
    reinterpret_cast<device_changed_cb>(cbInfo.callbackPtr);
  void *actual_user_data = cbInfo.actualUserData;
  CallbackWrapper wrapper = [local_cb_ptr, type, value, actual_user_data] {
    LOG_DEBUG("calling local_cb_ptr()");
    local_cb_ptr(type, value, actual_user_data);
  };
  CallbackWrapper *wrapper_ptr = new CallbackWrapper(wrapper);

  LOG_DEBUG("calling RequestCallbackCall()");
  RequestCallbackCall(wrapper_ptr);
}

void platform_non_blocking_device_changed_cb_0(device_callback_e type, void *value, void *reg_user_data) {
  platform_non_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_non_blocking_device_changed_cb_1(device_callback_e type, void *value, void *reg_user_data) {
  platform_non_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_non_blocking_device_changed_cb_2(device_callback_e type, void *value, void *reg_user_data) {
  platform_non_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_non_blocking_device_changed_cb_3(device_callback_e type, void *value, void *reg_user_data) {
  platform_non_blocking_device_changed_cb(type, value, reg_user_data);
}

void platform_non_blocking_device_changed_cb_4(device_callback_e type, void *value, void *reg_user_data) {
  platform_non_blocking_device_changed_cb(type, value, reg_user_data);
}

} // extern "C"
