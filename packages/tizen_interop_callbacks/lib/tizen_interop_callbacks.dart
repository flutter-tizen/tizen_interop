// Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'dart:ffi';
import 'dart:isolate';

import 'package:ffi/ffi.dart';
import 'package:tizen_log/tizen_log.dart';

const int _kProxyInstanceCount = 5;
const String _kLogTag = 'TizenInteropCallbacksPlugin';

/// Opaque type representing a wrapper function pointer.
final class _CallbackWrapper extends Opaque {}

// const _logDebug = Log.debug;
void _logDebug(String tag, String message) {}

/// Class for storing data about registered callback.
///
/// Obtained by calling [TizenInteropCallbacks.register].
///
/// [interopCallback] and [interopUserData] should be passed as arguments to
/// Native API calls.
class RegisteredCallback<NativeCbType extends Function> {
  RegisteredCallback._(
    this.id,
    this.callbackName,
    this.platformCallbackName,
    this.proxyIndex,
    Pointer<NativeFunction<NativeCbType>> interopCallback,
  ) : _proxyCallback = interopCallback.address;

  /// Unique identifier of the callback instance.
  final int id;

  /// Name of the callback defined in Tizen Native API.
  final String callbackName;

  /// Name of the proxy callback. [callbackName] prefixed with either
  /// `platform_blocking_` or `platform_non_blocking_`.
  final String platformCallbackName;

  /// Index identifying which of multiple proxies is used for this registered
  /// callback.
  final int proxyIndex;

  /// The pointer that will be used in native callback setter/adder.
  Pointer<NativeFunction<NativeCbType>> get interopCallback =>
      Pointer.fromAddress(_proxyCallback);
  final int _proxyCallback;

  /// User data pointer to be used in native callback setter/adder.
  Pointer<Void> get interopUserData => Pointer.fromAddress(id);
}

/// Class which manages wrappers and registration of callbacks.
///
/// This class must be instantiated only once, preferrably in the root isolate,
/// because the callbacks will be executed in the thread used for initialization
/// and will have access to objects in that isolate.
///
/// The purpose of this class is to solve the issue related to error message:
/// `Cannot invoke native callback outside an isolate`. If you are not
/// receiving such an error message, that means you don't need this class.
///
/// Before your callback can be called by some Tizen Native API module,
/// you should register it and pass [RegisteredCallback.interopCallback]
/// and [RegisteredCallback.interopUserData] to the Native API:
///
/// ```dart
/// final batteryCallback =
///     _callbacks.register<Void Function(Int32, Pointer<Void>, Pointer<Void>)>(
///   'device_changed_cb',
///   Pointer.fromFunction(_batteryChanged),
///   userObject: userObject,
/// );
/// tizen.device_add_callback(
///   device_callback_e.DEVICE_CALLBACK_BATTERY_CAPACITY,
///   batteryCallback.interopCallback,
///   batteryCallback.interopUserData,
/// );
/// ```
///
/// See [register] for additional information.
class TizenInteropCallbacks {
  /// Returns an instance of [TizenInteropCallbacks].
  ///
  /// The first access to this [TizenInteropCallbacks] instance should be
  /// performed from the root isolate - the one with your `main` entry point
  /// and `runApp` call.
  ///
  /// Subsequent calls will return the same instance.
  factory TizenInteropCallbacks() {
    _instance ??= TizenInteropCallbacks._internal();
    return _instance!;
  }

  TizenInteropCallbacks._internal() {
    final nativeCallbackCalls = ReceivePort()..listen(_callbackCallRequested);

    final nativePort = nativeCallbackCalls.sendPort.nativePort;
    final registerSendPort = _process
        .lookup<NativeFunction<Int32 Function(Int64)>>(
            'TizenInteropCallbacksRegisterSendPort')
        .asFunction<int Function(int)>();
    _logDebug(_kLogTag, 'calling registerSendPort()');
    final res = registerSendPort(nativePort);
    if (res == 1) {
      throw Exception(
          'TizenInteropCallbacks already initialized in another isolate.');
    }

    final initApi = _process
        .lookup<NativeFunction<Pointer Function(Pointer)>>(
            'TizenInteropCallbacksInitDartApi')
        .asFunction<Pointer Function(Pointer)>();
    _logDebug(_kLogTag, 'calling initApi()');
    initApi(NativeApi.initializeApiDLData);

    _registerWrappedCallback = _process
        .lookup<
            NativeFunction<
                _RegistrationResult Function(Pointer, Pointer<Utf8>,
                    Int32)>>('TizenInteropCallbacksRegisterWrappedCallback')
        .asFunction();
    _unregisterWrappedCallback = _process
        .lookup<NativeFunction<Void Function(Uint32)>>(
            'TizenInteropCallbacksUnregisterWrappedCallback')
        .asFunction();
    _runCallbackNative = _process
        .lookup<NativeFunction<Void Function(Pointer)>>(
            'TizenInteropCallbacksRunCallback')
        .asFunction();
    _platformProxyExists = _process
        .lookup<NativeFunction<Bool Function(Pointer<Utf8>)>>(
            'TizenInteropCallbacksProxyExists')
        .asFunction();
  }

