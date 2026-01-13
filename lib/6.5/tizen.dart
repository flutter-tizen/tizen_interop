library tizen_interop;

import 'dart:ffi';

import '../../src/bindings/6.5/generated_bindings.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/6.5/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen65Native? _tizen;
final _lookupProvider = LookupProvider();
Tizen65Native get tizen => _tizen ??= Tizen65Native.fromLookup(
      <T extends NativeType>(String symbolName) {
        return _lookupProvider.lookup<T>(symbolName);
      },
    );

void registerTizenSymbolMap(Map<String, List<String>> symbolMap) {
  _lookupProvider.registerSymbols(symbolMap);
}
