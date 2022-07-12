library tizen_interop;

import '../../src/bindings/6.5/generated_bindings.dart';
import '../../src/bindings/6.5/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/6.5/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen65Native? _tizen;
Tizen65Native get tizen =>
    _tizen ??= Tizen65Native.fromLookup(LookupProvider(tizen65Symbols).lookup);
