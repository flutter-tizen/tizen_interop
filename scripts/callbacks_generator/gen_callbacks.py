#!/usr/bin/env python3
# Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import os
import sys
import copy
import glob
import yaml
import logging
import argparse
from io import StringIO
from typing import List, Mapping, Callable, Set

log = logging.getLogger('gen_callbacks')

PROXY_INSTANCES_COUNT = 5

# Callbacks which have user_data parameter, but are not detected:
CB_USER_DATA_OVERRIDES = {
    'ime_language_requested_cb',
    'ime_imdata_requested_cb',
    'ime_geometry_requested_cb',
    'image_util_decode_completed_cb',
    'image_util_encode_completed_cb',
}

CB_PARAMETER_PATCHES: Mapping[str, Callable] = {
    'sensor_accuracy_changed_cb':
        lambda cb: cb.params[-1].set_name('user_data'),
    'system_settings_iter_cb':
        lambda cb: cb.params[-1].set_name('user_data'),
    'sensor_events_cb':
        lambda cb: cb.params[1].set_type('sensor_event_s*').set_name('events'),
    'mv_barcode_detected_cb':
        lambda cb: cb.params[3].set_type('const char**').set_name('messages'),
}

KNOWN_TYPES = {
    'bool',
    'bool*',
    'char*',
    'char**',
    'double',
    'float*',
    'float**',
    'int',
    'int*',
    'long',
    'long long',
    'unsigned',
    'unsigned char',
    'unsigned char*',
    'unsigned char**',
    'unsigned int',
    'unsigned int*',
    'unsigned long',
    'unsigned long long',
    'unsigned short',
    'void',
    'void*',
    'void**',
    'bool',
    'bool*',
    'char*',
    'char**',
    'double',
    'float*',
    'float**',
    'int',
    'int*',
    'long',
    'long long',
    'size_t',
    'time_t',
    'unsigned',
    'unsigned char',
    'unsigned char*',
    'unsigned char**',
    'unsigned int',
    'unsigned int*',
    'unsigned long',
    'unsigned long long',
    'unsigned short',
    'void',
    'void*',
    'void**',
    'size_t',
    'time_t',
}

SPECIAL_TYPES = {
    'dnssd_browser_h': 'unsigned int',
    'dnssd_service_h': 'unsigned int',
    'mtp_device_h': 'int',
    'mtp_object_h': 'int',
    'mtp_storage_h': 'int',
    'ssdp_browser_h': 'unsigned int',
    'ssdp_service_h': 'unsigned int',
    'result_set_cursor': 'void*',
    'stte_result_time_cb': 'void*',
    'stte_supported_language_cb': 'void*',
    'ttse_supported_voice_cb': 'void*',
    'vce_supported_language_cb': 'void*',
    'Ecore_IMF_Input_Hints': 'some_enum',
    'Ecore_IMF_Input_Panel_Lang': 'some_enum',
    'Ecore_IMF_Input_Panel_Layout': 'some_enum',
    'Ecore_IMF_Input_Panel_Return_Key_Type': 'some_enum',
    'eom_output_id': 'unsigned int',
    'location_coords_s': 'location_coords_s_copy',
    'mv_rectangle_s': 'mv_rectangle_s_copy',
    'wifi_direct_connection_state_cb_data_s': 'wifi_direct_connection_state_cb_data_s_copy',
}

EXTRA_HEADERS = {
    '5.0': [
    ],
}


class Token:
  def __init__(self, _type):
    self._type = _type
    self.word = ''
    self.contents = ''

  def __repr__(self):
    if self._type == 'W':
      return '<W %s>' % (self.word)
    elif self._type == 'X':
      return '<X %s>' % (self.contents)
    else:
      return '<%s>' % (self._type)

  def __eq__(self, other):
    return self._type == other._type and \
        self.word == other.word and \
        self.contents == other.contents


class ParamInfo:
  def __init__(self, _type, name):
    self._type = _type
    self.name = name

  def __repr__(self):
    return '<P %s, %s>' % (self._type, self.name)

  def __eq__(self, other):
    return self._type == other._type and \
        self.name == other.name

  def set_name(self, name):
    self.name = name
    return self

  def set_type(self, _type):
    self._type = _type
    return self


