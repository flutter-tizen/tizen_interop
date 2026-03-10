# Flutter-tizen tizen_interop Style Guide & Review Agent Guidelines

## Introduction

This document outlines the coding conventions and Review Bot (Gemini) guidelines for contributions to the `flutter-tizen/tizen_interop` repository. This repository primarily deals with Dart FFI (Foreign Function Interface) bindings for Tizen Native C APIs.

## Style Guides

Code should follow the relevant style guides and use the correct auto-formatter for each language.

- **Dart:** Follow the [Flutter styleguide](https://github.com/flutter/flutter/blob/main/docs/contributing/Style-guide-for-Flutter-repo.md) as the first priority. [Effective Dart: Style](https://dart.dev/effective-dart/style) applies where it does not conflict.
- **C/C++:** Formatted using `clang-format`, linted with `clang-tidy`, and must follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Python code is formatted using `yapf`, linted with `pylint`, and should follow the [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html).

## Best Practices for tizen_interop

Since this project heavily relies on Dart FFI to wrap Tizen C APIs, contributors and reviewers must strictly adhere to the following:

- **Memory Management:** Ensure that any memory allocated in C (e.g., `malloc`) or Dart (e.g., `calloc`, `malloc.allocate`) across the FFI boundary is explicitly and safely freed.
- **Pointer Safety:** Validate all pointers passed to Tizen APIs. Avoid dangling pointers and ensure null checks are in place before dereferencing.
- **Error Handling:** Tizen C APIs typically return error codes (e.g., `TIZEN_ERROR_NONE`). Interop code must check these return values and translate them into meaningful Dart Exceptions.

## Gemini Review Agent Guidelines

The Gemini review agent is integrated to assist maintainers by performing automated code reviews. When generating a review or summary, the agent **MUST** adhere to the following principles:

### 1. Scope and Tone
- **Target Branch:** Only review changes targeting the `master` branch.
- **Be Objective & Code-Driven:** Focus strictly on the code diff. Report what the code does and identify factual anomalies without subjective judgments ("good", "bad"). Do not rely on the PR description as the absolute truth.
- **Actionable Feedback:** If an issue is found, provide a concise explanation of *why* it is an issue and suggest a direct code fix.

### 2. Domain-Specific Code Review Rules
The agent must prioritize checking the following areas:
- **FFI Safety Checks:** Scrutinize all `dart:ffi` usage. Flag any missing `free()` or `malloc.free()` calls corresponding to allocations.
- **Tizen API Compatibility:** Ensure that the wrapped Tizen APIs are used according to standard Tizen Native documentation.
- **Resource Leaks:** Explicitly check for unclosed Tizen handles or unreleased resources in both Dart and C/C++ layers.

### 3. Temporary Dependency Overrides
- Do not flag or comment on `dependency_overrides` in `pubspec.yaml` if they are accompanied by a comment starting with: `"FOR TESTING AND INITIAL REVIEW ONLY. DO NOT MERGE."`

## Documentation

- **Document Public APIs:** All public FFI bindings and wrapper classes must be documented using `///`.
- **Explain the "Why":** Documentation should explain not just what the Tizen API does, but *why* and *how* it is mapped to Dart.
- **Provide Sample Code:** Use `{@tool dartpad}` or standard markdown code blocks for runnable examples demonstrating how to use the interop functions.

## Further Reading

- [Dart FFI Documentation](https://dart.dev/guides/libraries/c-interop)
- [Tizen Native API Reference](https://docs.tizen.org/application/native/)
- [Style guide for the Flutter repository](https://github.com/flutter/flutter/blob/main/docs/contributing/Style-guide-for-Flutter-repo.md)
