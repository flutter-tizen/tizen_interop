// Copyright 2021 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'dart:ffi';

class LookupProvider {
  LookupProvider(Map<String, List<String>> symbolMap) {
    symbolMap.forEach((String library, List<String> symbols) {
      symbols.forEach((String symbol) {
        _libraryIndex[symbol] = library;
      });
    });
  }

  late Map<String, String> _libraryIndex = Map<String, String>();
  Map<String, DynamicLibrary> _libraryCache = Map<String, DynamicLibrary>();

  Pointer<T> lookup<T extends NativeType>(String symbolName) {
    var libraryName = _libraryIndex[symbolName];
    if (libraryName == null) {
      throw ArgumentError(
          'Failed to look up symbol (undefined symbol: $symbolName)');
    }
    _libraryCache[libraryName] ??= DynamicLibrary.open(libraryName);
    return _libraryCache[libraryName]!.lookup(symbolName);
  }
}