class CallbackInfo:
  def __init__(self):
    self.filename = ''
    self.ret_type = ''
    self.name = ''
    self.params: List[ParamInfo] = []
    self._has_user_data: bool = None

  def __repr__(self):
    rep = '<CB %s %s(' % (self.ret_type, self.name)
    for i in range(0, len(self.params)):
      if i > 0:
        rep += ', '
      rep += repr(self.params[i])
    rep += ')>'
    return rep

  def __eq__(self, other):
    return self.ret_type == other.ret_type and \
        self.name == other.name and \
        self.params == other.params

  def compatible_signature(self, other):
    param_types = [p._type for p in self.params]
    param_types_other = [p._type for p in other.params]
    return self.ret_type == other.ret_type and param_types == param_types_other

  @property
  def allow_non_blocking(self):
    return self.ret_type == 'void'

  @property
  def has_user_data(self):
    if self._has_user_data is None:
      self._has_user_data = bool(
        self.params) and self.params[-1].name == 'user_data'
    return self._has_user_data

  def override_has_user_data(self, has_user_data):
    self._has_user_data = has_user_data

  @property
  def param_names(self) -> str:
    if self.params and self.params[0].name != 'void':
      return ', '.join(p.name for p in self.params)
    else:
      return ''

  @property
  def param_list(self) -> str:
    """
    Parameters to append in macro.
    """
    if not self.params or (len(self.params) == 1 and self.params[0].name == 'void'):
      return ''
    return ', ' + ', '.join('%s %s' % (p._type, p.name) for p in self.params)


class CallbackSignatureReader:
  def __init__(self, code_reader, tokens):
    self.cr = code_reader
    self.tokens = tokens
    self.cur_idx = -1
    self.params = []

  def is_end_of_param(self, token):
    return token._type == self.cr.TOKEN_COMMA or token._type == self.cr.TOKEN_PAREN_RIGHT

  # Reads parameter tokens starting at cur_idx.
  # Sets cur_idx to the ',' or ')' after the parameter.
  def read_param(self):
    t = self.tokens

    # Reading param tokens while accounting for newline tokens would make
    # the code needlessly complex.
    # Instead, we analyze param tokens with newlines removed.
    param_tokens = []   # without newlines
    i = self.cur_idx
    while not self.is_end_of_param(t[i]):
      if t[i]._type != self.cr.TOKEN_NEWLINE:
        param_tokens.append(t[i])
      i += 1
    self.cur_idx = i

    _type = ''
    pt = param_tokens
    # len(pt) - 1 because the last token is the name,
    # all others before it are parts of type.
    for i in range(0, len(pt) - 1):
      if pt[i]._type == self.cr.TOKEN_WORD:
        _type += ' '
        _type += pt[i].word
      else:  # This is an asterisk
        if _type.endswith('*'):
          _type += '*'
        else:
          _type += ' *'

    name = pt[-1].word
    self.params.append(ParamInfo(_type.strip(), name))

  def read_signature(self, typedef_token_idx):
    t = self.tokens
    cb_info = CallbackInfo()
    cb_info.filename = self.cr.filename

    # Set cur_idx so that we are at 'typedef':
    # typedef void (*done_cb)(int id, void *user_data);
    # ^^^^^^^
    self.cur_idx = typedef_token_idx

    # Move until we find a word (skips newline tokens):
    # typedef void (*done_cb)(int id, void *user_data);
    #         ^^^^
    self.cur_idx += 1
    while t[self.cur_idx]._type != self.cr.TOKEN_WORD:
      self.cur_idx += 1

    cb_info.ret_type = t[self.cur_idx].word

    # Move until we find the next word, which will be the callback's name:
    # typedef void (*done_cb)(int id, void *user_data);
    #                ^^^^^^^
    self.cur_idx += 1
    while t[self.cur_idx]._type != self.cr.TOKEN_WORD:
      self.cur_idx += 1

    cb_info.name = t[self.cur_idx].word

    # Move until we find '(', which opens the parameters.
    # Then move to the next token, which will be type of the first parameter:
    # typedef void (*done_cb)(int id, void *user_data);
    #                         ^^^
    # Or, in case of a parameterless callback, the closing ')':
    # typedef void (*done_cb)();
    #                         ^
    self.cur_idx += 1
    while t[self.cur_idx]._type != self.cr.TOKEN_PAREN_LEFT:
      self.cur_idx += 1
    self.cur_idx += 1

    # Read parameters until we reach the closing ')'.
    while t[self.cur_idx]._type != self.cr.TOKEN_PAREN_RIGHT:
      self.read_param()
      if t[self.cur_idx]._type == self.cr.TOKEN_COMMA:
        # We are here:
        # typedef void (*done_cb)(int id, void *user_data);
        #                               ^

        # Move to the next parameter (skip newlines)
        while t[self.cur_idx]._type != self.cr.TOKEN_WORD:
          self.cur_idx += 1

    # We are now here:
    # typedef void (*done_cb)(int id, void *user_data);
    #                                                ^

    for p in self.params:
      cb_info.params.append(p)

    return cb_info


