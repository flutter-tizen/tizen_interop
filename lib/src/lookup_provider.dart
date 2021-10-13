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
          'Failed to lookup symbol (undefined symbol: $symbolName');
    }
    _libraryCache[libraryName] ??= DynamicLibrary.open(libraryName);
    return _libraryCache[libraryName]!.lookup(symbolName);
  }
}
