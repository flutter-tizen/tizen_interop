import 'dart:collection';
import 'dart:io';

const _doxygenTags = <String>[
  'brief',
  'details',
  'deprecated',
  'since(?:_tizen)?',
  'privlevel',
  'privilege',
  'remarks?',
  'param(?:\\[[^\\]]+\\])?',
  'return',
  'retval',
  'exception',
  'pre',
  'post',
  'note',
  'warning',
  'see',
  'par',
  'code',
  'endcode',
  'feature',
  'platform',
  'partner',
  'internal',
  'WEARABLE_ONLY',
  'section',
  'ingroup',
  'addtogroup',
  'typedef',
  'struct',
  'enum',
];

final _doxygenTagRegExp = RegExp(
  r'^[\\@]('
  '${_doxygenTags.join('|')}'
  r')\b',
);
final _inlineDoxygenTagRegExp = RegExp(
  r'[\\@](?:if|elseif|else|endif|ref|[abce])\b',
);
final _docCommentStartRegExp = RegExp(r'^(\s*)///');
final _docCommentLineRegExp = RegExp(r'^\s*///');
final _codeBlockStartRegExp = RegExp(
  r'^[@\\]code(?:\{\.?([^}]+)\})?(?:\s+.*)?$',
);
final _versionedTizenLibraryPathRegExp = RegExp(
  r'(^|[\\/])lib[\\/](\d+\.\d+)[\\/]tizen\.dart$',
);
final _pathSeparatorRegExp = RegExp(r'[\\/]');
final _topLevelDeclarationRegExp = RegExp(
  r'^(typedef|(?:abstract|final)\s+class|class|enum)\s+',
);
final _primaryNativeClassRegExp = RegExp(r'^class\s+Tizen[0-9]+Native\b');
final _publicTopLevelGetterRegExp = RegExp(
  r'^[A-Za-z][A-Za-z0-9_<>,?. ]+\s+get\s+[A-Za-z][A-Za-z0-9_]*\b',
);
final _libraryTizenInteropRegExp = RegExp(r'^library\s+tizen_interop\s*;$');
final _briefTagRegExp = RegExp(r'^[\\@]brief\s*(.*)$');
final _detailsTagRegExp = RegExp(r'^[\\@]details\s*(.*)$');
final _deprecatedTagRegExp = RegExp(r'^[\\@]deprecated\s*(.*)$');
final _sinceTizenTagRegExp = RegExp(r'^[\\@]since_tizen\s*(.*)$');
final _sinceTagRegExp = RegExp(r'^[\\@]since\s*(.*)$');
final _privlevelTagRegExp = RegExp(r'^[\\@]privlevel\s*(.*)$');
final _privilegeTagRegExp = RegExp(r'^[\\@]privilege\s*(.*)$');
final _remarksTagRegExp = RegExp(r'^[\\@]remarks?\s*(.*)$');
final _paramTagRegExp = RegExp(r'^[\\@]param(?:\[(.*?)\])?\s+(\S+)\s*(.*)$');
final _returnTagRegExp = RegExp(r'^[\\@]return\s*(.*)$');
final _retvalTagRegExp = RegExp(r'^[\\@]retval\s*(.*)$');
final _exceptionTagRegExp = RegExp(r'^[\\@]exception\s*(.*)$');
final _preTagRegExp = RegExp(r'^[\\@]pre\s*(.*)$');
final _postTagRegExp = RegExp(r'^[\\@]post\s*(.*)$');
final _noteTagRegExp = RegExp(r'^[\\@]note\s*(.*)$');
final _warningTagRegExp = RegExp(r'^[\\@]warning\s*(.*)$');
final _seeTagRegExp = RegExp(r'^[\\@]see\s*(.*)$');
final _parTagRegExp = RegExp(r'^[\\@]par\s*(.*)$');
final _featureTagRegExp = RegExp(r'^[\\@]feature\s*(.*)$');
final _platformTagRegExp = RegExp(r'^[\\@]platform\s*(.*)$');
final _partnerTagRegExp = RegExp(r'^[\\@]partner\s*(.*)$');
final _internalTagRegExp = RegExp(r'^[\\@]internal\s*(.*)$');
final _wearableOnlyTagRegExp = RegExp(r'^[\\@]WEARABLE_ONLY\s*(.*)$');
final _sectionTagRegExp = RegExp(r'^[\\@]section\s*(.*)$');
final _groupTagRegExp = RegExp(r'^[\\@](?:ingroup|addtogroup)\s*(.*)$');
final _miscTagRegExp = RegExp(r'^[\\@](typedef|struct|enum)\s*(.*)$');
final _namedDocItemRegExp = RegExp(r'^(\S+)\s*(.*)$');
final _titleTrailingColonRegExp = RegExp(r':+$');
final _encodedNewlineMarkerRegExp = RegExp(r'(?<!\w)@n(?!\w)');
final _conditionalSinceBranchRegExp = RegExp(
  r'@(?:if|elseif)\s+([A-Z_]+)\s+(.+?)(?=\s+@(?:if|elseif|else|endif)\b|$)',
);
final _conditionalElseRegExp = RegExp(r'@else\s+(.+?)(?=\s+@endif\b|$)');
final _simpleReferenceRegExp = RegExp(r'^[A-Za-z_][A-Za-z0-9_]*(?:\(\))?$');
final _conditionalInlineBlockRegExp = RegExp(r'@if\s+[A-Z_]+\s+.+?@endif');
final _inlineRefRegExp = RegExp(r'[\\@]ref\s+([^\s]+)');
final _inlineFormattingTagRegExp = RegExp(r'[\\@]([abce])\s+([^\s]+)');
final _trailingPunctuationRegExp = RegExp(r'^(.+?)([.,;:!?)]*)$');
final _hashReferenceRegExp = RegExp(r'#([A-Za-z_][A-Za-z0-9_]*(?:\(\))?)');
final _squareBracketLiteralRegExp = RegExp(r'(?<!`)\[([^\[\]]+)\](?!`)');
final _whitespaceRegExp = RegExp(r'\s+');

