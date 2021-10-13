library tizen_interop;

import '../../src/bindings/5.0/generated_bindings.dart';
import '../../src/bindings/5.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/5.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen50Native? _tizen;
Tizen50Native get tizen =>
    _tizen ??= Tizen50Native.fromLookup(LookupProvider(tizen50Symbols).lookup);
