library tizen_interop;

import '../../src/bindings/7.0/generated_bindings.dart';
import '../../src/bindings/7.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/7.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen70Native? _tizen;
Tizen70Native get tizen =>
    _tizen ??= Tizen70Native.fromLookup(LookupProvider(tizen70Symbols).lookup);
