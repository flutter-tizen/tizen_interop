library tizen_interop;

import '../../src/bindings/8.0/generated_bindings.dart';
import '../../src/bindings/8.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/8.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen80Native? _tizen;
Tizen80Native get tizen =>
    _tizen ??= Tizen80Native.fromLookup(LookupProvider(tizen80Symbols).lookup);
