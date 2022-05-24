import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:isolate';
import 'dart:ffi';
import 'dart:collection';

import 'package:flutter/services.dart';
import 'package:ffi/ffi.dart';
import 'package:tizen_log/tizen_log.dart';
import 'package:async_callbacks/async_callbacks.dart';

import 'package:tizen_interop/6.0/tizen.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  State<MyApp> createState() => _MyAppState();
}

// A structure which holds data necessary to call the foreach function
// in another isolate. This includes a SendPort and arguments to foreach call.
// Same as ForeachCallArgs below, except pointers are kept as integers.
// We need this to be able to send the pointers to another isolate.
class ForeachCallArgsAsInts {
  int cameraPtrInt = 0;
  int regCallbackInt = 0;
  int userDataInt = 0;
  SendPort? sendPort;
}

// A class which holds foreach call arguments and the SendPort.
// toInts() converts the data to ForeachCallArgsAsInts().
class ForeachCallArgs {
  Pointer<Pointer<camera_cli_s>> cameraPtr = nullptr;
  Pointer<NativeFunction<camera_supported_preview_resolution_cb>> regCallback = nullptr;
  Pointer<Void> userData = nullptr;
  SendPort? sendPort;

  ForeachCallArgs(cameraPtr, regCallback, userData, sendPort) {
    this.cameraPtr = cameraPtr;
    this.regCallback = regCallback;
    this.userData = userData;
    this.sendPort = sendPort;
  }

  ForeachCallArgsAsInts toInts() {
    ForeachCallArgsAsInts res = ForeachCallArgsAsInts();

    res.cameraPtrInt = cameraPtr.address;
    res.regCallbackInt = regCallback.address;
    res.userDataInt = userData.address;
    res.sendPort = sendPort;

    return res;
  }
}

class _MyAppState extends State<MyApp> {
  String _platformVersion = 'Unknown';
  late AsyncCallbacks acbs;

  @override
  void initState() {
    super.initState();
    initPlatformState();
  }

  Future<void> initPlatformState() async {
    Log.debug('ConsoleMessage', 'in initPlatformState()');

    String platformVersion;
    // Platform messages may fail, so we use a try/catch PlatformException.
    // We also handle the message potentially returning null.
    try {
      platformVersion =
          await AsyncCallbacks.platformVersion ?? 'Unknown platform version';
    } on PlatformException {
      platformVersion = 'Failed to get platform version.';
    }

    // Create an object that will make the callback available
    Log.debug('ConsoleMessage', 'creating AsyncCallbacks()');
    acbs = AsyncCallbacks();
    Log.debug('ConsoleMessage', 'calling AsyncCallbacks.init()');
    acbs.init();

    registerBatteryCallbacks();
    getSupportedFormats();

    // If the widget was removed from the tree while the asynchronous platform
    // message was in flight, we want to discard the reply rather than calling
    // setState to update our non-existent appearance.
    if (!mounted) return;

    setState(() {
      _platformVersion = platformVersion;
    });
  }

  void registerBatteryCallbacks() {
    Log.debug('ConsoleMessage', 'calling register() for proxy 1');
    var rcb1 = acbs.register
        <device_changed_cb>
        ('device_changed_cb',
          Pointer.fromFunction<device_changed_cb>(dartBatteryCb_1),
          Pointer.fromAddress(5),
          false);

    Log.debug('ConsoleMessage', 'calling register() for proxy 2');
    var rcb2 = acbs.register
        <device_changed_cb>
        ('device_changed_cb',
          Pointer.fromFunction<device_changed_cb>(dartBatteryCb_2),
          Pointer.fromAddress(6),
          false);

    acbs.unregister(rcb1);

    int ret = 0;

    print('calling tizen.device_add_callback() for cb 1');
    ret = tizen.device_add_callback(
        2 /*DEVICE_CALLBACK_BATTERY_CHARGING */,
        rcb1.regCallbackPtr,
        rcb1.regUserData);
    if (ret != 0) {
      print('tizen.device_add_callback() failed, ret: $ret');
      throw Exception('Failed to add callback');
    }

    print('calling tizen.device_add_callback() for cb 2');
    ret = tizen.device_add_callback(
        2 /*DEVICE_CALLBACK_BATTERY_CHARGING */,
        rcb2.regCallbackPtr,
        rcb2.regUserData);
    if (ret != 0) {
      print('tizen.device_add_callback() failed, ret: $ret');
      throw Exception('Failed to add callback');
    }

    print('calling tizen.device_remove_callback() for cb 1');
    ret = tizen.device_remove_callback(
        2 /*DEVICE_CALLBACK_BATTERY_CHARGING */,
        rcb1.regCallbackPtr);
    if (ret != 0) {
      print('tizen.device_add_callback() failed, ret: $ret');
      throw Exception('Failed to add callback');
    }
  }

  static void dartBatteryCb_1(int type, Pointer<Void> value, Pointer<Void> userData) {
    print('---- in dartBatteryCb_1() ----');

    print('type: $type, value: $value, userData: $userData');
  }

  static void dartBatteryCb_2(int type, Pointer<Void> value, Pointer<Void> userData) {
    print('---- in dartBatteryCb_2() ----');

    print('type: $type, value: $value, userData: $userData');
  }

