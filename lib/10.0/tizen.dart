library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/10.0/generated_bindings.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/10.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen100Native? _tizen;
final _lookupProvider = LookupProvider();
Tizen100Native get tizen => _tizen ??= Tizen100Native.fromLookup(
      <T extends NativeType>(String symbolName) {
        return _lookupProvider.lookup<T>(symbolName);
      },
    );

void registerTizenSymbolMap(Map<String, List<String>> symbolMap) {
  _lookupProvider.registerSymbols(symbolMap);
}