  static TizenInteropCallbacks? _instance;

  final DynamicLibrary _process = DynamicLibrary.process();

  // Input arguments:
  // - user_callback (Pointer): A pointer to the Dart callback.
  // - proxy_name (Pointer<Utf8>): A pointer to the name of multi proxy callback.
  // - proxy_num (int): A proxy index number.
  late final _RegistrationResult Function(Pointer, Pointer<Utf8>, int)
      _registerWrappedCallback;

  late final void Function(int) _unregisterWrappedCallback;
  late final void Function(Pointer) _runCallbackNative;
  late final bool Function(Pointer<Utf8>) _platformProxyExists;

  static final Map<int, Object> _userObjectStore = {};
  static final Object _nullUserObjectMarker = Object();

  final Map<String, List<bool>> _multiProxyFlags = {};

  void _callbackCallRequested(dynamic message) {
    final callback = Pointer<_CallbackWrapper>.fromAddress(message as int);
    _logDebug(_kLogTag,
        'calling runCallbackNative(), callback: ${callback.address.toRadixString(16)}');
    _runCallbackNative(callback);
    _logDebug(_kLogTag, 'after calling runCallbackNative()');
  }

  int _getFirstFreeIndex(List<bool> list) {
    return list.indexWhere((bool flag) => flag == false);
  }

  /// Registers a callback and returns wrapper/proxy data to be used in Native
  /// API calls.
  ///
  /// To specify signature of wrapper callbacks, the name of Native API callback
  /// defined in header file (such as `device_changed_cb`) must be provided as
  /// [callbackName].
  ///
  /// [Pointer.fromFunction] can be used to convert a Dart callback to an FFI
  /// pointer passed as the [callback] parameter.
  /// The requirements of [Pointer.fromFunction] applies, i.e. the function must
  /// be a static or free function. If the function returns anything, a fallback
  /// return value must be specifed - a value that will be used if the Dart
  /// callback throws an exception.
  ///
  /// [NativeCbType] must match the signature of the Native API callback. The
  /// proper type can be found in the relevant `generated_binding.dart` file,
  /// by looking for the typedef of the callback.
  /// The match is verified when [RegisteredCallback.interopCallback] is passed
  /// to the Native API.
  ///
  /// Most Tizen Native API callbacks allow passing arbitrary `user_data` in the
  /// form of `void*`. You can provide [userObject] and then, inside your Dart
  /// callback, use [TizenInteropCallbacks.getUserObject] with the received
  /// `user_data` to retrieve the object back.
  /// If [userObject] is null, `nullptr` will be passed.
  ///
  /// The plugin chooses non-blocking callback if possible - i.e. blocking will
  /// be used for callbacks which return anything. You can override the behavior
  /// by setting [blocking].
  /// Note that using blocking callback will block the thread the native module
  /// will call the callback on. In some cases, Native API invocation must be
  /// performed in separate thread/isolate.
  ///
  /// ```dart
  /// static void _batteryChanged(
  ///   int type,
  ///   Pointer<Void> value,
  ///   Pointer<Void> userData,
  /// ) {
  ///   ...
  /// }
  ///
  /// final batteryCallback =
  ///     _callbacks.register<Void Function(Int32, Pointer<Void>, Pointer<Void>)>(
  ///   'device_changed_cb',
  ///   Pointer.fromFunction(_batteryChanged),
  /// );
  /// ```
  RegisteredCallback<NativeCbType> register<NativeCbType extends Function>(
    String callbackName,
    Pointer<NativeFunction<NativeCbType>> callback, {
    Object? userObject,
    bool? blocking,
  }) {
    final nonBlockingCallbackNamePtr =
        'platform_non_blocking_$callbackName'.toNativeUtf8();
    _logDebug(_kLogTag, 'calling platformProxyExists()');
    blocking ??= !_platformProxyExists(nonBlockingCallbackNamePtr);
    calloc.free(nonBlockingCallbackNamePtr);

    String platformCallbackName;
    if (blocking) {
      platformCallbackName = 'platform_blocking_$callbackName';
    } else {
      platformCallbackName = 'platform_non_blocking_$callbackName';
    }

    if (!_multiProxyFlags.containsKey(platformCallbackName)) {
      _multiProxyFlags[platformCallbackName] =
          List<bool>.filled(_kProxyInstanceCount, false);
    }

    final proxyIndex =
        _getFirstFreeIndex(_multiProxyFlags[platformCallbackName]!);
    if (proxyIndex == -1) {
      throw Exception('Exhausted pool of $platformCallbackName proxies.');
    }
    _logDebug(_kLogTag,
        'setting proxy index $proxyIndex for $platformCallbackName as used');
    _multiProxyFlags[platformCallbackName]![proxyIndex] = true;

    final platformCallbackNamePtr = platformCallbackName.toNativeUtf8();
    _logDebug(_kLogTag,
        'calling registerWrappedCallback(), callback: ${callback.address.toRadixString(16)}');
    final result =
        _registerWrappedCallback(callback, platformCallbackNamePtr, proxyIndex);
    calloc.free(platformCallbackNamePtr);

    final platformCallback =
        result.callback.cast<NativeFunction<NativeCbType>>();
    _logDebug(_kLogTag, 'after calling registerWrappedCallback()');
    if (platformCallback == nullptr) {
      throw Exception('Failed to register callback.');
    }

    _logDebug(_kLogTag, 'saving userObjectStore[${result.id}] = $userObject');
    _userObjectStore[result.id] = userObject ?? _nullUserObjectMarker;

    return RegisteredCallback<NativeCbType>._(
      result.id,
      callbackName,
      platformCallbackName,
      proxyIndex,
      platformCallback,
    );
  }

