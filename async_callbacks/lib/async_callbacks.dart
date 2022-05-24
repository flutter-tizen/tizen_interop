import 'dart:async';
import 'dart:ffi';
import 'dart:isolate';

import 'package:flutter/services.dart';
import 'package:tizen_log/tizen_log.dart';
import 'package:ffi/ffi.dart';

//import 'package:tizen_interop/6.0/tizen.dart';

class CallbackWrapper extends Opaque {
}

typedef run_cb_in_native_layer = Void Function(Pointer);

typedef register_send_port = Void Function(Int64);

class RegisteredCallback<DartCbType extends Function> {
  int id = -1;
  String nativeName = '';
  String platformCbName = '';
  int proxyId = -1;
  bool blocking = false;    // TODO not needed?

  // The pointer that will be used in native callback setter/adder.
  Pointer<NativeFunction<DartCbType>> regCallbackPtr = nullptr;

  // User data pointer to be used in native callback setter/adder.
  Pointer<Void> regUserData = nullptr;
}

class AsyncCallbacks {
  static const MethodChannel _channel = MethodChannel('async_callbacks');
  DynamicLibrary _process = DynamicLibrary.process();
  late Pointer Function(int, Pointer, Pointer, Pointer) registerWrappedCallback;
  late Pointer Function(int) unregisterWrappedCallback;
  late void Function(Pointer) runCallbackInNativeLayer;

  int curCallbackId = 0;
  final int PROXY_ID_COUNT = 5;
  var multiProxyIds = Map<String, List<bool>>();

  static Future<String?> get platformVersion async {
    final String? version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }

  void init() {
    Log.debug('ConsoleMessage', 'listening to ReceivePort');
    final nativeCallbackCalls = ReceivePort()..listen(callbackCallRequested);

    Log.debug('ConsoleMessage', 'setting nativePort');
    final int nativePort = nativeCallbackCalls.sendPort.nativePort;
    Log.debug('ConsoleMessage', '    nativePort = $nativePort');

    Log.debug('ConsoleMessage', 'looking up InitDartApiDL()');
    final initApi = _process
        .lookup<NativeFunction<Pointer Function(Pointer)>>('InitDartApiDL')
        .asFunction<Pointer Function(Pointer)>();
    Log.debug('ConsoleMessage', 'calling initApi()');
    initApi(NativeApi.initializeApiDLData);

    Log.debug('ConsoleMessage', 'looking up RegisterSendPort()');
    final void Function(int) registerSendPort = _process
        .lookup<NativeFunction<register_send_port>>("RegisterSendPort")
        .asFunction();
    Log.debug('ConsoleMessage', 'calling registerSendPort()');
    registerSendPort(nativePort);

    Log.debug('ConsoleMessage', 'looking up RunCallbackInNativeLayer()');
    runCallbackInNativeLayer = _process
      .lookup<NativeFunction<run_cb_in_native_layer>>("RunCallbackInNativeLayer")
      .asFunction();

    Log.debug('ConsoleMessage', 'looking up RegisterWrappedCallbackInNativeLayer()');
    /*
       About template parameter for lookup<NativeFunction<...>>:
       Pointer Function(Int32, Pointer, Pointer, Pointer):
       Pointer   - returned pointer to multi proxy callback, cast to void*
       Function(
       Int32,    - callback id
       Pointer,  - pointer to Dart callback
       Pointer,  - user data for Dart callback
       Pointer   - pointer to name of multi proxy callback,
                   allocated in Dart layer by toNativeUtf8() and freed by malloc.free,
                   const char * in C++ layer
       )
    */
    registerWrappedCallback = _process
      .lookup<NativeFunction<Pointer Function(Int32, Pointer, Pointer, Pointer)>>
        ('RegisterWrappedCallbackInNativeLayer')
      .asFunction();

    Log.debug('ConsoleMessage', 'looking up UnregisterWrappedCallbackInNativeLayer()');
    unregisterWrappedCallback = _process
      .lookup<NativeFunction<Pointer Function(Int32)>>
        ('UnregisterWrappedCallbackInNativeLayer')
      .asFunction();
  }

