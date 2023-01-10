import 'dart:ffi';
import 'dart:isolate';
import 'package:ffi/ffi.dart';
import 'package:tizen_log/tizen_log.dart';

/// Log entries will be tagger with this tag.
const String logTag = "TizenInteropCallbacksPlugin";

/// Opaque type representing a wrapper function pointer.
/// Used internally.
class CallbackWrapper extends Opaque {}

/// Class for storing data about registered callback.
///
/// Obtained by calling [TizenInteropCallbacks.register()].
/// Then [regCallbackPtr] and [regUserData] should be passed to native API
/// callback setup.
class RegisteredCallback<NativeCbType extends Function> {
  /// Unique identifier of the callback instance.
  final int id;

  /// Name of the Native API callback.
  final String nativeName;

  /// Name of the proxy callback. [nativeName] prefixed with
  /// `platform_blocking_` or `platform_non_blocking_`.
  final String platformCbName;

  /// Index identifying which of multiple proxies is used for this registered callback.
  final int proxyId;

  /// The pointer that will be used in native callback setter/adder.
  final Pointer<NativeFunction<NativeCbType>> regCallbackPtr;

  /// User data pointer to be used in native callback setter/adder.
  final Pointer<Void> regUserData;

  /// See [RegisteredCallback] class members documentation.
  RegisteredCallback(this.id, this.nativeName, this.platformCbName,
      this.proxyId, this.regCallbackPtr, this.regUserData);
}

/// Class which manages wrappers and registration of callbacks.
///
/// This class should be instantiated only once, on the main thread of
/// the main isolate - the one with your main() entry point / runApp() call.
///
/// There purpose of this class is to solve the issue related to error message:
/// `Cannot invoke native callback outside an isolate.` If you are not
/// receiving such error message, that means you don't need this class.
///
/// Before your callback can be called by some Tizen Native API modules,
/// you should register it and pass [RegisteredCallback.regCallbackPtr]
/// and [RegisteredCallback.regUserData] you will receive to Native API:
/// ``` dart
/// var levelCb = callbacks.register<
///       Void Function(Int32, Pointer<Void>, Pointer<Void>)
///     >('device_changed_cb', Pointer.fromFunction(_batteryChanged));
/// tizen.device_add_callback(2, levelCb.regCallbackPtr, levelCb.regUserData);
/// ```
/// See [register()] for additional information.
class TizenInteropCallbacks {
  final DynamicLibrary _process = DynamicLibrary.process();
  late Pointer Function(int, Pointer, Pointer, Pointer, int)
      _registerWrappedCallback;
  late Pointer Function(int) _unregisterWrappedCallback;
  late bool Function(Pointer<Utf8>) _platformProxyCallbackExists;
  late void Function(Pointer) _runCallbackInNativeLayer;
  static TizenInteropCallbacks? _instance;

  int _curCallbackId = 0;
  late final int _proxyIdCount;
  final _multiProxyIds = <String, List<bool>>{};

  /// Initializes the [TizenInteropCallbacks].
  ///
  /// This class should be instantiated only once, on the main thread of
  /// the main isolate - the one with your main() entry point / runApp() call.
  TizenInteropCallbacks() {
    if (_instance != null) {
      throw Exception(
          'There should be only one instance of TizenInteropCallbacks.');
    }
    _instance = this;
    Log.debug(logTag, 'listening to ReceivePort');
    final nativeCallbackCalls = ReceivePort()..listen(_callbackCallRequested);

    Log.debug(logTag, 'setting nativePort');
    final int nativePort = nativeCallbackCalls.sendPort.nativePort;
    Log.debug(logTag, '    nativePort = $nativePort');

    _proxyIdCount = _process
        .lookup<Int32>('TizenInteropCallbacksProxyInstancesCount')
        .value;
    Log.debug(logTag, 'proxy instances count: $_proxyIdCount');

    Log.debug(logTag, 'looking up InitDartApiDL()');
    final initApi = _process
        .lookup<NativeFunction<Pointer Function(Pointer)>>(
            'TizenInteropCallbacksInitDartApiDL')
        .asFunction<Pointer Function(Pointer)>();
    Log.debug(logTag, 'calling initApi()');
    initApi(NativeApi.initializeApiDLData);

    Log.debug(logTag, 'looking up RegisterSendPort()');
    final void Function(int) registerSendPort = _process
        .lookup<NativeFunction<Void Function(Int64)>>(
            "TizenInteropCallbacksRegisterSendPort")
        .asFunction();
    Log.debug(logTag, 'calling registerSendPort()');
    registerSendPort(nativePort);

    Log.debug(logTag, 'looking up RunCallbackInNativeLayer()');
    _runCallbackInNativeLayer = _process
        .lookup<NativeFunction<Void Function(Pointer)>>(
            "TizenInteropCallbacksRunCallbackInNativeLayer")
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
    _registerWrappedCallback = _process
        .lookup<
                NativeFunction<
                    Pointer Function(Int32, Pointer, Pointer, Pointer, Int32)>>(
            'TizenInteropCallbacksRegisterWrappedCallbackInNativeLayer')
        .asFunction();

    Log.debug(logTag, 'looking up UnregisterWrappedCallbackInNativeLayer()');
    _unregisterWrappedCallback = _process
        .lookup<NativeFunction<Pointer Function(Int32)>>(
            'TizenInteropCallbacksUnregisterWrappedCallbackInNativeLayer')
        .asFunction();

    Log.debug(logTag, 'looking up TizenInteropCallbacksProxyExists()');
    _platformProxyCallbackExists = _process
        .lookup<NativeFunction<Bool Function(Pointer<Utf8>)>>(
            'TizenInteropCallbacksProxyExists')
        .asFunction();
  }