class _DocItem {
  _DocItem({this.name, this.direction, required this.description});

  final String? name;
  final String? direction;
  String description;

  void append(String text) {
    description = _mergeDocText(description, text);
  }
}

class _CodeBlock {
  _CodeBlock({required this.lines, this.title, this.language});

  final List<String> lines;
  final String? title;
  final String? language;
}

class _StructuredDoc {
  final List<String> deprecations = [];
  final List<String> summary = [];
  final List<String> details = [];
  final List<String> since = [];
  final List<String> privilegeLevels = [];
  final List<String> privileges = [];
  final List<String> remarks = [];
  final List<_DocItem> parameters = [];
  final List<String> returns = [];
  final List<_DocItem> returnValues = [];
  final List<_DocItem> exceptions = [];
  final List<String> preconditions = [];
  final List<String> postconditions = [];
  final List<String> notes = [];
  final List<String> warnings = [];
  final List<String> seeAlso = [];
  final List<_CodeBlock> codeBlocks = [];
  final LinkedHashMap<String, List<String>> extraSections = LinkedHashMap();

  void addExtra(String label, String text) {
    extraSections.putIfAbsent(label, () => []).add(text);
  }
}

/// Converts Doxygen-style `///` comments in one or more Dart files in place.
void main(List<String> args) {
  if (args.isEmpty || args.contains('--help') || args.contains('-h')) {
    stdout.writeln(
      'Usage: dart run scripts/convert_description.dart <dart-file | version> '
      '[more...]',
    );
    exit(args.isEmpty ? 64 : 0);
  }

  final pathsToProcess = <String>[];
  for (final arg in args) {
    if (arg.startsWith('-')) {
      stderr.writeln('Unknown option: $arg');
      exitCode = 64;
      return;
    }

    if (arg.endsWith('.dart')) {
      pathsToProcess.add(arg);
    } else {
      // Treat argument as a version to fetch files from its bindings directory
      final bindingDir = Directory('lib/src/bindings/$arg');
      if (bindingDir.existsSync()) {
        for (final entry in bindingDir.listSync()) {
          if (entry is File) {
            final fileName = entry.path.split(_pathSeparatorRegExp).last;
            if (fileName.startsWith('generated_bindings') &&
                fileName.endsWith('.dart')) {
              pathsToProcess.add(entry.path);
            }
          }
        }
      } else {
        stderr.writeln(
          'Expected a Dart file path or version (e.g. "6.0"), got: $arg',
        );
        exitCode = 64;
        return;
      }
    }
  }

  var changedCount = 0;
  for (final path in pathsToProcess) {
    try {
      final changed = convertDoxygenCommentsInDartFile(path);
      if (changed) {
        stdout.writeln('Converted: $path');
        changedCount++;
      } else {
        stdout.writeln('No changes: $path');
      }
    } on Object catch (error) {
      stderr.writeln(error);
      exitCode = 1;
      return;
    }
  }

  if (changedCount == 0) {
    stdout.writeln('No doxygen-style doc comments were rewritten.');
  }
}

