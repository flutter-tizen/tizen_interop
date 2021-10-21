library tizen_interop;

import '../../src/bindings/6.0/generated_bindings.dart';
import '../../src/bindings/6.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/6.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen60Native? _tizen;
Tizen60Native get tizen =>
    _tizen ??= Tizen60Native.fromLookup(LookupProvider(tizen60Symbols).lookup);