class CodeReader:
  def __init__(self):
    self.filename = ''
    self.string = ''
    self.tokens = []

    # Key: handle name, value: underlying type
    # Example:
    # typedef void *handle_h;
    # Key: 'handle_h', value: 'void *'
    self.handles = {}

    self.callbacks = []

    self.TOKEN_WORD = 'W'
    self.TOKEN_NEWLINE = '\n'
    self.TOKEN_ASTERISK = '*'
    self.TOKEN_COMMA = ','
    self.TOKEN_PERIOD = '.'
    self.TOKEN_SEMICOLON = ';'
    self.TOKEN_PAREN_LEFT = '('
    self.TOKEN_PAREN_RIGHT = ')'
    self.TOKEN_BRACE_LEFT = '{'
    self.TOKEN_BRACE_RIGHT = '}'
    self.TOKEN_BRACKET_LEFT = '['
    self.TOKEN_BRACKET_RIGHT = ']'
    self.TOKEN_LINE_CMNT_START = '//'
    self.TOKEN_COMMENT_START = '/*'
    self.TOKEN_DOXYGEN_CMNT_START = '/**'
    self.TOKEN_COMMENT_END = '*/'
    self.TOKEN_AT = '@'
    self.TOKEN_OTHER = 'X'

  def read_file(self, filename):
    self.filename = filename
    f = open(filename, encoding='UTF-8')
    self.string = f.read()
    f.close()

  @classmethod
  def read_callbacks_from_string(class_, code):
    cr = class_()
    cr.filename = '<code>'
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()
    return cr.callbacks

  def is_part_of_word(self, c, is_first_char):
    if is_first_char:
      return c.isalpha() or c == '_'
    else:
      return c.isalnum() or c == '_'

  def tokenize(self):
    self.tokens = []
    cur_word = ''
    s = self.string + '  '  # two spaces allow safe checks for '/**'
    slen = len(s)
    i = 0
    while i < slen:
      c = s[i]

      is_first_word_char = cur_word == ''
      if self.is_part_of_word(c, is_first_word_char):
        cur_word += c
        i += 1
        continue
      else:
        if cur_word != '':
          t = Token(self.TOKEN_WORD)
          t.word = cur_word
          self.tokens.append(t)
          cur_word = ''

      if c.isspace():
        if c == '\n':
          # Why store newlines as tokens while ignoring other whitespace
          # characters?
          # Newlines are needed for detecting '//' comments.
          # Also, if we wanted to detect asterisks that are part of a multi-line
          # comment:
          # /**
          #  *
          #  */
          # then newlines are going to be useful.
          self.tokens.append(Token(self.TOKEN_NEWLINE))
        i += 1
        continue
      elif c == '*':
        if s[i + 1] == '/':
          self.tokens.append(Token(self.TOKEN_COMMENT_END))
          i += 2  # skip one character, as we have a two-char token '*/'
          continue
        else:
          self.tokens.append(Token(self.TOKEN_ASTERISK))
          i += 1
          continue
      elif c == ',':
        self.tokens.append(Token(self.TOKEN_COMMA))
        i += 1
        continue
      elif c == '.':
        self.tokens.append(Token(self.TOKEN_PERIOD))
        i += 1
        continue
      elif c == ';':
        self.tokens.append(Token(self.TOKEN_SEMICOLON))
        i += 1
        continue
      elif c == '(':
        self.tokens.append(Token(self.TOKEN_PAREN_LEFT))
        i += 1
        continue
      elif c == ')':
        self.tokens.append(Token(self.TOKEN_PAREN_RIGHT))
        i += 1
        continue
      elif c == '{':
        self.tokens.append(Token(self.TOKEN_BRACE_LEFT))
        i += 1
        continue
      elif c == '}':
        self.tokens.append(Token(self.TOKEN_BRACE_RIGHT))
        i += 1
        continue
      elif c == '[':
        self.tokens.append(Token(self.TOKEN_BRACKET_LEFT))
        i += 1
        continue
      elif c == ']':
        self.tokens.append(Token(self.TOKEN_BRACKET_RIGHT))
        i += 1
        continue
      elif c == '/':
        if s[i + 1] == '/':
          self.tokens.append(Token(self.TOKEN_LINE_CMNT_START))
          i += 2  # skip one character, as we have a two-char token '//'
          continue
        elif s[i + 1] == '*' and s[i + 2] != '*':
          self.tokens.append(Token(self.TOKEN_COMMENT_START))
          i += 2  # skip one character, as we have a two-char token '/*'
          continue
        elif s[i + 1] == '*' and s[i + 2] == '*':
          self.tokens.append(Token(self.TOKEN_DOXYGEN_CMNT_START))
          i += 3  # skip two characters, as we have a three-char token '/**'
          continue
        else:
          t = Token(self.TOKEN_OTHER)
          t.contents = '/'
          self.tokens.append(t)
          i += 1
          continue
      elif c == '@':
        self.tokens.append(Token(self.TOKEN_AT))
        i += 1
        continue
      else:
        t = Token(self.TOKEN_OTHER)
        t.contents = c
        self.tokens.append(t)
        i += 1
        continue

  def read_comment(self, idx):
    # idx is at '/*' or '/**'

    # Move until '*/' is found.
    # We assume that comments have the closing '*/'.
    t = self.tokens
    while t[idx]._type != self.TOKEN_COMMENT_END:
      idx += 1

    # Move to the token after '*/'.
    idx += 1

    return idx

  def read_line_comment(self, idx):
    # idx is at '//'

    # Move until newline or end of file is found.
    t = self.tokens
    while t[idx]._type != self.TOKEN_NEWLINE and idx < len(t) - 1:
      idx += 1

    # Move to the token after newline/eof.
    # This is ok, because the loop in find_typedefs() will stop if token
    # index is out of range.
    idx += 1

    return idx

  def is_callback_typedef(self, idx):
    t = self.tokens

    # We need 3 non-newline tokens after 'typedef'.
    # It's unlikely but possible that multi-line signature of a callback
    # will include the 'typedef void (*' part split by newlines.

    nnt = []  # no newline tokens
    i = idx + 1
    while len(nnt) < 3:
      if t[i]._type != self.TOKEN_NEWLINE:
        nnt.append(t[i])
      i += 1

    return nnt[0]._type == self.TOKEN_WORD and \
        nnt[1]._type == self.TOKEN_PAREN_LEFT and \
        nnt[2]._type == self.TOKEN_ASTERISK

  # Also detects enums and unions.
  # If we have a '{' in the definition, that means this is a struct/
  # enum/union. We look for it until we reach ';'.
  def is_struct_typedef(self, idx):
    t = self.tokens
    i = idx
    while t[i]._type != self.TOKEN_SEMICOLON:
      # We could account for a newline between '}' and ';', but that
      # doesn't occur in the API.
      if t[i]._type == self.TOKEN_BRACE_LEFT:
        return True
      i += 1
    return False

  # In this method, if we have
  # typedef void *handle_h;
  # by "name" (handle name) we mean handle_h, and by "_type" (underlying type)
  # we mean "void *".
  def read_handle(self, idx):
    t = self.tokens
    _type = ''
    i = idx + 1  # idx is at the word 'typedef', skip to start reading type
    while t[i]._type != self.TOKEN_SEMICOLON:
      if t[i + 1]._type == self.TOKEN_SEMICOLON:
        # We are at the last token before ';' which means this is the name
        # of the handle type and the underlying type was already read.
        # We've found all we need, we add the handle to found handles.
        name = t[i].word
        self.handles[name] = _type.strip()
        return
      else:
        # We are not at the handle name yet, this is part of the
        # underlying type.
        if t[i]._type == self.TOKEN_WORD:
          _type += ' '
          _type += t[i].word
        elif t[i]._type == self.TOKEN_ASTERISK:
          if _type.endswith('*'):
            _type += '*'
          else:
            _type += ' *'
        i += 1

  def find_typedefs(self):
    t = self.tokens
    i = 0
    while i < len(t):
      _type = t[i]._type
      if _type == self.TOKEN_LINE_CMNT_START:
        i = self.read_line_comment(i)
        continue
      elif _type == self.TOKEN_COMMENT_START or _type == self.TOKEN_DOXYGEN_CMNT_START:
        i = self.read_comment(i)
        continue
      elif t[i]._type != self.TOKEN_WORD:
        i += 1
        continue
      elif t[i].word != 'typedef':
        i += 1
        continue
      elif self.is_callback_typedef(i):
        csr = CallbackSignatureReader(self, self.tokens)
        cb_info = csr.read_signature(i)
        self.callbacks.append(cb_info)
      # If a typedef is not a callback, and is not a struct/enum/union type,
      # then it's likely a definition we're interested in - a handle:
      # typedef void *handle_h;
      elif not self.is_struct_typedef(i):
        self.read_handle(i)

      i += 1


