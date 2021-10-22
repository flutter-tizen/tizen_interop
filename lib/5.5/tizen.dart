library tizen_interop;

import '../../src/bindings/5.5/generated_bindings.dart';
import '../../src/bindings/5.5/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/5.5/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen55Native? _tizen;
Tizen55Native get tizen =>
    _tizen ??= Tizen55Native.fromLookup(LookupProvider(tizen55Symbols).lookup);
