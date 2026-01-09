library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/6.0/generated_bindings.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/6.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen60Native? _tizen;
final _lookupProvider = LookupProvider();
Tizen60Native get tizen => _tizen ??= Tizen60Native.fromLookup(
      <T extends NativeType>(String symbolName) {
        return _lookupProvider.lookup<T>(symbolName);
      },
    );

void registerTizenSymbolMap(Map<String, List<String>> symbolMap) {
  _lookupProvider.registerSymbols(symbolMap);
}