/// Rewrites Doxygen-style `///` lines into dartdoc/Markdown comments.
List<String> convertDoxygenDocCommentLines(List<String> docLines) {
  return _convertMethodDocLines(docLines);
}

/// Returns true when a doc-comment block contains recognized Doxygen markers.
bool looksLikeDoxygenDocCommentBlock(List<String> docLines) {
  for (final line in docLines) {
    final stripped = _stripGeneratedDocLine(line).trim();
    if (line.trim().startsWith('<') ||
        _doxygenTagRegExp.hasMatch(stripped) ||
        _inlineDoxygenTagRegExp.hasMatch(stripped) ||
        _squareBracketLiteralRegExp.hasMatch(stripped) ||
        stripped.contains('```[')) {
      return true;
    }
  }

  return false;
}

/// Converts all recognized Doxygen-style `///` blocks in a Dart source string.
String convertDoxygenCommentsInDartSource(String source, {String? path}) {
  final newline = source.contains('\r\n') ? '\r\n' : '\n';
  final hasTrailingNewline = source.endsWith('\n');
  final lines = source.split(RegExp(r'\r?\n')).toList();
  if (hasTrailingNewline && lines.isNotEmpty && lines.last.isEmpty) {
    lines.removeLast();
  }

  final output = <String>[];
  var index = 0;
  while (index < lines.length) {
    final line = lines[index];
    final docMatch = _docCommentStartRegExp.firstMatch(line);
    if (docMatch == null) {
      output.add(line);
      index++;
      continue;
    }

    final indent = docMatch.group(1)!;
    final block = <String>[];
    while (index < lines.length &&
        _docCommentLineRegExp.hasMatch(lines[index])) {
      block.add(lines[index]);
      index++;
    }

    final relativeBlock = block
        .map((commentLine) => commentLine.substring(indent.length))
        .toList();
    if (!looksLikeDoxygenDocCommentBlock(relativeBlock)) {
      output.addAll(block);
      continue;
    }

    final converted = convertDoxygenDocCommentLines(relativeBlock);
    output.addAll(converted.map((commentLine) => '$indent$commentLine'));
  }

  final annotatedOutput = _shouldHideTopLevelGeneratedBindingsDeclarations(path)
      ? _annotateGeneratedBindingsTopLevelDeclarations(output)
      : _shouldHideVersionedTizenLibraryGetters(path)
      ? _annotateVersionedTizenLibraryGetters(output)
      : output;
  final normalizedOutput = _rewriteVersionedTizenLibraryName(
    annotatedOutput,
    path,
  );
  final convertedSource = normalizedOutput.join(newline);
  if (hasTrailingNewline) {
    return '$convertedSource$newline';
  }
  return convertedSource;
}

/// Rewrites recognized Doxygen-style `///` blocks in `path` and returns
/// whether the file changed.
bool convertDoxygenCommentsInDartFile(String path) {
  final file = File(path);
  if (!file.existsSync()) {
    throw StateError('Missing file: $path');
  }

  final original = file.readAsStringSync();
  final converted = convertDoxygenCommentsInDartSource(original, path: path);
  if (converted == original) {
    return false;
  }

  file.writeAsStringSync(converted);
  return true;
}

bool _shouldHideTopLevelGeneratedBindingsDeclarations(String? path) {
  if (path == null) {
    return false;
  }

  final fileName = path.split(_pathSeparatorRegExp).last;
  return fileName == 'generated_bindings.dart';
}

bool _shouldHideVersionedTizenLibraryGetters(String? path) {
  if (path == null) {
    return false;
  }

  return _versionedTizenLibraryPathRegExp.hasMatch(path);
}