class CallbackDataCollector:
  def __init__(self):
    self.callbacks: Mapping[str, CallbackInfo] = {}
    self.types = {}
    self.no_user_data_callbacks = set()
    self.versions = []
    self.version = None
    self._used_type_mapping = None
    self.loaded_headers = []
    self.allowed_names: Set[str] = []

  def set_version(self, version):
    self.version = version
    if version not in self.versions:
      self.versions.append(version)

  def enable_asserts(self):
    self._used_type_mapping = set()

  def load_headers(self, headers):
    cr = CodeReader()
    for f in headers:
      cr.read_file(f)
      cr.tokenize()
      cr.find_typedefs()
      self.loaded_headers.append(f)

    for cb in cr.callbacks:
      if cb.name in self.callbacks:
        if not cb.compatible_signature(self.callbacks[cb.name]):
          log.warn('Callback %s signature mismatch %s\n\t%s\n\t%s',
                   self.version, cb.name, repr(cb), repr(self.callbacks[cb.name]))
      else:
        self.callbacks[cb.name] = cb

  def preprocess_callbacks_data(self):
    if self._used_type_mapping is not None:
      callbacks_before_rewrite = copy.deepcopy(self.callbacks)
    if self.allowed_names:
      names = set(self.callbacks)
      not_allowed_names = names.difference(self.allowed_names)
      if not_allowed_names:
        log.debug('Ignoring following names not found in bindinds: %s', not_allowed_names)
        for name in not_allowed_names:
          del self.callbacks[name]

    for name, cb in self.callbacks.items():

      patch = CB_PARAMETER_PATCHES.get(name)
      if patch:
        patch(cb)

      if name in CB_USER_DATA_OVERRIDES:
        cb.override_has_user_data(True)

      if not cb.has_user_data:
        self.no_user_data_callbacks.add(name)

      self.rewrite_types(cb)

    if self._used_type_mapping is not None:
      for name, cb in self.callbacks.items():
        original_cb = callbacks_before_rewrite[name]
        self._used_type_mapping.add((original_cb.ret_type, cb.ret_type))
        for param, original_param in zip(cb.params, original_cb.params):
          self._used_type_mapping.add((original_param._type, param._type))

  def get_type_mapping(self):
    const_items = set(
      item for item in self._used_type_mapping if item[0].startswith('const '))
    self._used_type_mapping.difference_update(const_items)
    self._used_type_mapping.update(
        set((item[0].replace('const ', ''), item[1].replace('const ', ''))
            for item in const_items)
    )
    if self._used_type_mapping is not None:
      for item in sorted(self._used_type_mapping):
        if item[0] == item[1] or item[0].replace(' ', '') == item[1].replace(' ', ''):
          continue

        # FIXME: those exceptions are probably results of issue with paramter parsing
        if item[0] == 'char * messages *':
          yield 'char **', item[1]
        elif item[0] == 'sensor_event_s events *':
          yield 'sensor_event_s*', item[1]
        else:
          yield item

  def set_bindings_filter(self, bindings_file_paths: List[str]):
    names = set()
    for bindings_path in bindings_file_paths:
      with open(bindings_path) as bindings_file:
        for line in bindings_file:
          if line.startswith('typedef '):
            names.add(line.split()[1])

    self.allowed_names = names

  @classmethod
  def rewrite_types(class_, cb: CallbackInfo):
    cb.ret_type = class_.type_substitute(cb.ret_type)
    if cb.ret_type == 'void*':
      cb.ret_type = 'void_pointer'
    elif cb.ret_type.endswith('*'):
      log.error(
        'Callback %s returns pointer: %s. Please add typedef for it.', cb.name, cb.ret_type)
    for param in cb.params:
      if param.name == 'void':
        return
      param.set_type(class_.type_substitute(param._type))

  @classmethod
  def type_substitute(class_, t):
    t = t.strip().replace(' *', '*')
    if t.startswith('const '):
      inner = t[5:]
      if inner in KNOWN_TYPES:
        return t
      else:
        return 'const ' + class_.type_substitute(inner)
    elif t in KNOWN_TYPES:
      return t
    elif t in SPECIAL_TYPES:
      return SPECIAL_TYPES[t]
    elif t.endswith('*') or t.endswith('_h'):
      return 'void*'
    elif t.endswith('_e'):
      return 'some_enum'
    log.error('Failed to map type `%s`.', t)
    return t


