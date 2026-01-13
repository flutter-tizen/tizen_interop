library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/9.0/generated_bindings.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/9.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen90Native? _tizen;
final _lookupProvider = LookupProvider();
Tizen90Native get tizen => _tizen ??= Tizen90Native.fromLookup(
      <T extends NativeType>(String symbolName) {
        return _lookupProvider.lookup<T>(symbolName);
      },
    );

void registerTizenSymbolMap(Map<String, List<String>> symbolMap) {
  _lookupProvider.registerSymbols(symbolMap);
}
