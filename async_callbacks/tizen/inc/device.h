#ifndef _ASYNC_CALLBACKS_CAMERA_H_
#define _ASYNC_CALLBACKS_CAMERA_H_


#include <device/callback.h>

#include "macros.h"

extern "C" {

MULTI_PROXY_DECLARATIONS(void, platform_blocking_device_changed_cb, device_callback_e type, void *value)
MULTI_PROXY_DECLARATIONS(void, platform_non_blocking_device_changed_cb, device_callback_e type, void *value)

} // extern "C"

#endif // _ASYNC_CALLBACKS_CAMERA_H_
