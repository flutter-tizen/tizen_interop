// Copyright 2021 Samsung Electronics Co., Ltd. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Executable script to generate symbol mapping for shared libraries.

import 'dart:io';
import 'package:args/args.dart';

import 'config.dart';
import 'generator.dart';

void main(List<String> args) {
  final argResults = _parseArguments(args);

  final configFile = File(argResults['config']);
  if (!configFile.existsSync()) {
    print('Error: $configFile not found.');
    exit(1);
  }

  Config config;
  try {
    config = Config.fromYaml(
      configFile.readAsStringSync(),
      argResults: argResults,
    );
  } catch (e) {
    print(e);
    print('Error: Please fix configuration errors and re-run the tool.');
    exit(1);
  }

  final generator = CodeGenerator(config);
  generator.generate();
}

ArgResults _parseArguments(List<String> args) {
  final parser = ArgParser(allowTrailingOptions: true)
    ..addFlag(
      'help',
      abbr: 'h',
      help: 'Print this usage.',
      negatable: false,
    )
    ..addOption(
      'config',
      help: 'Path to Yaml file containing configurations.',
      mandatory: true,
    )
    ..addOption(
      'output',
      help: 'Override the output value set in configrations.',
      mandatory: false,
    )
    ..addOption(
      'library-path',
      help: 'Override the library-path value set in configrations.',
      mandatory: false,
    )
    ..addOption(
      'allowlist',
      help: 'Override the allow value set in configrations.',
      mandatory: false,
    );

  ArgResults results;
  try {
    results = parser.parse(args);
    if (results.wasParsed('help')) {
      print(parser.usage);
      exit(0);
    }
  } catch (e) {
    print(e);
    print(parser.usage);
    exit(1);
  }

  return results;
}
