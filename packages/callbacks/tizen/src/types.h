// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TIZEN_INTEROP_CALLBACKS_TYPES_H_
#define TIZEN_INTEROP_CALLBACKS_TYPES_H_

// This file contains a few structures copied from Tizen native API headers,
// as we need their full definitions if they are used directly in callback
// signatures but not as pointers.

typedef struct {
  double latitude;
  double longitude;
} location_coords_s_copy;

typedef struct {
  int x;
  int y;
} mv_point_s_copy;

typedef struct {
  mv_point_s_copy point;
  int width;
  int height;
} mv_rectangle_s_copy;

#define WIFI_DIRECT_MAX_DEVICE_NAME_LEN 32
#define WIFI_DIRECT_MAC_ADDRESS_LEN 18
typedef struct {
  char device_name[WIFI_DIRECT_MAX_DEVICE_NAME_LEN + 1];
  char mac_address[WIFI_DIRECT_MAC_ADDRESS_LEN + 1];
} wifi_direct_connection_state_cb_data_s_copy;

typedef enum { SOME_ENUM_0 } some_enum;

typedef void *void_pointer;

#endif  // TIZEN_INTEROP_CALLBACKS_TYPES_H_