List<String> _annotateGeneratedBindingsTopLevelDeclarations(
  List<String> lines,
) {
  final output = <String>[];

  for (final line in lines) {
    final trimmed = line.trimLeft();
    final isTopLevelLine = trimmed == line;

    if (isTopLevelLine &&
        _topLevelDeclarationRegExp.hasMatch(trimmed) &&
        !_primaryNativeClassRegExp.hasMatch(trimmed)) {
      if (output.isEmpty || output.last.trim() != '/// {@nodoc}') {
        output.add('/// {@nodoc}');
      }
    }

    output.add(line);
  }

  return output;
}

List<String> _annotateVersionedTizenLibraryGetters(List<String> lines) {
  final output = <String>[];

  for (final line in lines) {
    final trimmed = line.trimLeft();
    final isTopLevelLine = trimmed == line;

    if (isTopLevelLine && _publicTopLevelGetterRegExp.hasMatch(trimmed)) {
      if (output.isEmpty || output.last.trim() != '/// {@nodoc}') {
        output.add('/// {@nodoc}');
      }
    }

    output.add(line);
  }

  return output;
}

List<String> _rewriteVersionedTizenLibraryName(
  List<String> lines,
  String? path,
) {
  if (path == null) {
    return lines;
  }

  final match = _versionedTizenLibraryPathRegExp.firstMatch(path);
  if (match == null) {
    return lines;
  }

  final versionId = match.group(2)!.replaceAll('.', '_');
  return lines
      .map(
        (line) => _libraryTizenInteropRegExp.hasMatch(line)
            ? 'library tizen_interop_$versionId;'
            : line,
      )
      .toList();
}

List<String> _convertMethodDocLines(List<String> docLines) {
  if (docLines.isEmpty) {
    return const [];
  }

  final doc = _parseStructuredDoc(docLines);
  final output = <String>[];

  void addParagraphs(List<String> paragraphs) {
    for (final paragraph in paragraphs) {
      _appendDocParagraph(output, paragraph);
    }
  }

  void addBullets(String heading, List<String> items) {
    _appendDocBullets(output, heading, items);
  }

  void addNamedBullets(String heading, List<_DocItem> items) {
    _appendDocNamedBullets(output, heading, items);
  }

  addParagraphs(doc.deprecations);
  addParagraphs(doc.summary);
  addParagraphs(doc.details);
  addBullets('Since Tizen', doc.since);
  addBullets('Privilege level', doc.privilegeLevels);
  addBullets('Privileges', doc.privileges);
  addBullets('Remarks', doc.remarks);
  addNamedBullets('Parameters', doc.parameters);
  addBullets('Returns', doc.returns);
  addNamedBullets('Return values', doc.returnValues);
  addNamedBullets('Exceptions', doc.exceptions);
  addBullets('Preconditions', doc.preconditions);
  addBullets('Postconditions', doc.postconditions);
  addBullets('Notes', doc.notes);
  addBullets('Warnings', doc.warnings);
  addBullets('See also', doc.seeAlso);

  for (final entry in doc.extraSections.entries) {
    addBullets(entry.key, entry.value);
  }

  for (final codeBlock in doc.codeBlocks) {
    if (codeBlock.title != null && codeBlock.title!.isNotEmpty) {
      final title = codeBlock.title!.replaceFirst(
        _titleTrailingColonRegExp,
        '',
      );
      _appendDocParagraph(output, '**$title:**');
    }
    _appendCodeBlock(output, codeBlock);
  }

  if (output.isNotEmpty && output.last == '///') {
    output.removeLast();
  }

  return output;
}