class CallbackGenerator:
  def __init__(self, callbacks):
    self.filenames = []
    self.callbacks = callbacks
    self.out = StringIO()
    self.callback_id = 0
    self.no_user_data_callbacks = set()
    self.map_entries = []

  def writeln(self, *args):
    print(*args, file=self.out)

  def write_reserved_callback_id(self, cb):
    self.writeln(f'#define BASE_CALLBACK_ID_{cb.name} {self.callback_id}')
    self.callback_id += PROXY_INSTANCES_COUNT
    self.no_user_data_callbacks.add(cb.name)

  def generate_single_callback_code_non_blocking(self, cb: CallbackInfo):
    if cb.has_user_data:
      self.writeln(f'PROXY_GROUP_NON_BLOCKING({cb.name}{cb.param_list})')
    else:
      self.writeln(
        f'PROXY_GROUP_NON_BLOCKING_NO_USER_DATA({cb.name}{cb.param_list})')

    self.map_entries.append((cb.name, f'platform_non_blocking_{cb.name}'))

  def generate_single_callback_code_blocking(self, cb: CallbackInfo):
    if cb.ret_type == 'void':
      if cb.has_user_data:
        self.writeln(f'PROXY_GROUP_BLOCKING({cb.name}{cb.param_list})')
      elif cb.param_list:
        self.writeln(
          f'PROXY_GROUP_BLOCKING_NO_USER_DATA({cb.name}{cb.param_list})')
      else:
        raise NotImplementedError(
          'NO return AND no params is not supported: ' + cb.name)
    else:
      if cb.has_user_data:
        self.writeln(
          f'PROXY_GROUP_RETURN({cb.name}, {cb.ret_type}{cb.param_list})')
      elif cb.param_list:
        self.writeln(
          f'PROXY_GROUP_RETURN_NO_USER_DATA({cb.name}, {cb.ret_type}{cb.param_list})')
      else:
        self.writeln(
          f'PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM({cb.name}, {cb.ret_type})')
    self.map_entries.append((cb.name, f'platform_blocking_{cb.name}'))

  def generate_single_callback_code(self, cb: CallbackInfo):
    if not cb.has_user_data:
      self.write_reserved_callback_id(cb)
    self.writeln(
      f'typedef {cb.ret_type} (*{cb.name})({cb.param_list.lstrip(", ")});')

    has_params = bool(cb.param_list)
    if has_params:
      self.writeln(f'#define CB_PARAMS_NAMES {cb.param_names}')

    if cb.allow_non_blocking:
      self.generate_single_callback_code_non_blocking(cb)
    self.generate_single_callback_code_blocking(cb)

    if has_params:
      self.writeln('#undef CB_PARAMS_NAMES\n')
    else:
      self.writeln()

  def generate_callbacks(self):
    for cb in sorted(self.callbacks, key=lambda cb: cb.name):
      self.generate_single_callback_code(cb)
    return self.out

  def process_files(self, filenames, headers_prepend={}):
    self.filenames = filenames

    cr = CodeReader()
    for f in filenames:
      cr.read_file(f)
      cr.tokenize()
      cr.find_typedefs()

    self.callbacks = cr.callbacks

    if self.callbacks:
      for f in sorted(self.filenames):
        if 'rootstrap' in f and '/usr/include/' in f:
          header = f[f.index('/usr/include/') + 13:]
          if header in headers_prepend:
            for h in headers_prepend[header]:
              self.writeln('#include <%s>' % h)
          self.writeln('#include <%s>\n' % header)

    return self.generate_callbacks()

  def generate_full_source(self, api):
    generate_preamble(self.out)
    print(f'static_assert(kProxyInstanceCount == {PROXY_INSTANCES_COUNT}, "Callbacks instances count mismatch");',
          file=self.out)
    print(
      f'static constexpr int32_t kNoUserDataCallbackCount = {len(api.no_user_data_callbacks)};\n', file=self.out)
    print(
      'uint32_t reserved_callback_ids[kProxyInstanceCount * kNoUserDataCallbackCount] = {};\n', file=self.out)
    self.generate_callbacks()
    print(
      '\nstd::map<std::string, MultiProxyFunctionsContainer> multi_proxy_map = {', file=self.out)
    for cb in sorted(self.callbacks, key=lambda cb: cb.name):
      print(
        f'  MULTI_PROXY_MAP_ENTRY(platform_blocking_{cb.name})', file=self.out)
      if cb.allow_non_blocking:
        print(
          f'  MULTI_PROXY_MAP_ENTRY(platform_non_blocking_{cb.name})', file=self.out)
    print('};\n', file=self.out)
    print(
      'std::map<std::string, int> reserved_base_id_map = {', file=self.out)
    for cb in sorted(api.no_user_data_callbacks):
      print(f'  {{"{cb}", BASE_CALLBACK_ID_{cb}}},', file=self.out)
    print('};', file=self.out)
    log.info(f'Generated code for {len(api.callbacks)} callbacks.')

  @staticmethod
  def generate_from_collector(api: CallbackDataCollector, output):
    api.preprocess_callbacks_data()
    cg = CallbackGenerator(list(api.callbacks.values()))
    cg.out = output
    cg.generate_full_source(api)

  @staticmethod
  def generate_asserts_from_collector(api: CallbackDataCollector, output, args):
    entrypoints = os.path.join(os.path.dirname(args.config[0]), 'entrypoints.h')
    if not os.path.exists(entrypoints):
      log.error('Entrypoints header not found (%s)', entrypoints)
      sys.exit(3)
    version = os.path.basename(os.path.dirname(args.config[0]))
    api.enable_asserts()
    api.preprocess_callbacks_data()
    cg = CallbackGenerator(list(api.callbacks.values()))
    cg.out = output
    generate_preamble(output)
    output.write(
      f'static constexpr int32_t kNoUserDataCallbackCount = {len(api.no_user_data_callbacks)};\n')
    output.write(
      'int reserved_callback_ids[kProxyInstanceCount * kNoUserDataCallbackCount];\n')
    output.write(
      'std::map<std::string, MultiProxyFunctionsContainer> multi_proxy_map;\n')
    output.write('std::map<std::string, int> reserved_base_id_map;\n\n')
    output.write('#undef TIZEN_DEPRECATION\n#undef DEPRECATION_WARNING\n')
    output.write(f'#include "{entrypoints}"\n')
    for header in EXTRA_HEADERS.get(version, []):
        output.write(f'#include "{header}"\n')
    output.write('\n')
    for type1, type2 in api.get_type_mapping():
      output.write(f'static_assert(sizeof({type1}) == sizeof({type2}), "Wrong '
                   f'type substitution - {type1} and {type2} have different sizes.");\n')
    log.info(f'Generated asserts for {len(api.callbacks)} callbacks.')


