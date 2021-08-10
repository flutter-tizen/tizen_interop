library tizen_interop;

import 'dart:ffi';
import '../../src/bindings/4.0/wearable/generated_bindings.dart';
import '../../src/bindings/4.0/wearable/generated_symbols.dart';

export '../../src/bindings/4.0/wearable/generated_bindings.dart';
export '../../src/extensions.dart';
export '../../src/cstring.dart';

final _provider = _LookupProvider();

Tizen40Wearable? _tizen;
Tizen40Wearable get tizen =>
    _tizen ??= Tizen40Wearable.fromLookup(_provider.lookup);

class _LookupProvider {
  late Map<String, String> _libraryIndex = _getSymbolToLibraryIndex();
  Map<String, DynamicLibrary> _libraryCache = Map<String, DynamicLibrary>();

  Pointer<T> lookup<T extends NativeType>(String symbolName) {
    var libraryName = _libraryIndex[symbolName];
    if (libraryName == null) {
      throw ArgumentError(
          'Failed to lookup symbol (undefined symbol: $symbolName');
    }
    _libraryCache[libraryName] ??= DynamicLibrary.open(libraryName);
    return _libraryCache[libraryName]!.lookup(symbolName);
  }

  Map<String, String> _getSymbolToLibraryIndex() {
    final ret = Map<String, String>();
    for (final library in tizen40Symbols.keys) {
      for (final symbol in tizen40Symbols[library]!) {
        ret[symbol] = library;
      }
    }
    return ret;
  }
}