  void callbackCallRequested(dynamic message) {
    Log.debug('ConsoleMessage', 'in callbackCallRequested()');
    int callback_ptr = message;
    final callback = Pointer<CallbackWrapper>.fromAddress(callback_ptr);
    Log.debug('ConsoleMessage', 'calling runCallbackInNativeLayer()');
    runCallbackInNativeLayer(callback);
    Log.debug('ConsoleMessage', 'after calling runCallbackInNativeLayer()');
  }

  int getFirstFreeId(List<bool> list) {
    return list.indexWhere((bool elem) => elem == false);
  }

  RegisteredCallback<DartCbType> register<DartCbType extends Function>
        (String nativeName,
         Pointer<NativeFunction<DartCbType>> dartCallback,
         Pointer<Void> userData,
         bool blocking
         ) {
    Log.debug('ConsoleMessage', 'looking up platform callback');

    String platformCbName = '';
    if (blocking) {
      platformCbName = 'platform_blocking_$nativeName';
    } else {
      platformCbName = 'platform_non_blocking_$nativeName';
    }

    if (!multiProxyIds.containsKey(platformCbName)) {
      Log.debug('ConsoleMessage', 'adding new list for platformCbName ${platformCbName}');
      multiProxyIds[platformCbName] = List<bool>.filled(PROXY_ID_COUNT, false);
    }

    int freeProxyId = getFirstFreeId(multiProxyIds[platformCbName]!);
    if (freeProxyId == -1) {
      Log.debug('ConsoleMessage', 'no free proxy ids for ${platformCbName}');
      // Return an unusable object
      return RegisteredCallback<DartCbType>();
    }
    Log.debug('ConsoleMessage', 'setting proxy id ${freeProxyId} for cb ${platformCbName} as used');
    multiProxyIds[platformCbName]![freeProxyId] = true;
    String platformCbWithIdx = '${platformCbName}_${freeProxyId}';
    Pointer<Utf8> platformCbNamePtr = platformCbWithIdx.toNativeUtf8();

    int newId = curCallbackId++;
    Pointer<NativeFunction<DartCbType>> platformCallback = nullptr;

    Log.debug('ConsoleMessage', 'calling registerWrappedCallback()');
    platformCallback = registerWrappedCallback(
        newId,
        dartCallback,
        // Note that this is the actual user data that the user wants
        // associated with the callback, not the user data modified by us.
        userData,
        platformCbNamePtr
    ).cast<NativeFunction<DartCbType>>();
    Log.debug('ConsoleMessage', 'after calling registerWrappedCallback()');

    malloc.free(platformCbNamePtr);

    RegisteredCallback<DartCbType> regCb = RegisteredCallback<DartCbType>();
    regCb.id = newId;
    regCb.blocking = blocking;
    regCb.platformCbName = platformCbName;
    regCb.proxyId = freeProxyId;
    regCb.regCallbackPtr = platformCallback;
    regCb.regUserData = Pointer.fromAddress(newId);
    return regCb;
  }

  // TODO we probably want to return success/error
  void unregister<DartCbType extends Function>(RegisteredCallback<DartCbType> regCb) {
    String platformCbName = regCb.platformCbName;
    int proxyId = regCb.proxyId;

    if (multiProxyIds[platformCbName]![proxyId] == false) {
      Log.debug('ConsoleMessage', 'tried to remove proxy ${proxyId} for cb ${platformCbName}');
    } else {
      Log.debug('ConsoleMessage', 'setting proxy id ${proxyId} for cb ${platformCbName} as available');
      multiProxyIds[platformCbName]![proxyId] = false;
    }

    Log.debug('ConsoleMessage', 'calling unregisterWrappedCallback()');
    unregisterWrappedCallback(regCb.id);
    Log.debug('ConsoleMessage', 'after calling unregisterWrappedCallback()');
  }
}