  /// Unregisters a callback and deletes all its associated data.
  void unregister(RegisteredCallback registeredCallback) {
    final platformCallbackName = registeredCallback.platformCallbackName;
    final proxyIndex = registeredCallback.proxyIndex;

    if (_multiProxyFlags[platformCallbackName]![proxyIndex]) {
      _multiProxyFlags[platformCallbackName]![proxyIndex] = false;
    } else {
      Log.warn(_kLogTag,
          'Tried to remove non-existent proxy $proxyIndex for $platformCallbackName.');
    }
    _userObjectStore.remove(registeredCallback.id);
    _logDebug(_kLogTag,
        'calling unregisterWrappedCallback(), id: ${registeredCallback.id}');
    _unregisterWrappedCallback(registeredCallback.id);
  }

  /// Retrieves an object passed as `userObject` to [register].
  ///
  /// When `userObject` is used with [register], that object is stored
  /// internally and `interopUserData` of the returned [RegisteredCallback]
  /// holds the key to that object. The `user_data` received by callback should
  /// be passed to this function to retrieve the stored object.
  ///
  /// `null` is returned if no object associated with [userData] is found.
  ///
  /// ```dart
  /// static void _batteryChanged(
  ///   int type,
  ///   Pointer<Void> value,
  ///   Pointer<Void> userData,
  /// ) {
  ///   final userObject = TizenInteropCallbacks.getUserObject(userData);
  ///   ...
  /// }
  ///
  /// final batteryCallback =
  ///     _callbacks.register<Void Function(Int32, Pointer<Void>, Pointer<Void>)>(
  ///   'device_changed_cb',
  ///   Pointer.fromFunction(_batteryChanged),
  ///   userObject: userObject,
  /// );
  /// ```
  ///
  /// Note that this is not intended for passing objects across threads.
  /// You should access [TizenInteropCallbacks] from a single isolate only.
  static T? getUserObject<T extends Object>(Pointer<Void> userData) {
    if (_userObjectStore.containsKey(userData.address)) {
      var object = _userObjectStore[userData.address];
      if (identical(object, _nullUserObjectMarker)) object = null;
      _logDebug(_kLogTag, 'getting from store ${userData.address} -> $object');
      return object as T?;
    } else {
      Log.warn(_kLogTag,
          'getUserObject(): key ${userData.address} not found, returning null');
      return null;
    }
  }
}

final class _RegistrationResult extends Struct {
  /// The native proxy callback to be used with Native API.
  external Pointer callback;

  /// The registration ID.
  @Uint32()
  external int id;
}
