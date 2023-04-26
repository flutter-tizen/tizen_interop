// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:tizen_log/tizen_log.dart';

import 'battery.dart';
import 'preview_resolutions.dart';
import 'strings.dart';

void main() {
  Log.info(logTag, 'starting...');
  runApp(ChangeNotifierProvider<BatteryService>(
    child: const MyApp(),
    create: (_) => BatteryService(),
  ));
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: DefaultTabController(
        length: 2,
        child: Scaffold(
          body: const TabBarView(children: [
            BatteryTab(),
            PreviewResolutionsTab(),
          ]),
          appBar: AppBar(
            title: const Text(appTitle),
            bottom: const TabBar(tabs: [
              Tab(icon: Icon(Icons.battery_5_bar)),
              Tab(icon: Icon(Icons.camera)),
            ]),
          ),
        ),
      ),
    );
  }
}