_StructuredDoc _parseStructuredDoc(List<String> docLines) {
  final doc = _StructuredDoc();
  void Function(String text)? appendContinuation;
  final pendingParagraphTitles = <String>[];
  List<String>? currentCodeBlock;
  String? currentCodeLanguage;

  void addParagraph(
    List<String> target,
    String text, {
    bool appendToCurrentItem = true,
  }) {
    final normalized = _normalizeInlineDocText(text);
    if (normalized.isEmpty) {
      return;
    }
    target.add(normalized);
    appendContinuation = (more) {
      final nextText = _normalizeInlineDocText(more);
      if (nextText.isEmpty) {
        return;
      }
      if (appendToCurrentItem) {
        target[target.length - 1] = _mergeDocText(
          target[target.length - 1],
          nextText,
        );
        return;
      }
      target.add(nextText);
    };
  }

  void addNamedItem(
    List<_DocItem> target,
    String? name,
    String description, {
    String? direction,
  }) {
    final normalized = _normalizeInlineDocText(description);
    target.add(
      _DocItem(
        name: name == null || name.isEmpty ? null : name,
        direction: direction == null || direction.isEmpty ? null : direction,
        description: normalized,
      ),
    );
    appendContinuation = (more) {
      target[target.length - 1].append(_normalizeInlineDocText(more));
    };
  }

  void addExtra(String label, String text) {
    final normalized = _normalizeInlineDocText(text);
    if (normalized.isEmpty) {
      return;
    }
    doc.addExtra(label, normalized);
    appendContinuation = (more) {
      final items = doc.extraSections[label]!;
      items[items.length - 1] = _mergeDocText(
        items[items.length - 1],
        _normalizeInlineDocText(more),
      );
    };
  }

  void flushPendingParagraphTitles() {
    while (pendingParagraphTitles.isNotEmpty) {
      addExtra('Paragraph', pendingParagraphTitles.removeAt(0));
    }
  }

  for (final rawDocLine in docLines) {
    final stripped = _stripGeneratedDocLine(rawDocLine);
    final expandedLines = _expandDocLine(stripped);

    for (final expandedLine in expandedLines) {
      final line = currentCodeBlock == null
          ? expandedLine.trimRight()
          : expandedLine;
      final trimmed = line.trim();

      if (currentCodeBlock != null) {
        if (trimmed == r'@endcode' || trimmed == r'\endcode') {
          final title = pendingParagraphTitles.isNotEmpty
              ? pendingParagraphTitles.removeLast()
              : null;
          doc.codeBlocks.add(
            _CodeBlock(
              lines: List<String>.from(currentCodeBlock),
              title: title,
              language: currentCodeLanguage,
            ),
          );
          currentCodeBlock = null;
          currentCodeLanguage = null;
          appendContinuation = null;
          continue;
        }
        currentCodeBlock.add(_normalizeCodeLine(line));
        continue;
      }

      if (trimmed.isEmpty) {
        appendContinuation = null;
        continue;
      }

      final codeBlockStartMatch = _codeBlockStartRegExp.firstMatch(trimmed);
      if (codeBlockStartMatch != null) {
        currentCodeBlock = <String>[];
        currentCodeLanguage = _normalizeCodeBlockLanguage(
          codeBlockStartMatch.group(1),
        );
        appendContinuation = null;
        continue;
      }

      final briefMatch = _briefTagRegExp.firstMatch(trimmed);
      if (briefMatch != null) {
        addParagraph(doc.summary, briefMatch.group(1)!);
        continue;
      }

      final detailsMatch = _detailsTagRegExp.firstMatch(trimmed);
      if (detailsMatch != null) {
        addParagraph(doc.details, detailsMatch.group(1)!);
        continue;
      }

      final deprecatedMatch = _deprecatedTagRegExp.firstMatch(trimmed);
      if (deprecatedMatch != null) {
        final text = deprecatedMatch.group(1)!.trim();
        addParagraph(
          doc.deprecations,
          text.isEmpty
              ? '**Deprecated.**'
              : '**Deprecated:** ${_normalizeConditionalInlineText(text)}',
        );
        continue;
      }

      final sinceTizenMatch = _sinceTizenTagRegExp.firstMatch(trimmed);
      if (sinceTizenMatch != null) {
        addParagraph(doc.since, _formatSinceText(sinceTizenMatch.group(1)!));
        continue;
      }

      final sinceMatch = _sinceTagRegExp.firstMatch(trimmed);
      if (sinceMatch != null) {
        addParagraph(doc.since, sinceMatch.group(1)!);
        continue;
      }

      final privlevelMatch = _privlevelTagRegExp.firstMatch(trimmed);
      if (privlevelMatch != null) {
        addParagraph(doc.privilegeLevels, privlevelMatch.group(1)!);
        continue;
      }

      final privilegeMatch = _privilegeTagRegExp.firstMatch(trimmed);
      if (privilegeMatch != null) {
        addParagraph(
          doc.privileges,
          privilegeMatch.group(1)!,
          appendToCurrentItem: false,
        );
        continue;
      }

      final remarksMatch = _remarksTagRegExp.firstMatch(trimmed);
      if (remarksMatch != null) {
        addParagraph(
          doc.remarks,
          remarksMatch.group(1)!,
          appendToCurrentItem: false,
        );
        continue;
      }

      final paramMatch = _paramTagRegExp.firstMatch(trimmed);
      if (paramMatch != null) {
        addNamedItem(
          doc.parameters,
          paramMatch.group(2),
          paramMatch.group(3) ?? '',
          direction: paramMatch.group(1),
        );
        continue;
      }

      final returnMatch = _returnTagRegExp.firstMatch(trimmed);
      if (returnMatch != null) {
        addParagraph(doc.returns, returnMatch.group(1)!);
        continue;
      }

      final retvalMatch = _retvalTagRegExp.firstMatch(trimmed);
      if (retvalMatch != null) {
        final parsed = _parseNamedDocItem(retvalMatch.group(1)!);
        addNamedItem(doc.returnValues, parsed.name, parsed.description);
        continue;
      }

      final exceptionMatch = _exceptionTagRegExp.firstMatch(trimmed);
      if (exceptionMatch != null) {
        final parsed = _parseNamedDocItem(exceptionMatch.group(1)!);
        addNamedItem(doc.exceptions, parsed.name, parsed.description);
        continue;
      }

      final preMatch = _preTagRegExp.firstMatch(trimmed);
      if (preMatch != null) {
        addParagraph(doc.preconditions, preMatch.group(1)!);
        continue;
      }

      final postMatch = _postTagRegExp.firstMatch(trimmed);
      if (postMatch != null) {
        addParagraph(doc.postconditions, postMatch.group(1)!);
        continue;
      }

      final noteMatch = _noteTagRegExp.firstMatch(trimmed);
      if (noteMatch != null) {
        addParagraph(doc.notes, noteMatch.group(1)!);
        continue;
      }

      final warningMatch = _warningTagRegExp.firstMatch(trimmed);
      if (warningMatch != null) {
        addParagraph(doc.warnings, warningMatch.group(1)!);
        continue;
      }

      final seeMatch = _seeTagRegExp.firstMatch(trimmed);
      if (seeMatch != null) {
        addParagraph(doc.seeAlso, _normalizeSeeAlsoText(seeMatch.group(1)!));
        continue;
      }

      final parMatch = _parTagRegExp.firstMatch(trimmed);
      if (parMatch != null) {
        final title = _normalizeInlineDocText(parMatch.group(1)!);
        if (title.isNotEmpty) {
          pendingParagraphTitles.add(title);
        }
        appendContinuation = null;
        continue;
      }

      final featureMatch = _featureTagRegExp.firstMatch(trimmed);
      if (featureMatch != null) {
        addExtra('Required feature', featureMatch.group(1)!);
        continue;
      }

      final platformMatch = _platformTagRegExp.firstMatch(trimmed);
      if (platformMatch != null) {
        final text = platformMatch.group(1)!.trim();
        addExtra('Platform', text.isEmpty ? 'Platform API.' : text);
        continue;
      }

      final partnerMatch = _partnerTagRegExp.firstMatch(trimmed);
      if (partnerMatch != null) {
        addExtra('Partner', partnerMatch.group(1)!);
        continue;
      }

      final internalMatch = _internalTagRegExp.firstMatch(trimmed);
      if (internalMatch != null) {
        addExtra('Internal', internalMatch.group(1)!);
        continue;
      }

      final wearableOnlyMatch = _wearableOnlyTagRegExp.firstMatch(trimmed);
      if (wearableOnlyMatch != null) {
        final text = wearableOnlyMatch.group(1)!.trim();
        addExtra(
          'Platform restriction',
          text.isEmpty ? 'Wearable only.' : text,
        );
        continue;
      }

      final sectionMatch = _sectionTagRegExp.firstMatch(trimmed);
      if (sectionMatch != null) {
        addExtra('Section', sectionMatch.group(1)!);
        continue;
      }

      final groupMatch = _groupTagRegExp.firstMatch(trimmed);
      if (groupMatch != null) {
        addExtra('Group', groupMatch.group(1)!);
        continue;
      }

      final miscTagMatch = _miscTagRegExp.firstMatch(trimmed);
      if (miscTagMatch != null) {
        addExtra(
          _uppercaseFirst(miscTagMatch.group(1)!),
          miscTagMatch.group(2)!,
        );
        continue;
      }

      if (appendContinuation != null) {
        appendContinuation!(trimmed);
        continue;
      }

      if (pendingParagraphTitles.isNotEmpty) {
        addExtra(pendingParagraphTitles.removeAt(0), trimmed);
        continue;
      }

      addParagraph(
        doc.summary.isEmpty && doc.details.isEmpty ? doc.summary : doc.details,
        trimmed,
      );
    }
  }

  if (currentCodeBlock != null) {
    doc.codeBlocks.add(
      _CodeBlock(
        lines: List<String>.from(currentCodeBlock),
        title: pendingParagraphTitles.isNotEmpty
            ? pendingParagraphTitles.removeLast()
            : null,
        language: currentCodeLanguage,
      ),
    );
  }

  flushPendingParagraphTitles();
  return doc;
}

