import 'dart:ffi';

class LookupProvider {
  late Map<String, String> _libraryIndex;
  Map<String, DynamicLibrary> _libraryCache = Map<String, DynamicLibrary>();

  LookupProvider(Map<String, List<String>> symbols) {
    _libraryIndex = _getSymbolToLibraryIndex(symbols);
  }

  Pointer<T> lookup<T extends NativeType>(String symbolName) {
    var libraryName = _libraryIndex[symbolName];
    if (libraryName == null) {
      throw ArgumentError(
          'Failed to lookup symbol (undefined symbol: $symbolName');
    }
    _libraryCache[libraryName] ??= DynamicLibrary.open(libraryName);
    return _libraryCache[libraryName]!.lookup(symbolName);
  }

  Map<String, String> _getSymbolToLibraryIndex(
    Map<String, List<String>> symbols,
  ) {
    final ret = Map<String, String>();
    for (final library in symbols.keys) {
      for (final symbol in symbols[library]!) {
        ret[symbol] = library;
      }
    }
    return ret;
  }
}
