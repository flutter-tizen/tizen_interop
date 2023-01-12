import 'package:flutter/material.dart';
import 'dart:ffi';
import 'package:tizen_interop/6.5/tizen.dart';
import 'package:tizen_interop_callbacks/tizen_interop_callbacks.dart';
import 'package:tizen_log/tizen_log.dart';

MyAppState? myAppState;

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => MyAppState();
}

class MyAppState extends State<MyApp> {
  bool? _batteryCharging;
  int? _batteryLevel;
  final callbacks = TizenInteropCallbacks();

  @override
  void initState() {
    super.initState();
    myAppState = this;
    initPlatformState();
  }

  void initPlatformState() {
    final chargerCb =
        callbacks.register<Void Function(Int32, Pointer<Void>, Pointer<Void>)>(
            'device_changed_cb',
            Pointer.fromFunction(_batteryChanged),
            Pointer.fromAddress(0),
            true);
    int ret = tizen.device_add_callback(
        device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING,
        chargerCb.regCallbackPtr,
        chargerCb.regUserData);

    if (ret != 0) {
      throw Exception('Failed to add battery charging callback');
    }

    final levelCb =
        callbacks.register<Void Function(Int32, Pointer<Void>, Pointer<Void>)>(
            'device_changed_cb', Pointer.fromFunction(_batteryChanged));
    ret = tizen.device_add_callback(
        device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
        levelCb.regCallbackPtr,
        levelCb.regUserData);

    // If you need to remove a callback, first unregister it:
    // callbacks.unregister(chargerCb);
    //
    // Then call the Native API function:
    // ret = tizen.device_remove_callback(
    //     device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING,
    //     chargerCb.regCallbackPtr);

    if (ret != 0) {
      throw Exception('Failed to add battery level callback');
    }

    if (!mounted) return;
  }

  static void _batteryChanged(
      int type, Pointer<Void> value, Pointer<Void> userData) {
    Log.info(logTag, 'callback called, type:$type, value: ${value.address}');
    final int val = value.address;
    if (type == device_callback_e.DEVICE_CALLBACK_BATTERY_CHARGING) {
      myAppState?.updateBatteryCharging(val);
    } else if (type == device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY) {
      myAppState?.updateBatteryLevel(val);
    }
  }

  void updateBatteryLevel(int val) {
    setState(() {
      _batteryLevel = val;
    });
  }

  void updateBatteryCharging(int val) {
    setState(() {
      _batteryCharging = (val != 0);
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
          child: Column(
            children: [
              Text('Battery charging: $_batteryCharging'),
              Text('Battery level: $_batteryLevel'),
            ],
          ),
        ),
      ),
    );
  }
}