_DocItem _parseNamedDocItem(String text) {
  final normalized = _normalizeInlineDocText(text);
  final match = _namedDocItemRegExp.firstMatch(normalized);
  if (match == null) {
    return _DocItem(description: normalized);
  }

  return _DocItem(
    name: match.group(1),
    description: (match.group(2) ?? '').trim(),
  );
}

void _appendDocParagraph(List<String> output, String paragraph) {
  if (paragraph.trim().isEmpty) {
    return;
  }
  if (output.isNotEmpty) {
    output.add('///');
  }
  for (final line in paragraph.split('\n')) {
    output.add(line.isEmpty ? '///' : '/// $line');
  }
}

void _appendDocBullets(
  List<String> output,
  String heading,
  List<String> items,
) {
  final filteredItems = items.where((item) => item.trim().isNotEmpty).toList();
  if (filteredItems.isEmpty) {
    return;
  }
  if (output.isNotEmpty) {
    output.add('///');
  }
  output.add('/// **$heading:**');
  for (final item in filteredItems) {
    final bulletText = item.startsWith('http://') || item.startsWith('https://')
        ? '<$item>'
        : item;
    output.add('/// - $bulletText');
  }
}

void _appendDocNamedBullets(
  List<String> output,
  String heading,
  List<_DocItem> items,
) {
  final filteredItems = items
      .where((item) => item.description.trim().isNotEmpty)
      .toList();
  if (filteredItems.isEmpty) {
    return;
  }
  if (output.isNotEmpty) {
    output.add('///');
  }
  output.add('/// **$heading:**');
  for (final item in filteredItems) {
    final buffer = StringBuffer('/// - ');
    if (item.name != null) {
      final displayName = item.name!.startsWith('`') && item.name!.endsWith('`')
          ? item.name!
          : '`${item.name}`';
      buffer.write(displayName);
      if (item.direction != null && item.direction!.isNotEmpty) {
        buffer.write(' (${item.direction})');
      }
      if (item.description.isNotEmpty) {
        buffer.write(': ${item.description}');
      }
    } else {
      buffer.write(item.description);
    }
    output.add(buffer.toString());
  }
}

