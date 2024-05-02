// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// ignore_for_file: public_member_api_docs, avoid_print

import 'dart:ffi';

import 'package:ffi/ffi.dart';
import 'package:flutter/material.dart';
import 'package:tizen_interop/6.0/tizen.dart';
import 'package:tizen_interop_callbacks/tizen_interop_callbacks.dart';

class BatteryTab extends StatefulWidget {
  const BatteryTab({super.key});

  @override
  State<BatteryTab> createState() => _BatteryTabState();
}

class _BatteryTabState extends State<BatteryTab> {
  final TizenInteropCallbacks _callbacks = TizenInteropCallbacks();

  late final RegisteredCallback<
      Void Function(Int32, Pointer<Void>, Pointer<Void>)> _chargingCallback;
  late final RegisteredCallback<
      Void Function(Int32, Pointer<Void>, Pointer<Void>)> _levelCallback;

  bool? _batteryCharging;
  int _batteryLevel = 0;

  static void _batteryChanged(
    int type,
    Pointer<Void> value,
    Pointer<Void> userData,
  ) {
    final state =
        TizenInteropCallbacks.getUserObject<_BatteryTabState>(userData)!;
    if (type == device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING) {
      state._batteryCharging = value.address != 0;
    } else if (type == device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY) {
      state._batteryLevel = value.address;
    }
    state.setState(() {});
  }

  @override
  void initState() {
    super.initState();

    _chargingCallback = _callbacks.register(
      'device_changed_cb',
      Pointer.fromFunction(_batteryChanged),
      userObject: this,
      blocking: true,
    );
    int ret = tizen.device_add_callback(
      device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING,
      _chargingCallback.interopCallback,
      _chargingCallback.interopUserData,
    );
    if (ret != 0) {
      final error = tizen.get_error_message(ret).toDartString();
      print('Failed to add battery charging callback: $error');
    }

    _levelCallback = _callbacks.register(
      'device_changed_cb',
      Pointer.fromFunction(_batteryChanged),
      userObject: this,
    );
    ret = tizen.device_add_callback(
      device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
      _levelCallback.interopCallback,
      _levelCallback.interopUserData,
    );
    if (ret != 0) {
      final error = tizen.get_error_message(ret).toDartString();
      print('Failed to add battery level callback: $error');
    }

    using((Arena arena) {
      Pointer<Int> percent = arena();
      int ret = tizen.device_battery_get_percent(percent);
      if (ret == 0) {
        _batteryLevel = percent.value;
      } else {
        final error = tizen.get_error_message(ret).toDartString();
        print('Failed to read battery level: $error');
      }

      Pointer<Bool> charging = arena();
      ret = tizen.device_battery_is_charging(charging);
      if (ret == 0) {
        _batteryCharging = charging.value;
      } else {
        final error = tizen.get_error_message(ret).toDartString();
        print('Failed to read battery charging status: $error');
      }
      setState(() {});
    });
  }

  @override
  void dispose() {
    tizen.device_remove_callback(
      device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
      _levelCallback.interopCallback,
    );
    tizen.device_remove_callback(
      device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING,
      _chargingCallback.interopCallback,
    );
    _callbacks.unregister(_levelCallback);
    _callbacks.unregister(_chargingCallback);

    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    String status = 'Unknown';
    if (_batteryCharging != null) {
      status = _batteryCharging! ? 'Charging' : 'Discharging';
    }
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Text('Battery status: $status'),
        if (_batteryCharging != null) Text('Battery level: $_batteryLevel%')
      ],
    );
  }
}
