// Copyright 2021 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'dart:ffi';

class LookupProvider {
  final Map<String, String> _libraryIndex = Map<String, String>();
  final Map<String, DynamicLibrary> _libraryCache =
      Map<String, DynamicLibrary>();
  final Set<String> _registeredSymbolMaps = {};

  /// Register symbols for a specific module
  void registerSymbols(Map<String, List<String>> symbolMap) {
    if (_registeredSymbolMaps.add(symbolMap.keys.first)) {
      symbolMap.forEach((String library, List<String> symbols) {
        symbols.forEach((String symbol) {
          _libraryIndex[symbol] = library;
        });
      });
    }
  }

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
