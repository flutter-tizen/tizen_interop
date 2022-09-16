// Copyright 2021 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import 'dart:io' show Platform;

import 'package:args/args.dart';
import 'package:file/file.dart';
import 'package:file/local.dart';
import 'package:yaml/yaml.dart';

class Config {
  String get name => _name;
  late final String _name;

  String get output => _output;
  late final String _output;

  final List<String> allowlist = <String>[];

  String get libraryPath => _libraryPath;
  late final String _libraryPath;

  List<String> get targetLibraries => _targetLibraries;
  late final List<String> _targetLibraries;

  String get preamble => _preamble;
  late final String _preamble;

  Config._();

  factory Config.fromYaml(String yaml, {ArgResults? argResults}) {
    return Config.fromYamlMap(
      loadYaml(yaml) as YamlMap,
      argResults: argResults,
    );
  }

  factory Config.fromYamlMap(YamlMap map, {ArgResults? argResults}) {
    final config = Config._();

    config._name = map.getValue('name');

    config._output = argResults?['output'] ??
        _mapEnvironmentVariables(map.getValue('output'));

    config._libraryPath = argResults?['library-path'] ??
        _mapEnvironmentVariables(map.getValue('library-path'));

    config.allowlist.addAll(_readAllowlistFile(
      argResults?['allowlist'] ?? map.getValue('allowlist', mandatory: false),
    ));

    config._targetLibraries =
        List.unmodifiable(map.getValue('target-libraries'));

    config._preamble =
        map.getValue('preamble', mandatory: false, defaultValue: '');

    return config;
  }

  static String? _mapEnvironmentVariables(String? value) {
    if (value == null || !value.contains('\${')) {
      return value;
    }
    for (var key in Platform.environment.keys) {
      value = value!.replaceAll('\${$key}', Platform.environment[key]!);
    }
    return value;
  }

  static List<String> _readAllowlistFile(String? path) {
    if (path == null) {
      return <String>[];
    }
    final file = LocalFileSystem().file(path);
    if (!file.existsSync()) {
      throw FileSystemException('Could not find the allowlist file', path);
    }
    return file.readAsLinesSync();
  }
}

extension _YamlMapExtensions on YamlMap {
  dynamic getValue(String key, {dynamic defaultValue, bool mandatory = true}) {
    dynamic value = this[key];
    if (value == null) {
      if (defaultValue == null && mandatory) {
        throw StateError('$key not found');
      }
      value = defaultValue;
    }
    return value;
  }
}