  void getSupportedFormats() async {
    const int exceptionalRetVal = 0;
    int ret;

    Pointer<Pointer<camera_cli_s>> cameraPtr = calloc();

    Log.debug('ConsoleMessage', 'calling tizen.camera_create()');
    ret = tizen.camera_create(camera_device_e.CAMERA_DEVICE_CAMERA0, cameraPtr);
    if (ret != 0) {
      Log.debug('ConsoleMessage', 'tizen.camera_create() failed, ret: $ret');
      throw Exception('Failed to create camera');
    }

    Log.debug('ConsoleMessage', 'calling register()');
    RegisteredCallback rcbPreview = acbs.register
        <camera_supported_preview_resolution_cb>
        ('camera_supported_preview_resolution_cb',
        Pointer.fromFunction<camera_supported_preview_resolution_cb>
          (dartPreviewResCb, exceptionalRetVal),
        nullptr,
        true);

    final recPortPreview = ReceivePort();

    // Prepare foreach call's arguments that will be sent to the spawned isolate.
    ForeachCallArgs args = ForeachCallArgs(
        cameraPtr,
        rcbPreview.regCallbackPtr,
        rcbPreview.regUserData,
        recPortPreview.sendPort);

    // We can't send pointers, but we can send ints
    var intArgs = args.toInts();

    // Spawn an isolate which will call the foreach function
    Log.debug('ConsoleMessage', 'spawning an isolate');
    await Isolate.spawn(callForeachPreviewRes, intArgs);

    // Wait for the spawned isolate to complete its work
    Log.debug('ConsoleMessage', 'waiting for recPort.first');
    await recPortPreview.first;

    // Now the same calls, but for another foreach callback
    Log.debug('ConsoleMessage', 'calling register()');
    RegisteredCallback rcbCapture = acbs.register
        <camera_supported_capture_resolution_cb>
        ('camera_supported_capture_resolution_cb',
        Pointer.fromFunction<camera_supported_capture_resolution_cb>
          (dartCaptureResCb, exceptionalRetVal),
        nullptr,
        true);
    final recPortCapture = ReceivePort();
    args = ForeachCallArgs(
        cameraPtr,
        rcbCapture.regCallbackPtr,
        rcbCapture.regUserData,
        recPortCapture.sendPort);
    intArgs = args.toInts();
    Log.debug('ConsoleMessage', 'spawning an isolate');
    await Isolate.spawn(callForeachCaptureRes, intArgs);
    Log.debug('ConsoleMessage', 'waiting for recPort.first');
    await recPortCapture.first;

    Log.debug('ConsoleMessage', 'calling tizen.camera_destroy()');
    ret = tizen.camera_destroy(cameraPtr.value);
    if (ret != 0) {
      Log.debug('ConsoleMessage', 'tizen.camera_destroy() failed, ret: $ret');
      throw Exception('Failed to destroy camera');
    }
  }

  static void callForeachPreviewRes(ForeachCallArgsAsInts args) async {
    Log.debug('ConsoleMessage',
        'calling tizen.camera_foreach_supported_preview_resolution()');

    // Convert received ints back to pointers
    Pointer<Pointer<camera_cli_s>> cameraPtr = Pointer.fromAddress(args.cameraPtrInt);
    Pointer<NativeFunction<camera_supported_preview_resolution_cb>> regCallback =
      Pointer.fromAddress(args.regCallbackInt);
    Pointer<Void> userData = Pointer.fromAddress(args.userDataInt);

    int ret = tizen.camera_foreach_supported_preview_resolution(
        cameraPtr.value,
        regCallback,
        userData);

    if (ret != 0) {
      Log.debug('ConsoleMessage',
          'tizen.camera_foreach_supported_preview_resolution() failed, ret: $ret');
      var msg = tizen.get_error_message(ret).toDartString();
      Log.debug('ConsoleMessage', 'ret: $ret, get_error_message(ret): $msg');
      throw Exception('tizen.camera_foreach_capture_preview_resolution() failed');
    }

    // The second argument is not important here, we return 1 here because
    // the cost of sending it to the original isolate will be relatively small.
    // We primarily care about notifying the original isolate that the spawned
    // isolate has finished its work.
    Isolate.exit(args.sendPort, 1);
  }

  static void callForeachCaptureRes(ForeachCallArgsAsInts args) async {
    Log.debug('ConsoleMessage',
        'calling tizen.camera_foreach_supported_capture_resolution()');

    Pointer<Pointer<camera_cli_s>> cameraPtr = Pointer.fromAddress(args.cameraPtrInt);
    Pointer<NativeFunction<camera_supported_capture_resolution_cb>> regCallback =
      Pointer.fromAddress(args.regCallbackInt);
    Pointer<Void> userData = Pointer.fromAddress(args.userDataInt);

    int ret = tizen.camera_foreach_supported_capture_resolution(
        cameraPtr.value,
        regCallback,
        userData);

    if (ret != 0) {
      Log.debug('ConsoleMessage',
          'tizen.camera_foreach_supported_capture_resolution() failed, ret: $ret');
      var msg = tizen.get_error_message(ret).toDartString();
      Log.debug('ConsoleMessage', 'ret: $ret, get_error_message(ret): $msg');
      throw Exception('tizen.camera_foreach_capture_capture_resolution() failed');
    }

    Isolate.exit(args.sendPort, 1);
  }

  static int dartPreviewResCb(int width, int height, Pointer<Void> userData) {
    Log.debug('ConsoleMessage',
        '----- in Dart preview resolutions cb ----- width: $width, height: $height, userData: $userData');

    // If we return 0 here, then the iteration will stop after the first call
    // of the callback, as expected.
    // Returning 1 results in iterating through all values.
    return 1;
  }

  static int dartCaptureResCb(int width, int height, Pointer<Void> userData) {
    Log.debug('ConsoleMessage',
        '----- in Dart capture resolutions cb ----- width: $width, height: $height, userData: $userData');
    return 1;
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
          child: Text('Running on: $_platformVersion\n'),
        ),
      ),
    );
  }
}
