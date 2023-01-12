#!/usr/bin/env python3

import os
import sys
import glob
import yaml
import logging
import argparse
from io import StringIO
from typing import List

log = logging.getLogger('gen_callbacks')
PROXY_INSTANCES_COUNT = 5


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
        return self._type == other._type and\
            self.word == other.word and\
            self.contents == other.contents


class ParamInfo:
    def __init__(self, _type, name):
        self._type = _type
        self.name = name

    def __repr__(self):
        return '<P %s, %s>' % (self._type, self.name)

    def __eq__(self, other):
        return self._type == other._type and\
                self.name == other.name


class CallbackInfo:
    def __init__(self):
        self.filename = ''
        self.ret_type = ''
        self.name = ''
        self.params: List[ParamInfo] = []

    def __repr__(self):
        rep = '<CB %s %s(' % (self.ret_type, self.name)
        for i in range(0, len(self.params)):
            if i > 0:
                rep += ', '
            rep += repr(self.params[i])
        rep += ')>'
        return rep

    def __eq__(self, other):
        return self.ret_type == other.ret_type and\
                self.name == other.name and\
                self.params == other.params

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
                if s[i+1] == '/':
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
                if s[i+1] == '/':
                    self.tokens.append(Token(self.TOKEN_LINE_CMNT_START))
                    i += 2  # skip one character, as we have a two-char token '//'
                    continue
                elif s[i+1] == '*' and s[i+2] != '*':
                    self.tokens.append(Token(self.TOKEN_COMMENT_START))
                    i += 2  # skip one character, as we have a two-char token '/*'
                    continue
                elif s[i+1] == '*' and s[i+2] == '*':
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

        return nnt[0]._type == self.TOKEN_WORD and\
                nnt[1]._type == self.TOKEN_PAREN_LEFT and\
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
            if t[i+1]._type == self.TOKEN_SEMICOLON:
                # We are at the last token before ';' which means this is the
                # name of the handle type and the underlying type was already
                # read.
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
            # If a typedef is not a callback, and is not a struct/enum/union
            # type, then it's likely a definition we're interested in -
            # a handle:
            # typedef void *handle_h;
            elif not self.is_struct_typedef(i):
                self.read_handle(i)

            i += 1


class CallbackGenerator:
    def __init__(self, handles, callbacks):
        self.filenames = []
        self.callbacks = callbacks
        self.out = StringIO()
        self.callback_id = 0
        self.no_user_data_callbacks = set()
        self.map_entries = []

    def writeln(self, *args):
        print(*args, file=self.out)

    def write_reserved_callback_id(self, cb):
        self.callback_id += PROXY_INSTANCES_COUNT
        self.writeln(f'#define BASE_CALLBACK_ID_{cb.name} {self.callback_id}')
        self.no_user_data_callbacks.add(cb.name)

    def generate_single_callback_code_non_blocking(self, cb: CallbackInfo, has_user_data=True):
        if has_user_data:
            self.writeln(f'PROXY_GROUP_NON_BLOCKING({cb.name}{cb.param_list})')
        else:
            self.writeln(f'PROXY_GROUP_NON_BLOCKING_NO_USER_DATA({cb.name}{cb.param_list})')

        self.map_entries.append((cb.name, f'platform_non_blocking_{cb.name}'))

    def generate_single_callback_code_blocking(self, cb: CallbackInfo, has_user_data=True):
        if cb.ret_type == 'void':
            if has_user_data:
                self.writeln(f'PROXY_GROUP_BLOCKING({cb.name}{cb.param_list})')
            elif cb.param_list:
                self.writeln(f'PROXY_GROUP_BLOCKING_NO_USER_DATA({cb.name}{cb.param_list})')
            else:
                raise NotImplementedError('NO return AND no params is not supported: ' + cb.name)
        else:
            if has_user_data:
                self.writeln(f'PROXY_GROUP_RETURN({cb.name}, {cb.ret_type}{cb.param_list})')
            elif cb.param_list:
                self.writeln(f'PROXY_GROUP_RETURN_NO_USER_DATA({cb.name}, {cb.ret_type}{cb.param_list})')
            else:
                self.writeln(f'PROXY_GROUP_RETURN_NO_USER_DATA_NO_PARAM({cb.name}, {cb.ret_type})')
        self.map_entries.append((cb.name, f'platform_blocking_{cb.name}'))

    def callback_info_patching(self, cb: CallbackInfo):
        if cb.name == 'sensor_accuracy_changed_cb' or cb.name == 'system_settings_iter_cb':
            cb.params[-1].name = 'user_data'
            return True
        elif cb.name == 'sensor_events_cb':
            cb.params[1] = ParamInfo('sensor_event_s*', 'events')
        elif cb.name == 'mv_barcode_detected_cb':
            cb.params[3] = ParamInfo('const char**', 'messages')

        return cb.name in {
            'ime_language_requested_cb', 'ime_imdata_requested_cb', 'ime_geometry_requested_cb',
            'image_util_decode_completed_cb', 'image_util_encode_completed_cb',
        }

    def generate_single_callback_code(self, cb: CallbackInfo):

        has_user_data = bool(cb.params) and cb.params[-1].name == 'user_data'
        has_user_data |= self.callback_info_patching(cb)

        if not has_user_data:
            self.write_reserved_callback_id(cb)

        has_params = has_user_data or cb.param_list
        if has_params:
            self.writeln(f'#define CB_PARAMS_NAMES {cb.param_names}')
        if cb.ret_type == 'void':
            self.generate_single_callback_code_non_blocking(cb, has_user_data)
            self.generate_single_callback_code_blocking(cb, has_user_data)
        else:
            self.generate_single_callback_code_blocking(cb, has_user_data)
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
                    header = f[f.index('/usr/include/')+13:]
                    if header in headers_prepend:
                        for h in headers_prepend[header]:
                            self.writeln('#include <%s>' % h)
                    self.writeln('#include <%s>\n' % header)

        return self.generate_callbacks()


