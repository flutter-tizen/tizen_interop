library tizen_interop;

import '../../src/bindings/9.0/generated_bindings.dart';
import '../../src/bindings/9.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/9.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen90Native? _tizen;
Tizen90Native get tizen =>
    _tizen ??= Tizen90Native.fromLookup(LookupProvider(tizen90Symbols).lookup);