def generate_preamble(output):
  print('#include "tizen_interop_callbacks_plugin.h"\n', file=output)
  print('#include <cstdint>', file=output)
  print('#include <map>', file=output)
  print('#include <string>\n', file=output)
  print('#include "macros.h"', file=output)
  print('#include "types.h"\n', file=output)


def find_headers_by_config(config_path):
  log.info('Processing config file: %s', config_path)
  root_dir = os.path.relpath(os.path.join(
    os.path.dirname(config_path), os.pardir, os.pardir))
  log.debug('Root dir: %s', root_dir)
  api_version = os.path.basename(os.path.dirname(os.path.abspath(config_path)))
  log.debug('API version: %s', api_version)
  rootstrap_include = os.path.join(
    root_dir, 'rootstraps', api_version, 'usr', 'include')
  if not os.path.isdir(rootstrap_include):
    log.error('Rootstrap not found. There is no directory %s', rootstrap_include)
    return

  with open(config_path) as ffigen_conf_file:
    ffigen_config = yaml.safe_load(ffigen_conf_file)

  selected = ffigen_config['headers']['include-directives']
  files_to_find = set()
  dirs_to_find = set()
  for pattern in selected:
    assert pattern.startswith('**/')
    if pattern.endswith('/*.h'):
      log.debug('DIR %s', pattern[3:-4])
      dirs_to_find.add('/' + pattern[3:-4])
    elif pattern.endswith('.h') and pattern.count('/') == 1:
      log.debug('FILE %s', pattern[3:])
      files_to_find.add(pattern[3:])
    else:
      raise NotImplementedError(
        f'config include-directives `{pattern}` not supported')

  items = set()

  for directory, _, files in os.walk(rootstrap_include):
    match = files_to_find.intersection(files)
    if match:
      log.debug('%s %d %d', match, len(match), len(files_to_find))
      items.update(os.path.join(directory, m) for m in match)
    for p in dirs_to_find:
      if directory.endswith(p):
        log.debug('--- %s [%s] %s', directory, p, files)
        items.add(os.path.join(directory, '*.h'))
        break
  return api_version, rootstrap_include, items


