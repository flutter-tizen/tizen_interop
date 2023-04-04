import 'dart:ffi';
import 'dart:isolate';
import 'package:ffi/ffi.dart';
import 'package:tizen_log/tizen_log.dart';

/// Log entries will be tagger with this tag.
const String _logTag = 'TizenInteropCallbacksPlugin';

/// Opaque type representing a wrapper function pointer.
class _CallbackWrapper extends Opaque {}

//const _logDebug = Log.debug;
void _logDebug(String tag, String message) {}

/// Class for storing data about registered callback.
///
/// Obtained by calling [TizenInteropCallbacks.register()].
/// Then [interopCallback] and [interopUserData] should be passed to native API
/// callback setup.
class RegisteredCallback<NativeCbType extends Function> {
  /// Unique identifier of the callback instance.
  final int id;

  /// Name of the callback defined in Tizen Native API.
  final String callbackName;

  /// Name of the proxy callback. [callbackName] prefixed with
  /// `platform_blocking_` or `platform_non_blocking_`.
  final String platformCallbackName;

  /// Index identifying which of multiple proxies is used for this registered callback.
  final int proxyId;

  /// The pointer that will be used in native callback setter/adder.
  Pointer<NativeFunction<NativeCbType>> get interopCallback =>
      Pointer.fromAddress(_proxyCallback);
  final int _proxyCallback;

  /// User data pointer to be used in native callback setter/adder.
  Pointer<Void> get interopUserData => Pointer.fromAddress(id);

  /// See [RegisteredCallback] class members documentation.
  RegisteredCallback._(this.id, this.callbackName, this.platformCallbackName,
      this.proxyId, Pointer<NativeFunction<NativeCbType>> interopCallback)
      : _proxyCallback = interopCallback.address;
}

/// Class which manages wrappers and registration of callbacks.
///
/// This class must be instantiated only once. Preferrably in the root isolate, because
/// the callbacks will be executed in the thread used for initialization and will have access to object in that isolate.
///
/// There purpose of this class is to solve the issue related to error message:
/// `Cannot invoke native callback outside an isolate.` If you are not
/// receiving such error message, that means you don't need this class.
///
/// Before your callback can be called by some Tizen Native API modules,
/// you should register it and pass [RegisteredCallback.interopCallback]
/// and [RegisteredCallback.interopUserData] you will receive to Native API:
/// ``` dart
/// var levelCb = callbacks.register<
///       Void Function(Int32, Pointer<Void>, Pointer<Void>)
///     >('device_changed_cb', Pointer.fromFunction(_batteryChanged));
/// tizen.device_add_callback(2, levelCb.interopCallback, levelCb.interopUserData);
/// ```
/// See [register()] for additional information.
class TizenInteropCallbacks {
  final DynamicLibrary _process = DynamicLibrary.process();
  late final _RegistrationResult Function(Pointer, Pointer, int)
      _registerWrappedCallback;
  late final void Function(int) _unregisterWrappedCallback;
  late final bool Function(Pointer<Utf8>) _platformProxyCallbackExists;
  late final void Function(Pointer) _runCallbackInNativeLayer;

  static TizenInteropCallbacks? _instance;
  static final Map<int, Object> _userObjectStore = {};
  static final Object nullUserObjectMarker = Object();

  late final int _proxyIdCount;
  final _multiProxyIds = <String, List<bool>>{};

  /// Factory constructor provides an instance of [TizenInteropCallbacks].
  ///
  /// First access to this TizenInteropCallbacks instance should be performed
  /// from the main isolate - the one with your main() entry point / runApp() call.
  ///
  /// Subsequent calls will return the same instance.
  factory TizenInteropCallbacks() {
    _instance ??= TizenInteropCallbacks._internal();
    return _instance!;
  }