  void _callbackCallRequested(dynamic message) {
    Log.debug(logTag, 'in callbackCallRequested()');
    int callbackPtr = message;
    final callback = Pointer<CallbackWrapper>.fromAddress(callbackPtr);
    Log.debug(logTag, 'calling runCallbackInNativeLayer()');
    _runCallbackInNativeLayer(callback);
    Log.debug(logTag, 'after calling runCallbackInNativeLayer()');
  }

  int _getFirstFreeId(List<bool> list) {
    return list.indexWhere((bool elem) => elem == false);
  }

  /// Registers a callbacks and returns wrapper/proxy data to be used
  /// in Native API calls.
  ///
  /// @nativeName - a Native API callback named as defined in header file,
  /// for example `device_changed_cb`.
  ///
  /// @callback - a ffi pointer to your Dart callback. The signature must match
  /// the @NativeCbType i.e. [NativeCbType] must describe a native version of the
  /// @callback type.
  /// [Pointer.fromFunction()] is used to convert a Dart callback to ffi
  /// pointer. The requirements of fromFunction() applies - the function needs
  /// to be static of free function. If the functions returns something, a fallback
  /// return value needs to be specifed - a value which will be used in case
  /// the Dart code invocation throws an exception.
  ///
  /// [NativeCbType] must match the signature of the Native API callback.
  /// Proper type can be found in the relevant generated_binding.dart file,
  /// look for the typedef for the callback.
  ///
  /// @userData - most Tizen Native API callbacks offer passing arbitrary data
  /// (in form of `void*`). The value you specify here will be passed to your
  /// Dart callback as `user_data` parameter (if callback has such parameter).
  /// If not given, the `0`/`nullptr` will be passed.
  ///
  /// @blocking - whether to use blocking callback. If you don't specify this,
  /// the system will choose non blocking if possible - i.e. blocking will be
  /// used for callbacks which has to return something.
  /// Note that using blocking callback will block the thread the native module
  /// will call the callback. In some cases, Native API invocation must be perform
  /// in separate thread/isolate.
  ///
  /// ``` dart
  /// static void _batteryChanged(int type,
  ///                             Pointer<Void> val,
  ///                             Pointer<Void> userData) { }
  ///
  /// var levelCb = callbacks.register<
  ///       Void Function(Int32, Pointer<Void>, Pointer<Void>)
  ///     >('device_changed_cb', Pointer.fromFunction(_batteryChanged));
  /// ```
  RegisteredCallback<NativeCbType> register<NativeCbType extends Function>(
      String nativeName, Pointer<NativeFunction<NativeCbType>> callback,
      [Pointer<Void>? userData, bool? blocking]) {
    Log.debug(logTag, 'looking up platform callback');

    String platformCbName = '';
    blocking ??= !_platformProxyCallbackExists(
        'platform_non_blocking_$nativeName'.toNativeUtf8());
    if (blocking) {
      platformCbName = 'platform_blocking_$nativeName';
    } else {
      platformCbName = 'platform_non_blocking_$nativeName';
    }

    if (!_multiProxyIds.containsKey(platformCbName)) {
      Log.debug(logTag, 'adding new list for platformCbName $platformCbName');
      _multiProxyIds[platformCbName] = List<bool>.filled(_proxyIdCount, false);
    }

    int freeProxyId = _getFirstFreeId(_multiProxyIds[platformCbName]!);
    if (freeProxyId == -1) {
      Log.error(logTag, 'no free proxy ids for $platformCbName');
      throw Exception('Exhausted pool of $platformCbName proxies.');
    }
    Log.debug(
        logTag, 'setting proxy id $freeProxyId for cb $platformCbName as used');
    _multiProxyIds[platformCbName]![freeProxyId] = true;
    Pointer<Utf8> platformCbNamePtr = platformCbName.toNativeUtf8();

    int newId = _curCallbackId++;
    Pointer<NativeFunction<NativeCbType>> platformCallback = nullptr;

    Log.debug(logTag,
        'calling registerWrappedCallback(), cb=${callback.address.toRadixString(16)}');
    platformCallback = _registerWrappedCallback(
            newId,
            callback,
            // Note that this is the actual user data that the user wants
            // associated with the callback, not the user data modified by us.
            userData ?? nullptr,
            platformCbNamePtr,
            freeProxyId)
        .cast<NativeFunction<NativeCbType>>();
    Log.debug(logTag,
        'after calling registerWrappedCallback(), pcb=${platformCallback.address.toRadixString(16)} ');

    malloc.free(platformCbNamePtr);
    if (platformCallback == nullptr) {
      throw Exception('Failed to register callback.');
    }

    RegisteredCallback<NativeCbType> regCb = RegisteredCallback<NativeCbType>(
        newId,
        nativeName,
        platformCbName,
        freeProxyId,
        platformCallback,
        Pointer.fromAddress(newId));
    return regCb;
  }

  /// Cleans the data and registration related to passed [regCb].
  void unregister(RegisteredCallback regCb) {
    String platformCbName = regCb.platformCbName;
    int proxyId = regCb.proxyId;

    if (_multiProxyIds[platformCbName]![proxyId] == false) {
      Log.debug(
          logTag, 'tried to remove proxy $proxyId for cb $platformCbName');
    } else {
      Log.debug(logTag,
          'setting proxy id $proxyId for cb $platformCbName as available');
      _multiProxyIds[platformCbName]![proxyId] = false;
    }

    Log.debug(logTag, 'calling unregisterWrappedCallback()');
    _unregisterWrappedCallback(regCb.id);
    Log.debug(logTag, 'after calling unregisterWrappedCallback()');
    // consider returning success/error
  }
}
