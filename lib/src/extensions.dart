import 'dart:ffi';
import 'package:ffi/ffi.dart';

extension Int8Pointer on Pointer<Int8> {
  int get length => cast<Utf8>().length;

  String toDartString({int? length}) {
    return cast<Utf8>().toDartString(length: length);
  }
}

extension StringInt8Pointer on String {
  Pointer<Int8> toNativeInt8({Allocator allocator = malloc}) {
    return toNativeUtf8(allocator: allocator).cast<Int8>();
  }
}
