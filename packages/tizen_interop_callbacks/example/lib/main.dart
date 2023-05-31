// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'package:flutter/material.dart';

import 'battery.dart';
import 'preview_resolutions.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: DefaultTabController(
        length: 2,
        child: Scaffold(
          appBar: AppBar(
            title: const Text('Tizen Interop Callbacks Example'),
            bottom: const TabBar(tabs: [
              Tab(icon: Icon(Icons.battery_charging_full)),
              Tab(icon: Icon(Icons.camera)),
            ]),
          ),
          body: const TabBarView(children: [
            BatteryTab(),
            PreviewResolutionsTab(),
          ]),
        ),
      ),
    );
  }
}