def generate_preamble(output):
    print('#include "tizen_interop_callbacks_plugin.h"', file=output)
    print('#define PROXY_INSTANCES_COUNT', PROXY_INSTANCES_COUNT, file=output)
    print('#include "macros.h"\n', file=output)
    print('#include <mutex>', file=output)
    print('#include <condition_variable>\n', file=output)
    # print('extern std::map<std::string, void*> __multi_proxy_name_to_ptr_map;\n', file=output)


def process_config(config_path, exclude, preinclude):
    if not os.path.exists(config_path):
        print('ERROR: Config file does not exist:', config_path)
        return
    excluded_items = (exclude or '').split(',')
    header_include_map = {}
    if '=' in preinclude:
        for pair in preinclude.split(':'):
            header, dependencies = pair.split('=')
            header_include_map[header] = dependencies.split(',')
    log.debug('Processing config file: %s', config_path)
    root_dir = os.path.relpath(os.path.join(os.path.dirname(config_path), os.pardir, os.pardir))
    log.debug('Root dir: %s', root_dir)
    api_version = os.path.basename(os.path.dirname(os.path.abspath(config_path)))
    log.debug('API version: %s', api_version)
    rootstrap_include = os.path.join(root_dir, 'rootstraps', api_version, 'usr', 'include')
    if not os.path.isdir(rootstrap_include):
        print('ERROR: Rootstrap not found. There is no directory', rootstrap_include)
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
            assert False, pattern

    items = []

    for directory, _, files in os.walk(rootstrap_include):
        match = files_to_find.intersection(files)
        if match:
            log.debug('%s %d %d', match, len(match), len(files_to_find))
            items.extend(os.path.join(directory, m) for m in match if m not in excluded_items)
        for p in dirs_to_find:
            if directory.endswith(p):
                if p in excluded_items:
                    log.debug('skipping excluded %s', p)
                else:
                    log.debug('--- %s [%s] %s', directory, p, files)
                    items.append(os.path.join(directory, '*.h'))
                break

    if not items:
        return
    excluded_items = [os.path.join(rootstrap_include, item) for item in excluded_items]

    reserved_callback_id = 0
    no_user_data_callbacks = set()
    output = sys.stdout
    map_entries = []
    results = []
    callback_count = 0
    for item in sorted(items):
        cg = CallbackGenerator({}, [])
        cg.callback_id = reserved_callback_id
        cg.map_entries = map_entries
        cg.no_user_data_callbacks = no_user_data_callbacks
        results.append(
            cg.process_files(
                [f for f in glob.glob(item) if f not in excluded_items],
                header_include_map,
            )
        )
        reserved_callback_id = cg.callback_id
        callback_count += len(cg.callbacks)

    generate_preamble(output)
    print(f'#define NO_USER_DATA_CALLBACKS_COUNT {(reserved_callback_id) // PROXY_INSTANCES_COUNT + 1}', file=output)
    print(f'int __reserved_cb_id_array[PROXY_INSTANCES_COUNT * NO_USER_DATA_CALLBACKS_COUNT] = {{}};\n', file=output)
    for res in results:
        print(res.getvalue(), file=output)
    print(f'\nstd::map<std::string, MultiProxyFunctionsContainer> __multi_proxy_name_to_ptr_map = {{', file=output)
    for cb_name, proxy_base in sorted(map_entries):
        print(f'  MULTI_PROXY_MAP_ENTRY({proxy_base})')
    print('};\n', file=output)
    print('std::map<std::string, int> __reserved_base_id_map = {', file=output)
    for cb in sorted(no_user_data_callbacks):
        print(f'  {{std::string("{cb}"), BASE_CALLBACK_ID_{cb}}},', file=output)
    print('};', file=output)
    log.info(f'Generated code for {callback_count} callbacks.')


def main(argv):
    parser = argparse.ArgumentParser()
    parser.add_argument('-c', '--config')
    parser.add_argument('-o', '--output')
    parser.add_argument('-v', '--verbose', action='store_true')
    parser.add_argument('-e', '--exclude')
    parser.add_argument('-p', '--preinclude', default='')
    parser.add_argument('files', nargs='*')
    args = parser.parse_args(argv)
    logging.basicConfig(level=logging.DEBUG if args.verbose else logging.INFO)
    if args.config:
        process_config(args.config, exclude=args.exclude, preinclude=args.preinclude)
    elif args.files:
        cg = CallbackGenerator({}, [])
        res = cg.process_files(args.files).getvalue()
        print(res)


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