void _appendCodeBlock(List<String> output, _CodeBlock codeBlock) {
  if (codeBlock.lines.isEmpty) {
    return;
  }
  if (output.isNotEmpty) {
    output.add('///');
  }
  output.add(
    codeBlock.language == null ? '/// ```' : '/// ```${codeBlock.language}',
  );
  for (final line in codeBlock.lines) {
    output.add(line.isEmpty ? '///' : '/// $line');
  }
  output.add('/// ```');
}

String _stripGeneratedDocLine(String line) {
  final stripped = line.startsWith('///') ? line.substring(3) : line;
  return stripped.startsWith(' ') ? stripped.substring(1) : stripped;
}

List<String> _expandDocLine(String line) {
  final expanded = line
      .replaceAll(r'\n', '\n')
      .replaceAll(_encodedNewlineMarkerRegExp, '\n');
  final parts = expanded.split('\n');
  while (parts.isNotEmpty && parts.last.isEmpty) {
    parts.removeLast();
  }
  return parts;
}

String _formatSinceText(String text) {
  final trimmed = text.trim();
  if (!trimmed.contains('@if')) {
    return _normalizeInlineDocText(trimmed);
  }

  final items = <String>[];
  for (final match in _conditionalSinceBranchRegExp.allMatches(trimmed)) {
    final platform = _formatPlatformLabel(match.group(1)!);
    final version = _normalizeInlineDocText(match.group(2)!);
    items.add('$platform $version');
  }

  final elseMatch = _conditionalElseRegExp.firstMatch(trimmed);
  if (elseMatch != null) {
    items.add('Otherwise ${_normalizeInlineDocText(elseMatch.group(1)!)}');
  }

  if (items.isNotEmpty) {
    return items.join('; ');
  }

  return _normalizeInlineDocText(
    trimmed
        .replaceAll('@if', '')
        .replaceAll('@elseif', '')
        .replaceAll('@else', '')
        .replaceAll('@endif', ''),
  );
}

