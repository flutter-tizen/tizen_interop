import 'dart:ffi';

import 'package:ffi/ffi.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:tizen_interop/4.0/tizen.dart';
import 'package:tizen_interop_callbacks/tizen_interop_callbacks.dart';
import 'package:tizen_log/tizen_log.dart';

import 'strings.dart';

class BatteryTab extends StatelessWidget {
  const BatteryTab({super.key});

  @override
  Widget build(BuildContext context) {
    return Consumer<BatteryService>(builder: (context, battery, child) {
      if (battery.batteryAvailable) {
        return Column(
          children: [
            Text('Battery charging: ${battery.batteryCharging}'),
            Text('Battery level: ${battery.batteryLevel}'),
          ],
        );
      } else {
        return const Text('ERROR: Battery info not available.');
      }
    });
  }
}

class BatteryService with ChangeNotifier {
  bool? _batteryCharging;
  int? _batteryLevel;
  late final Pointer<void> userData;
  late final RegisteredCallback<
      Void Function(Int32, Pointer<Void>, Pointer<Void>)> chargingCallback;
  late final RegisteredCallback<
      Void Function(Int32, Pointer<Void>, Pointer<Void>)> levelCallback;

  bool get batteryAvailable => _batteryCharging != null;
  bool get batteryCharging => _batteryCharging ?? false;
  int get batteryLevel => _batteryLevel ?? 0;

  BatteryService() {
    Log.info(logTag, 'Initializing BatteryService');
    final callbacks = TizenInteropCallbacks();

    chargingCallback = callbacks.register(
        'device_changed_cb', Pointer.fromFunction(_batteryChanged),
        userObject: this, blocking: true);
    int ret = tizen.device_add_callback(
        device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING,
        chargingCallback.interopCallback,
        chargingCallback.interopUserData);

    if (ret != 0) {
      Log.error(logTag, 'Failed to add battery charging callback [$ret]');
    }

    levelCallback = callbacks.register(
        'device_changed_cb', Pointer.fromFunction(_batteryChanged),
        userObject: this);
    ret = tizen.device_add_callback(
        device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
        levelCallback.interopCallback,
        levelCallback.interopUserData);

    if (ret != 0) {
      Log.error(logTag, 'Failed to add battery level callback [$ret]');
    }

    using((Arena arena) {
      Pointer<Int> intPointer = arena();
      ret = tizen.device_battery_get_percent(intPointer);
      if (ret == 0) {
        _batteryLevel = intPointer.value;
      } else {
        Log.error(logTag, 'Failed to read battery level [$ret]');
      }
      Pointer<Bool> boolPointer = arena();
      ret = tizen.device_battery_is_charging(boolPointer);
      if (ret == 0) {
        _batteryCharging = boolPointer.value;
      } else {
        Log.error(logTag, 'Failed to read battery charging status [$ret]');
      }
    });
  }

  @override
  void dispose() {
    Log.info(logTag, 'disposing BatteryService');
    final callbacks = TizenInteropCallbacks();
    tizen.device_remove_callback(
        device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
        levelCallback.interopCallback);
    tizen.device_remove_callback(
        device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING,
        chargingCallback.interopCallback);
    callbacks.unregister(levelCallback);
    callbacks.unregister(chargingCallback);
    super.dispose();
  }

  static void _batteryChanged(
      int type, Pointer<Void> value, Pointer<Void> userData) {
    Log.info(
        logTag, 'battery callback called, type:$type, value: ${value.address}');
    BatteryService? battery = TizenInteropCallbacks.getUserObject(userData);
    int val = value.address;
    if (type == device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING) {
      battery?._updateBatteryCharging(val != 0);
    } else if (type == device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY) {
      battery?._updateBatteryLevel(val);
    }
  }

  void _updateBatteryLevel(int level) {
    if (_batteryLevel != level) {
      _batteryLevel = level;
      notifyListeners();
    }
  }

  void _updateBatteryCharging(bool charging) {
    if (_batteryCharging != charging) {
      _batteryCharging = charging;
      notifyListeners();
    }
  }
}
