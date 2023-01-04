import unittest
import gen_callbacks as gc


class TestTokenize(unittest.TestCase):
    def token_word(self, word):
        cr = gc.CodeReader()
        t = gc.Token(cr.TOKEN_WORD)
        t.word = word
        return t

    def token_other(self, contents):
        cr = gc.CodeReader()
        t = gc.Token(cr.TOKEN_OTHER)
        t.contents = contents
        return t

    def test_empty_string(self):
        code = ''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [])

    def test_space(self):
        code = ' '

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [])

    def test_three_spaces(self):
        code = '   '

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [])

    def test_one_letter(self):
        code = 'a'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [self.token_word('a')])

    def test_one_word(self):
        code = 'abc'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [self.token_word('abc')])

    def test_two_words(self):
        code = 'abc def'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('abc'),
            self.token_word('def')
        ])

    def test_three_one_letter_words(self):
        code = 'a b c'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('a'),
            self.token_word('b'),
            self.token_word('c')
        ])

    def test_alphanums_1(self):
        code = 'a1 b2'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('a1'),
            self.token_word('b2')
        ])

    def test_alphanums_2(self):
        code = '1 2 3'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_other('1'),
            self.token_other('2'),
            self.token_other('3')
        ])

    # We're not testing string like '1abc', as they will not occur in the code
    # as keywords or identifiers. We assume that the code compiles (i.e. is correct).
    # They may appear as parts of strings or comments, but we're not interested in
    # parsing those perfectly.

    def test_other_chars_1(self):
        code = '+ - * /'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_other('+'),
            self.token_other('-'),
            gc.Token(cr.TOKEN_ASTERISK),
            self.token_other('/')
        ])

    def test_other_chars_2(self):
        code = '+a -b *c /d'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_other('+'),
            self.token_word('a'),
            self.token_other('-'),
            self.token_word('b'),
            gc.Token(cr.TOKEN_ASTERISK),
            self.token_word('c'),
            self.token_other('/'),
            self.token_word('d')
        ])

    def test_other_chars_3(self):
        code = '_a+_+_b_+'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('_a'),
            self.token_other('+'),
            self.token_word('_'),
            self.token_other('+'),
            self.token_word('_b_'),
            self.token_other('+')
        ])

    def test_comment_start(self):
        code = '/*'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [gc.Token(cr.TOKEN_COMMENT_START)])

    def test_comment_start_end(self):
        code = '/* */'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_COMMENT_START),
            gc.Token(cr.TOKEN_COMMENT_END)
        ])

    def test_comment_text(self):
        code = '/* aaa bbb */'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_COMMENT_START),
            self.token_word('aaa'),
            self.token_word('bbb'),
            gc.Token(cr.TOKEN_COMMENT_END)
        ])

    def test_comment_asterisks(self):
        code = '* /* * */ *'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_COMMENT_START),
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_COMMENT_END),
            gc.Token(cr.TOKEN_ASTERISK)
        ])

    def test_doxygen_comment_start(self):
        code = '/**'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [gc.Token(cr.TOKEN_DOXYGEN_CMNT_START)])

    def test_doxygen_comment_start_end(self):
        code = '/** */'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_DOXYGEN_CMNT_START),
            gc.Token(cr.TOKEN_COMMENT_END)
        ])

    def test_doxygen_comment_text(self):
        code = '/** aaa bbb */'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_DOXYGEN_CMNT_START),
            self.token_word('aaa'),
            self.token_word('bbb'),
            gc.Token(cr.TOKEN_COMMENT_END)
        ])

    def test_doxygen_comment_asterisks(self):
        code = '* /** * */ *'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_DOXYGEN_CMNT_START),
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_COMMENT_END),
            gc.Token(cr.TOKEN_ASTERISK)
        ])

    def test_typedef_handle(self):
        code = 'typedef void *handle_h;\n'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('typedef'),
            self.token_word('void'),
            gc.Token(cr.TOKEN_ASTERISK),
            self.token_word('handle_h'),
            gc.Token(cr.TOKEN_SEMICOLON),
            gc.Token(cr.TOKEN_NEWLINE)
        ])

    def test_typedef_callback_no_params(self):
        code = 'typedef void (*done_cb)();\n'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('typedef'),
            self.token_word('void'),
            gc.Token(cr.TOKEN_PAREN_LEFT),
            gc.Token(cr.TOKEN_ASTERISK),
            self.token_word('done_cb'),
            gc.Token(cr.TOKEN_PAREN_RIGHT),
            gc.Token(cr.TOKEN_PAREN_LEFT),
            gc.Token(cr.TOKEN_PAREN_RIGHT),
            gc.Token(cr.TOKEN_SEMICOLON),
            gc.Token(cr.TOKEN_NEWLINE)
        ])

    def test_typedef_callback_one_param(self):
        code = 'typedef void (*done_cb)(int id);\n'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('typedef'),
            self.token_word('void'),
            gc.Token(cr.TOKEN_PAREN_LEFT),
            gc.Token(cr.TOKEN_ASTERISK),
            self.token_word('done_cb'),
            gc.Token(cr.TOKEN_PAREN_RIGHT),
            gc.Token(cr.TOKEN_PAREN_LEFT),
            self.token_word('int'),
            self.token_word('id'),
            gc.Token(cr.TOKEN_PAREN_RIGHT),
            gc.Token(cr.TOKEN_SEMICOLON),
            gc.Token(cr.TOKEN_NEWLINE)
        ])

    def test_typedef_callback_two_params(self):
        code = 'typedef void (*done_cb)(int id, void *user_data);\n'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            self.token_word('typedef'),
            self.token_word('void'),
            gc.Token(cr.TOKEN_PAREN_LEFT),
            gc.Token(cr.TOKEN_ASTERISK),
            self.token_word('done_cb'),
            gc.Token(cr.TOKEN_PAREN_RIGHT),
            gc.Token(cr.TOKEN_PAREN_LEFT),
            self.token_word('int'),
            self.token_word('id'),
            gc.Token(cr.TOKEN_COMMA),
            self.token_word('void'),
            gc.Token(cr.TOKEN_ASTERISK),
            self.token_word('user_data'),
            gc.Token(cr.TOKEN_PAREN_RIGHT),
            gc.Token(cr.TOKEN_SEMICOLON),
            gc.Token(cr.TOKEN_NEWLINE)
        ])

    def test_doxygen_comment_brief(self):
        code = '''/**
            * @brief Gets ID.
            */'''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_DOXYGEN_CMNT_START),
            gc.Token(cr.TOKEN_NEWLINE),
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_AT),
            self.token_word('brief'),
            self.token_word('Gets'),
            self.token_word('ID'),
            gc.Token(cr.TOKEN_PERIOD),
            gc.Token(cr.TOKEN_NEWLINE),
            gc.Token(cr.TOKEN_COMMENT_END)
        ])

    def test_doxygen_comment_many_tags(self):
        code = '''/**
            * @brief
            * @param[in]
            * @param[out]
            * @see
            */'''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.tokens, [
            gc.Token(cr.TOKEN_DOXYGEN_CMNT_START),
            gc.Token(cr.TOKEN_NEWLINE),
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_AT),
            self.token_word('brief'),
            gc.Token(cr.TOKEN_NEWLINE),
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_AT),
            self.token_word('param'),
            gc.Token(cr.TOKEN_BRACKET_LEFT),
            self.token_word('in'),
            gc.Token(cr.TOKEN_BRACKET_RIGHT),
            gc.Token(cr.TOKEN_NEWLINE),
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_AT),
            self.token_word('param'),
            gc.Token(cr.TOKEN_BRACKET_LEFT),
            self.token_word('out'),
            gc.Token(cr.TOKEN_BRACKET_RIGHT),
            gc.Token(cr.TOKEN_NEWLINE),
            gc.Token(cr.TOKEN_ASTERISK),
            gc.Token(cr.TOKEN_AT),
            self.token_word('see'),
            gc.Token(cr.TOKEN_NEWLINE),
            gc.Token(cr.TOKEN_COMMENT_END)
        ])