  TizenInteropCallbacks._internal() {
    final nativeCallbackCalls = ReceivePort()..listen(_callbackCallRequested);

    final int nativePort = nativeCallbackCalls.sendPort.nativePort;
    _logDebug(_logTag, 'listening to ReceivePort');

    _proxyIdCount = _process
        .lookup<Int32>('TizenInteropCallbacksProxyInstancesCount')
        .value;
    Log.debug(_logTag,
        'Initializing TizenInteropCallbacks, proxy instances count: $_proxyIdCount');

    final int Function(int) registerSendPort = _process
        .lookup<NativeFunction<Int32 Function(Int64)>>(
            'TizenInteropCallbacksRegisterSendPort')
        .asFunction();
    _logDebug(_logTag, 'calling registerSendPort()');
    final res = registerSendPort(nativePort);
    if (res == 1) {
      throw Exception(
          'TizenInteropCallbacks already initialized in another Isolate.');
    }

    final initApi = _process
        .lookup<NativeFunction<Pointer Function(Pointer)>>(
            'TizenInteropCallbacksInitDartApiDL')
        .asFunction<Pointer Function(Pointer)>();
    _logDebug(_logTag, 'calling initApi()');
    initApi(NativeApi.initializeApiDLData);

    _runCallbackInNativeLayer = _process
        .lookup<NativeFunction<Void Function(Pointer)>>(
            'TizenInteropCallbacksRunCallback')
        .asFunction();

    /*
       About template parameter for lookup<NativeFunction<...>>:
       Pointer Function(Int32, Pointer, Pointer, Pointer):
       Pointer   - returned pointer to multi proxy callback, cast to void*
       Function(
       Pointer,  - pointer to Dart callback
       Pointer,  - pointer to name of multi proxy callback,
                   allocated in Dart layer by toNativeUtf8() and freed by malloc.free,
                   const char * in C++ layer
       Int32     - proxy num
       )
    */
    _registerWrappedCallback = _process
        .lookup<
            NativeFunction<
                _RegistrationResult Function(Pointer, Pointer,
                    Int32)>>('TizenInteropCallbacksRegisterWrappedCallback')
        .asFunction();

    _unregisterWrappedCallback = _process
        .lookup<NativeFunction<Void Function(Uint32)>>(
            'TizenInteropCallbacksUnregisterWrappedCallback')
        .asFunction();

    _platformProxyCallbackExists = _process
        .lookup<NativeFunction<Bool Function(Pointer<Utf8>)>>(
            'TizenInteropCallbacksProxyExists')
        .asFunction();
  }

  void _callbackCallRequested(dynamic message) {
    int callbackPtr = message;
    final callback = Pointer<_CallbackWrapper>.fromAddress(callbackPtr);
    _logDebug(_logTag,
        'calling native runCallback(), cb=${callback.address.toRadixString(16)}');
    _runCallbackInNativeLayer(callback);
    _logDebug(_logTag, 'after calling native runCallback()');
  }

  int _getFirstFreeId(List<bool> list) {
    return list.indexWhere((bool elem) => elem == false);
  }

