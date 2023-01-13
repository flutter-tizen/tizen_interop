import 'package:flutter/material.dart';
import 'dart:ffi';
import 'dart:isolate';

import 'package:ffi/ffi.dart';
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
  Pointer<NativeFunction<Bool Function(Int, Int, Pointer<Void>)>> regCallback =
      nullptr;
  Pointer<Void> userData = nullptr;
  SendPort? sendPort;

  ForeachCallArgs(
      this.cameraPtr, this.regCallback, this.userData, this.sendPort);

  ForeachCallArgsAsInts toInts() {
    ForeachCallArgsAsInts res = ForeachCallArgsAsInts();

    res.cameraPtrInt = cameraPtr.address;
    res.regCallbackInt = regCallback.address;
    res.userDataInt = userData.address;
    res.sendPort = sendPort;

    return res;
  }
}

class MyAppState extends State<MyApp> {
  List<String> supportedRes = [];
  final callbacks = TizenInteropCallbacks();

  @override
  void initState() {
    super.initState();
    myAppState = this;
    initPlatformState();
  }

  void initPlatformState() async {
    const bool exceptionalRetVal = false;
    int ret;

    Pointer<Pointer<camera_cli_s>> cameraPtr = calloc();

    Log.debug('ConsoleMessage', 'calling tizen.camera_create()');
    ret = tizen.camera_create(camera_device_e.CAMERA_DEVICE_CAMERA0, cameraPtr);
    if (ret != 0) {
      Log.debug('ConsoleMessage', 'tizen.camera_create() failed, ret: $ret');
      throw Exception('Failed to create camera');
    }

    Log.debug('ConsoleMessage', 'calling register()');
    final rcbPreview =
        callbacks.register<Bool Function(Int, Int, Pointer<Void>)>(
            'camera_supported_preview_resolution_cb',
            Pointer.fromFunction(dartPreviewResCb, exceptionalRetVal),
            nullptr,
            true);

    final recPortPreview = ReceivePort();

    // Prepare foreach call's arguments that will be sent to the spawned isolate.
    ForeachCallArgs args = ForeachCallArgs(cameraPtr, rcbPreview.regCallbackPtr,
        rcbPreview.regUserData, recPortPreview.sendPort);

    // We can't send pointers, but we can send ints
    var intArgs = args.toInts();

    // Spawn an isolate which will call the foreach function
    Log.debug('ConsoleMessage', 'spawning an isolate');
    await Isolate.spawn(callForeachPreviewRes, intArgs);

    // Wait for the spawned isolate to complete its work
    Log.debug('ConsoleMessage', 'waiting for recPort.first');
    await recPortPreview.first;
    setState(() {});

    if (!mounted) return;
  }

  static void callForeachPreviewRes(ForeachCallArgsAsInts args) async {
    Log.debug('ConsoleMessage',
        'calling tizen.camera_foreach_supported_preview_resolution()');

    // Convert received ints back to pointers
    Pointer<Pointer<camera_cli_s>> cameraPtr =
        Pointer.fromAddress(args.cameraPtrInt);
    Pointer<NativeFunction<Bool Function(Int, Int, Pointer<Void>)>>
        regCallback = Pointer.fromAddress(args.regCallbackInt);
    Pointer<Void> userData = Pointer.fromAddress(args.userDataInt);

    int ret = tizen.camera_foreach_supported_preview_resolution(
        cameraPtr.value, regCallback, userData);

    if (ret != 0) {
      Log.debug('ConsoleMessage',
          'tizen.camera_foreach_supported_preview_resolution() failed, ret: $ret');
      var msg = tizen.get_error_message(ret).toDartString();
      Log.debug('ConsoleMessage', 'ret: $ret, get_error_message(ret): $msg');
      throw Exception(
          'tizen.camera_foreach_capture_preview_resolution() failed');
    }

    // The second argument is not important here, we return 1 here because
    // the cost of sending it to the original isolate will be relatively small.
    // We primarily care about notifying the original isolate that the spawned
    // isolate has finished its work.
    Isolate.exit(args.sendPort, 1);
  }

  static bool dartPreviewResCb(int width, int height, Pointer<Void> userData) {
    myAppState?.supportedRes.add('${width}x${height}');

    // If we return false here, then the iteration will stop after the first call
    // of the callback, as expected.
    // Returning true results in iteration through all values.
    return true;
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
              const Text('Supported preview resolutions:'),
              for (var res in supportedRes)
                Padding(
                  padding: const EdgeInsets.only(top: 8.0),
                  child: Text(res),
                ),
            ],
          ),
        ),
      ),
    );
  }
}
