library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/7.0/generated_bindings.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/7.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen70Native? _tizen;
final _lookupProvider = LookupProvider();
Tizen70Native get tizen => _tizen ??= Tizen70Native.fromLookup(
      <T extends NativeType>(String symbolName) {
        return _lookupProvider.lookup<T>(symbolName);
      },
    );

void registerTizenSymbolMap(Map<String, List<String>> symbolMap) {
  _lookupProvider.registerSymbols(symbolMap);
}
