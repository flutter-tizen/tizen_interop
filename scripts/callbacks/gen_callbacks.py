#!/usr/bin/env python3

import sys


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
        self.params = []

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


def main(argv):
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