def process_configs(args):
  config_paths = args.config
  for config_path in config_paths:
    file_is_missing = False
    if not os.path.exists(config_path):
      log.error('Config file does not exist: %s', config_path)
      file_is_missing = True
    if file_is_missing:
      return

  api = CallbackDataCollector()
  for config_path in config_paths:
    res = find_headers_by_config(config_path)
    if not res:
      return
    api_version, rootstrap_include, items = res
    api.set_version(api_version)
    for item in items:
      api.load_headers(glob.glob(item))

  if args.bindings:
    api.set_bindings_filter(args.bindings)
  if args.output:
    output = open(args.output, 'w')
  else:
    output = sys.stdout
  if args.asserts:
    CallbackGenerator.generate_asserts_from_collector(api, output, args)
  else:
    CallbackGenerator.generate_from_collector(api, output)
  if args.output:
    output.close()


def main(argv):
  parser = argparse.ArgumentParser()
  parser.add_argument('-c', '--config', action='append', default=[])
  parser.add_argument('-o', '--output')
  parser.add_argument('-v', '--verbose', action='store_true')
  parser.add_argument('-a', '--asserts',
                      help='Generate asserts to verify type substitution')
  parser.add_argument('-b', '--bindings', action='append', default=[],
                      help='Filter callbacks using generated bindings dart file(s)')
  parser.add_argument('files', nargs='*')
  args = parser.parse_args(argv)
  logging.basicConfig(level=logging.DEBUG if args.verbose else logging.INFO)
  if args.config:
    process_configs(args)
  elif args.files:
    cg = CallbackGenerator([])
    if args.bindings:
      cg.set_bindings_filter(args.bindings)
    res = cg.process_files(args.files).getvalue()
    print(res)


if __name__ == '__main__':
  sys.exit(main(sys.argv[1:]))