String _formatPlatformLabel(String value) {
  return value
      .split('_')
      .where((part) => part.isNotEmpty)
      .map((part) => '${part[0]}${part.substring(1).toLowerCase()}')
      .join(' ');
}

String _normalizeSeeAlsoText(String text) {
  final normalized = _normalizeInlineDocText(text);
  if (normalized.isEmpty) {
    return normalized;
  }
  if (normalized.startsWith('http://') || normalized.startsWith('https://')) {
    return '<$normalized>';
  }
  if (normalized.startsWith('`') && normalized.endsWith('`')) {
    return normalized;
  }
  if (_simpleReferenceRegExp.hasMatch(normalized)) {
    return '`$normalized`';
  }
  return normalized;
}

String _normalizeConditionalInlineText(String text) {
  final trimmed = text.trim();
  if (!trimmed.contains('@if')) {
    return _normalizeInlineDocText(trimmed);
  }

  final conditionalMatch = _conditionalInlineBlockRegExp.firstMatch(trimmed);
  if (conditionalMatch == null) {
    return _normalizeInlineDocText(trimmed);
  }

  final replacement = _formatSinceText(conditionalMatch.group(0)!);
  final replaced = trimmed.replaceRange(
    conditionalMatch.start,
    conditionalMatch.end,
    replacement,
  );
  return _normalizeInlineDocText(replaced);
}

String _normalizeInlineDocText(String text) {
  var normalized = text.trim();
  if (normalized.isEmpty) {
    return normalized;
  }

  normalized = normalized.replaceAll(r'\n', ' ');
  normalized = normalized.replaceAll(_encodedNewlineMarkerRegExp, ' ');
  normalized = normalized.replaceAll('%http://', 'http://');
  normalized = normalized.replaceAll('%https://', 'https://');

  normalized = normalized.replaceAllMapped(
    _inlineRefRegExp,
    (match) => '`${match.group(1)}`',
  );
  normalized = normalized.replaceAllMapped(_inlineFormattingTagRegExp, (match) {
    final marker = match.group(1)!;
    final rawToken = match.group(2)!;
    final tokenMatch = _trailingPunctuationRegExp.firstMatch(rawToken)!;
    final token = tokenMatch.group(1)!;
    final punctuation = tokenMatch.group(2)!;
    final formatted = switch (marker) {
      'a' || 'c' => '`$token`',
      'b' => '**$token**',
      'e' => '*$token*',
      _ => token,
    };
    return '$formatted$punctuation';
  });
  normalized = normalized.replaceAllMapped(
    _hashReferenceRegExp,
    (match) => '`${match.group(1)}`',
  );
  // Normalize existing bracket escaping (idempotency)
  normalized = normalized.replaceAllMapped(
    RegExp(r'`+\[([^\[\]]+)\]`+'),
    (match) => '`[${match.group(1)}]`',
  );
  normalized = normalized.replaceAllMapped(
    _squareBracketLiteralRegExp,
    (match) => '`[${match.group(1)}]`',
  );
  normalized = normalized.replaceAll(_whitespaceRegExp, ' ');
  return normalized.trim();
}

String _normalizeCodeLine(String line) {
  return line.replaceAll(r'\n', '').trimRight();
}

String? _normalizeCodeBlockLanguage(String? language) {
  if (language == null) {
    return null;
  }

  final normalized = language.trim();
  if (normalized.isEmpty) {
    return null;
  }

  return normalized.startsWith('.') ? normalized.substring(1) : normalized;
}

String _mergeDocText(String current, String next) {
  if (current.isEmpty) {
    return next;
  }
  if (next.isEmpty) {
    return current;
  }
  return '$current $next';
}

String _uppercaseFirst(String value) {
  if (value.isEmpty) {
    return value;
  }
  return '${value[0].toUpperCase()}${value.substring(1)}';
}
