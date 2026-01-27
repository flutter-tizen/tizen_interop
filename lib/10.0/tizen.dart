library tizen_interop;

import '../../src/bindings/10.0/generated_bindings.dart';
import '../../src/bindings/10.0/generated_symbols.dart';
import '../../src/lookup_provider.dart';

export '../../src/bindings/10.0/generated_bindings.dart';
export '../../src/extensions.dart';

Tizen100Native? _tizen;
Tizen100Native get tizen => _tizen ??=
    Tizen100Native.fromLookup(LookupProvider(tizen100Symbols).lookup);
