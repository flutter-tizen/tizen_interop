import 'dart:ffi';

import 'package:ffi/ffi.dart';
import 'package:flutter/material.dart';
import 'package:tizen_interop/4.0/tizen.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  String _appName = '';
  int _preferenceValue = 0;
  int _freeMemory = 0;

  @override
  void initState() {
    super.initState();

    // Getting a string value from the Native API.
    // Prefer using `arena` to allocate memory because it frees the memory
    // automatically when the `using` block ends.
    _appName = using((Arena arena) {
      Pointer<Pointer<Char>> ppStr = arena();
      if (tizen.app_get_name(ppStr) == 0) {
        // The memory allocated by the Native API must be freed by the caller.
        arena.using(ppStr.value, calloc.free);
        return ppStr.value.toDartString();
      }
      return 'unknown';
    });

    // Passing a string value to the Native API.
    // The memory allocated by the `toNativeChar` method must be freed by
    // the caller. The `arena` allocator will free it automatically.
    using((Arena arena) {
      Pointer<Char> pKey =
          'tizen_interop_test_key_for_int'.toNativeChar(allocator: arena);
      tizen.preference_set_int(pKey, 100);
    });

    // Getting an integer value from the Native API.
    _preferenceValue = using((Arena arena) {
      Pointer<Char> pKey =
          'tizen_interop_test_key_for_int'.toNativeChar(allocator: arena);
      Pointer<Int> pValue = arena();
      if (tizen.preference_get_int(pKey, pValue) == 0) {
        return pValue.value;
      }
      return 0;
    });

    // Getting a struct value from the Native API.
    _freeMemory = using((Arena arena) {
      Pointer<runtime_memory_info_s> pMemInfo = arena();
      if (tizen.runtime_info_get_system_memory_info(pMemInfo) == 0) {
        return pMemInfo.ref.free;
      }
      return 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text('app_get_name() = $_appName'),
            Text('preference_get_int() = $_preferenceValue'),
            Text('Free Memory = $_freeMemory'),
          ],
        ),
      ),
    );
  }
}
