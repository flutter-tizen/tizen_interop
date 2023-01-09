#ifndef _ASYNC_CALLBACKS_DEVICE_H_
#define _ASYNC_CALLBACKS_DEVICE_H_

#include "async_callbacks_plugin.h"
#include "macros.h"


extern "C" {

MULTI_PROXY_DECLARATIONS(bool, platform_blocking_camera_supported_preview_resolution_cb, int width, int height)
MULTI_PROXY_DECLARATIONS(bool, platform_blocking_camera_supported_capture_resolution_cb, int width, int height)

} // extern "C"

#endif // _ASYNC_CALLBACKS_DEVICE_H_
