import 'dart:ffi';
import 'package:ffi/ffi.dart';

/// Represents the string type "char*" of the C language.
///
/// It allocates heap memory for the string value and its holder, and releases
/// all allocated memory by calling [free] method.
class CString {
  late Pointer<Pointer<Utf8>> _reference;

  /// Creates a holder for a C string.
  ///
  /// If a string value is received from the out parameter of a C native
  /// function, [CString] can be declared without an argument.
  /// ```dart
  /// final cstr = CString();
  /// some_native_function(cstr.ref);
  /// print(cstr);
  /// cstr.free();
  /// ```
  ///
  /// Conversely, if a string value is passed to a C native function, [CString]
  /// can be declared with a string argument.
  /// ```dart
  /// final cstr = CString('hello flutter');
  /// some_native_function(cstr.value);
  /// cstr.free();
  /// ```
  CString([String? value]) {
    _reference = calloc();
    _reference.value = value != null ? value.toNativeUtf8() : nullptr;
  }

  /// Gets the [Pointer] of the holder.
  Pointer<Pointer<Int8>> get ref => _reference.cast<Pointer<Int8>>();

  /// Gets the [Pointer] of the string value.
  Pointer<Int8> get value {
    assert(_reference != nullptr);
    return _reference.value.cast<Int8>();
  }

  /// Returns the Dart String.
  @override
  String toString() {
    if (_reference != nullptr && _reference.value != nullptr) {
      return _reference.value.toDartString();
    }
    return '';
  }

  /// Releases all allocations.
  ///
  /// Once [free] is called, the [CString] object cannot be reused.
  void free([bool ignoreValue = false]) {
    if (_reference != nullptr) {
      if (_reference.value != nullptr && !ignoreValue) {
        calloc.free(_reference.value);
        _reference.value = nullptr;
      }
      calloc.free(_reference);
      _reference = nullptr;
    }
  }
}

/// Runs [computation] with a new [CString], and releases all allocations at the
/// end.
///
/// If the return value of [computation] is a [Future], all allocations are
/// released when the future completes.
R usingCString<R>(R Function(CString) computation) {
  return usingCStringValue(null, computation);
}

/// Runs [computation] with a new [CString] with a string value, and releases
/// all allocations at the end.
///
/// If the return value of [computation] is a [Future], all allocations are
/// released when the future completes.
R usingCStringValue<R>(String? value, R Function(CString) computation) {
  final cstr = CString(value);
  bool isAsync = false;
  try {
    final result = computation(cstr);
    if (result is Future) {
      isAsync = true;
      return (result.whenComplete(cstr.free) as R);
    }
    return result;
  } finally {
    if (!isAsync) {
      cstr.free();
    }
  }
}
