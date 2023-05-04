// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'dart:async';
import 'dart:ffi';
import 'dart:isolate';

import 'package:ffi/ffi.dart';
import 'package:flutter/material.dart';
import 'package:tizen_interop/4.0/tizen.dart';
import 'package:tizen_interop_callbacks/tizen_interop_callbacks.dart';
import 'package:tizen_log/tizen_log.dart';
import 'package:tuple/tuple.dart';

const String kLogTag = 'TizenInteropCallbacksExample';

class PreviewResolutionsTab extends StatefulWidget {
  const PreviewResolutionsTab({super.key});

  @override
  State<StatefulWidget> createState() => PreviewResolutionsState();
}

class PreviewResolutionsState extends State<PreviewResolutionsTab> {
  List<String> _list = [];
  bool _loading = false;

  @override
  Widget build(BuildContext context) {
    if (_loading) {
      return const Text('Loading...');
    } else if (_list.isEmpty) {
      return TextButton(onPressed: load, child: const Text('Click to load'));
    } else {
      return Column(children: [
        const Text('Resolutions:'),
        for (var item in _list) Text(item)
      ]);
    }
  }

  void load() async {
    setState(() {
      _loading = true;
    });
    final retriever = _PreviewResolutionsRetriever();
    final resolutions = await retriever.getResolutions();
    setState(() {
      _loading = false;
      _list = resolutions;
    });
  }
}

typedef InitMessage = Tuple2<SendPort,
    RegisteredCallback<Bool Function(Int, Int, Pointer<Void>)>>;

class _PreviewResolutionsRetriever {
  final List<String> _resolutions = [];

  Future<List<String>> getResolutions() async {
    final callbacks = TizenInteropCallbacks();
    // value to be automaticaly returned from callback in case of exception
    const exceptionalRetVal = false;
    final ReceivePort port = ReceivePort();

    final wrapper = callbacks.register<Bool Function(Int, Int, Pointer<Void>)>(
        'camera_supported_preview_resolution_cb',
        Pointer.fromFunction(_previewResolutionCallback, exceptionalRetVal),
        userObject: _resolutions);

    await Isolate.spawn(_getResolutions, InitMessage(port.sendPort, wrapper));
    await port.first;

    callbacks.unregister(wrapper);
    return _resolutions;
  }

  static void _getResolutions(InitMessage init) async {
    final sendPort = init.item1;
    final wrapper = init.item2;

    final cameraHandle = createCamera();
    final ret = tizen.camera_foreach_supported_preview_resolution(
        cameraHandle, wrapper.interopCallback, wrapper.interopUserData);
    if (ret != 0) {
      Log.error(kLogTag, 'Failed to query preview resolutions. [$ret]');
    }

    tizen.camera_destroy(cameraHandle);
    sendPort.send(null);
  }

  static bool _previewResolutionCallback(
      int width, int height, Pointer<Void> userData) {
    // ignore: avoid_print
    print('Got supported preview resolution:  $width $height');
    final List<String>? target = TizenInteropCallbacks.getUserObject(userData);
    target?.add('$width x $height');
    return true;
  }

  static Pointer<camera_cli_s> createCamera() {
    Pointer<camera_cli_s> cameraHandle = using((Arena arena) {
      Pointer<Pointer<camera_cli_s>> cameraHandlePointer = arena();
      final ret = tizen.camera_create(
          camera_device_e.CAMERA_DEVICE_CAMERA0, cameraHandlePointer);
      if (ret == 0) {
        return cameraHandlePointer.value;
      } else {
        Log.error(kLogTag, 'Failed to initialize camera. [$ret]');
        return Pointer<camera_cli_s>.fromAddress(0);
      }
    });
    return cameraHandle;
  }
}