  /// Registers a callbacks and returns wrapper/proxy data to be used
  /// in Native API calls.
  ///
  /// To specify signature of wrapper callbacks, the name of Native API callback
  /// defined in header file (such as `"device_changed_cb"`) must be provided
  /// as [callbackName] parameter.
  ///
  /// [Pointer.fromFunction()] can be used to convert a Dart callback to ffi
  /// pointer which is passed as [callback] parameter.
  /// The requirements of fromFunction() applies - the function needs
  /// to be static of free function. If the functions returns something, a fallback
  /// return value needs to be specifed - a value which will be used in case
  /// the Dart code invocation throws an exception.
  ///
  /// [NativeCbType] must match the signature of the Native API callback.
  /// Proper type can be found in the relevant generated_binding.dart file,
  /// look for the typedef for the callback.
  /// The match is verified when [RegisteredCallback.interopCallback] is passed
  /// to Native API.
  ///
  /// Most Tizen Native API callbacks offer passing arbitrary data
  /// (in form of `void*`), known as `user_data`.
  /// You can provide [userObject] and then, inside your callback,
  /// use [TizenInteropCallbacks.getUserObject(userData)] with the
  /// obtained `user_data` value to retrieve the object back.
  /// If neither is given, the `0`/`nullptr` will be passed.
  ///
  /// The system chooses non blocking callback if possible - i.e. blocking will be
  /// used for callbacks which has to return something. You can override that
  /// behaviour by setting [blocking].
  /// Note that using blocking callback will block the thread the native module
  /// will call the callback. In some cases, Native API invocation must be
  /// performed in separate thread/isolate.
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
      String callbackName, Pointer<NativeFunction<NativeCbType>> callback,
      {Object? userObject, bool? blocking}) {
    _logDebug(_logTag, 'looking up platform callback');

    String platformCbName = '';
    blocking ??= !_platformProxyCallbackExists(
        'platform_non_blocking_$callbackName'.toNativeUtf8());
    if (blocking) {
      platformCbName = 'platform_blocking_$callbackName';
    } else {
      platformCbName = 'platform_non_blocking_$callbackName';
    }

    if (!_multiProxyIds.containsKey(platformCbName)) {
      _logDebug(_logTag, 'adding new list for platformCbName $platformCbName');
      _multiProxyIds[platformCbName] = List<bool>.filled(_proxyIdCount, false);
    }

    int freeProxyId = _getFirstFreeId(_multiProxyIds[platformCbName]!);
    if (freeProxyId == -1) {
      Log.error(_logTag, 'no free proxy ids for $platformCbName');
      throw Exception('Exhausted pool of $platformCbName proxies.');
    }
    _logDebug(_logTag,
        'setting proxy id $freeProxyId for cb $platformCbName as used');
    _multiProxyIds[platformCbName]![freeProxyId] = true;
    Pointer<Utf8> platformCbNamePtr = platformCbName.toNativeUtf8();

    _logDebug(_logTag,
        'calling registerWrappedCallback(), cb=${callback.address.toRadixString(16)}');
    final result =
        _registerWrappedCallback(callback, platformCbNamePtr, freeProxyId);
    malloc.free(platformCbNamePtr);

    final Pointer<NativeFunction<NativeCbType>> platformCallback =
        result.callback.cast();
    _logDebug(_logTag,
        'after calling registerWrappedCallback(), pcb=${platformCallback.address.toRadixString(16)} ');
    if (platformCallback == nullptr) {
      throw Exception('Failed to register callback.');
    }

    _logDebug(_logTag, 'Saving userObjectStore[${result.id}] = $userObject');
    _userObjectStore[result.id] = userObject ?? nullUserObjectMarker;

    RegisteredCallback<NativeCbType> regCb = RegisteredCallback<NativeCbType>._(
        result.id, callbackName, platformCbName, freeProxyId, platformCallback);
    return regCb;
  }

  /// Cleans the data and registration related to passed [registeredCallback].
  void unregister(RegisteredCallback registeredCallback) {
    String platformCbName = registeredCallback.platformCallbackName;
    int proxyId = registeredCallback.proxyId;

    if (_multiProxyIds[platformCbName]![proxyId] == false) {
      Log.warn(_logTag,
          'Tried to remove non-existend proxy $proxyId for callback $platformCbName');
    } else {
      _multiProxyIds[platformCbName]![proxyId] = false;
    }
    _userObjectStore.remove(registeredCallback.id);
    _unregisterWrappedCallback(registeredCallback.id);
  }

  /// Retrieves an object passed as `userObject` to [register()].
  ///
  /// When `userObject` is used with [register()], that object is stored
  /// internally and `interopUserData` property of the returned [RegisteredCallback]
  /// holds the key to that object. The `user_data` received by callback should
  /// be passed to `getUserObject()` to retrieve the stored object.
  ///
  /// `null` is returned if there is no object under the given [userData].
  ///
  /// ``` dart
  /// static void _batteryChanged(int type,
  ///                             Pointer<Void> val,
  ///                             Pointer<Void> userData) {
  ///   MyClass? object = TizenInteropCallbacks.getUserObject(userData);
  /// }
  ///
  /// MyClass anObject;
  /// var levelCallback = callbacks.register(
  ///     'device_changed_cb', Pointer.fromFunction(_batteryChanged),
  ///     userObject: anOject);
  /// ```
  ///
  /// Keep in mind that this is not intended for transfering objects across threads.
  /// You should access the TizenInteropCallbacks from a single isolate only.
  static T? getUserObject<T extends Object>(Pointer<Void> userData) {
    if (_userObjectStore.containsKey(userData.address)) {
      var object = _userObjectStore[userData.address];
      if (identical(object, nullUserObjectMarker)) object = null;
      _logDebug(_logTag, 'getting from store ${userData.address} -> $object');
      return object as T?;
    } else {
      Log.warn(_logTag,
          'getUserObject(): key ${userData.address} not found, returning null');
      return null;
    }
  }
}

class _RegistrationResult extends Struct {
  /// The native proxy callback to be used with Native API
  external Pointer callback;

  /// The registration ID
  @Uint32()
  external int id;
}
