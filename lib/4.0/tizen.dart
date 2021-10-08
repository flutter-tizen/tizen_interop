library tizen_interop;

import '../../src/bindings/4.0/generated_bindings.dart';
import '../../src/bindings/4.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/4.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen40Native? _tizen;
Tizen40Native get tizen =>
    _tizen ??= Tizen40Native.fromLookup(LookupProvider(tizen40Symbols).lookup);
