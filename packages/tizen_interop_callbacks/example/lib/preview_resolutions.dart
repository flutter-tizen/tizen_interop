// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// ignore_for_file: public_member_api_docs, avoid_print

import 'dart:ffi';
import 'dart:isolate';

import 'package:ffi/ffi.dart';
import 'package:flutter/material.dart';
import 'package:tizen_interop/5.5/tizen.dart';
import 'package:tizen_interop_callbacks/tizen_interop_callbacks.dart';

class PreviewResolutionsTab extends StatefulWidget {
  const PreviewResolutionsTab({super.key});

  @override
  State<StatefulWidget> createState() => _PreviewResolutionsState();
}

class _PreviewResolutionsState extends State<PreviewResolutionsTab> {
  final List<String> _resolutions = [];

  @override
  void initState() {
    super.initState();

    getResolutions().then((_) => setState(() {}));
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        const Text('Preview resolutions:'),
        if (_resolutions.isEmpty)
          const Text('None')
        else
          for (final resolution in _resolutions) Text(resolution)
      ],
    );
  }

  Future<void> getResolutions() async {
    final callbacks = TizenInteropCallbacks();
    final port = ReceivePort();

    final callback = callbacks.register<Bool Function(Int, Int, Pointer<Void>)>(
      'camera_supported_preview_resolution_cb',
      Pointer.fromFunction(_previewResolutionCallback, false),
      userObject: _resolutions,
    );

    await Isolate.spawn(_getResolutions, [port.sendPort, callback]);
    await port.first;

    callbacks.unregister(callback);
  }

  static void _getResolutions(List<Object> message) async {
    final sendPort = message[0] as SendPort;
    final callback = message[1]
        as RegisteredCallback<Bool Function(Int, Int, Pointer<Void>)>;

    final cameraHandle = using((Arena arena) {
      Pointer<camera_h> camera = arena();
      final ret =
          tizen.camera_create(camera_device_e.CAMERA_DEVICE_CAMERA0, camera);
      if (ret != 0) {
        final error = tizen.get_error_message(ret).toDartString();
        print('Failed to initialize camera: $error');
        return nullptr;
      }
      return camera.value;
    });

    if (cameraHandle != nullptr) {
      final ret = tizen.camera_foreach_supported_preview_resolution(
        cameraHandle,
        callback.interopCallback,
        callback.interopUserData,
      );
      if (ret != 0) {
        final error = tizen.get_error_message(ret).toDartString();
        print('Failed to query preview resolutions: $error');
      }

      tizen.camera_destroy(cameraHandle);
    }

    sendPort.send(null);
  }

  static bool _previewResolutionCallback(
    int width,
    int height,
    Pointer<Void> userData,
  ) {
    final resolutions =
        TizenInteropCallbacks.getUserObject<List<String>>(userData)!;
    resolutions.add('$width x $height');
    return true;
  }
}
