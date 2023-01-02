import 'dart:ffi';
import 'dart:isolate';
import 'package:ffi/ffi.dart';
import 'package:tizen_log/tizen_log.dart';

const String logTag = "TizenInteropCallbacksPlugin";

class CallbackWrapper extends Opaque {}

// ignore: camel_case_types
typedef run_cb_in_native_layer = Void Function(Pointer);

// ignore: camel_case_types
typedef register_send_port = Void Function(Int64);

class RegisteredCallback<DartCbType extends Function> {
  int id = -1;
  String nativeName = '';
  String platformCbName = '';
  int proxyId = -1;

  // The pointer that will be used in native callback setter/adder.
  Pointer<NativeFunction<DartCbType>> regCallbackPtr = nullptr;

  // User data pointer to be used in native callback setter/adder.
  Pointer<Void> regUserData = nullptr;
}

class TizenInteropCallbacks {
  final DynamicLibrary _process = DynamicLibrary.process();
  late Pointer Function(int, Pointer, Pointer, Pointer) registerWrappedCallback;
  late Pointer Function(int) unregisterWrappedCallback;
  late bool Function(Pointer<Utf8>) platformProxyCallbackExists;
  late void Function(Pointer) runCallbackInNativeLayer;

  int curCallbackId = 0;
  // ignore: non_constant_identifier_names
  final int PROXY_ID_COUNT = 5;
  var multiProxyIds = <String, List<bool>>{};

  void init() {
    Log.debug(logTag, 'listening to ReceivePort');
    final nativeCallbackCalls = ReceivePort()..listen(callbackCallRequested);

    Log.debug(logTag, 'setting nativePort');
    final int nativePort = nativeCallbackCalls.sendPort.nativePort;
    Log.debug(logTag, '    nativePort = $nativePort');

    Log.debug(logTag, 'looking up InitDartApiDL()');
    final initApi = _process
        .lookup<NativeFunction<Pointer Function(Pointer)>>('InitDartApiDL')
        .asFunction<Pointer Function(Pointer)>();
    Log.debug(logTag, 'calling initApi()');
    initApi(NativeApi.initializeApiDLData);

    Log.debug(logTag, 'looking up RegisterSendPort()');
    final void Function(int) registerSendPort = _process
        .lookup<NativeFunction<register_send_port>>("RegisterSendPort")
        .asFunction();
    Log.debug(logTag, 'calling registerSendPort()');
    registerSendPort(nativePort);

    Log.debug(logTag, 'looking up RunCallbackInNativeLayer()');
    runCallbackInNativeLayer = _process
        .lookup<NativeFunction<run_cb_in_native_layer>>(
            "RunCallbackInNativeLayer")
        .asFunction();

    Log.debug(logTag, 'looking up RegisterWrappedCallbackInNativeLayer()');
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
        .lookup<
            NativeFunction<
                Pointer Function(Int32, Pointer, Pointer,
                    Pointer)>>('RegisterWrappedCallbackInNativeLayer')
        .asFunction();

    Log.debug(logTag, 'looking up UnregisterWrappedCallbackInNativeLayer()');
    unregisterWrappedCallback = _process
        .lookup<NativeFunction<Pointer Function(Int32)>>(
            'UnregisterWrappedCallbackInNativeLayer')
        .asFunction();

    Log.debug(logTag, 'looking up TizenInteropCallbacksProxyExists()');
    platformProxyCallbackExists = _process
        .lookup<NativeFunction<Bool Function(Pointer<Utf8>)>>(
            'TizenInteropCallbacksProxyExists')
        .asFunction();
  }

  void callbackCallRequested(dynamic message) {
    Log.debug(logTag, 'in callbackCallRequested()');
    int callbackPtr = message;
    final callback = Pointer<CallbackWrapper>.fromAddress(callbackPtr);
    Log.debug(logTag, 'calling runCallbackInNativeLayer()');
    runCallbackInNativeLayer(callback);
    Log.debug(logTag, 'after calling runCallbackInNativeLayer()');
  }

  int getFirstFreeId(List<bool> list) {
    return list.indexWhere((bool elem) => elem == false);
  }

  RegisteredCallback<DartCbType> register<DartCbType extends Function>(
      String nativeName, Pointer<NativeFunction<DartCbType>> dartCallback,
      [Pointer<Void>? userData, bool? blocking]) {
    Log.debug(logTag, 'looking up platform callback');

    String platformCbName = '';
    blocking ??= !platformProxyCallbackExists(
        'platform_non_blocking_${nativeName}_0'.toNativeUtf8());
    if (blocking) {
      platformCbName = 'platform_blocking_$nativeName';
    } else {
      platformCbName = 'platform_non_blocking_$nativeName';
    }

    if (!multiProxyIds.containsKey(platformCbName)) {
      Log.debug(logTag, 'adding new list for platformCbName $platformCbName');
      multiProxyIds[platformCbName] = List<bool>.filled(PROXY_ID_COUNT, false);
    }

    int freeProxyId = getFirstFreeId(multiProxyIds[platformCbName]!);
    if (freeProxyId == -1) {
      Log.error(logTag, 'no free proxy ids for $platformCbName');
      throw Exception('Exhausted pool of $platformCbName proxies.');
    }
    Log.debug(
        logTag, 'setting proxy id $freeProxyId for cb $platformCbName as used');
    multiProxyIds[platformCbName]![freeProxyId] = true;
    String platformCbWithIdx = '${platformCbName}_$freeProxyId';
    Pointer<Utf8> platformCbNamePtr = platformCbWithIdx.toNativeUtf8();

    int newId = curCallbackId++;
    Pointer<NativeFunction<DartCbType>> platformCallback = nullptr;

    Log.debug(logTag,
        'calling registerWrappedCallback(), cb=${dartCallback.address.toRadixString(16)}');
    platformCallback = registerWrappedCallback(
            newId,
            dartCallback,
            // Note that this is the actual user data that the user wants
            // associated with the callback, not the user data modified by us.
            userData ?? nullptr,
            platformCbNamePtr)
        .cast<NativeFunction<DartCbType>>();
    Log.debug(logTag,
        'after calling registerWrappedCallback(), pcb=${platformCallback.address.toRadixString(16)} ');

    malloc.free(platformCbNamePtr);

    RegisteredCallback<DartCbType> regCb = RegisteredCallback<DartCbType>();
    regCb.id = newId;
    regCb.platformCbName = platformCbName;
    regCb.proxyId = freeProxyId;
    regCb.regCallbackPtr = platformCallback;
    regCb.regUserData = Pointer.fromAddress(newId);
    return regCb;
  }

  void unregister<DartCbType extends Function>(
      RegisteredCallback<DartCbType> regCb) {
    String platformCbName = regCb.platformCbName;
    int proxyId = regCb.proxyId;

    if (multiProxyIds[platformCbName]![proxyId] == false) {
      Log.debug(
          logTag, 'tried to remove proxy $proxyId for cb $platformCbName');
    } else {
      Log.debug(logTag,
          'setting proxy id $proxyId for cb $platformCbName as available');
      multiProxyIds[platformCbName]![proxyId] = false;
    }

    Log.debug(logTag, 'calling unregisterWrappedCallback()');
    unregisterWrappedCallback(regCb.id);
    Log.debug(logTag, 'after calling unregisterWrappedCallback()');
    // consider returning success/error
  }
}
