import unittest
import gen_callbacks as gc


class TestTypedefRecognition(unittest.TestCase):
    def test_handle_1(self):
        code = 'typedef void *handle_h;'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), False)

    def test_handle_2(self):
        code = 'typedef void* handle_h;'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), False)

    def test_handle_3(self):
        code = 'typedef int handle_h;'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), False)

    def test_callback_1(self):
        code = 'typedef void (*done_cb)();'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), True)
        self.assertEqual(cr.is_struct_typedef(0), False)

    def test_callback_2(self):
        code = 'typedef void (*done_cb)(int a);'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), True)
        self.assertEqual(cr.is_struct_typedef(0), False)

    def test_callback_3(self):
        code = 'typedef void (*done_cb)(int a, void *user_data);'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), True)
        self.assertEqual(cr.is_struct_typedef(0), False)

    def test_callback_4(self):
        code = '''
                typedef void (*done_cb)(
                int a,
                void *user_data);
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        # We check at position 1 because the first token is \n.
        self.assertEqual(cr.is_callback_typedef(1), True)
        self.assertEqual(cr.is_struct_typedef(1), False)

    def test_struct_1(self):
        code = 'typedef struct { int x; } struct_s;'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_struct_2(self):
        code = 'typedef struct _tag1 { int x; } struct_s;'

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_struct_3(self):
        code = '''
            typedef struct {
                int x;
                int y;
                char *s;
            } struct_s;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_struct_4(self):
        code = '''
            typedef struct _tag1 {
                int x;
                int y;
                char *s;
            } struct_s;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_struct_5(self):
        code = '''
            typedef struct _tag1 {
                /**
                 * X
                 */
                int x;
                /**
                 * Y
                 */
                int y;
                /**
                 * S
                 */
                char *s;
                /**
                 * Substruct
                 */
                struct sub1 {
                    int a;
                    int b;
                };
            } struct_s;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_struct_6(self):
        code = '''
            typedef struct _tag1 {
                int x;      /**< X */
                int y;      /**< Y */
                char *s;    /**< S */
                struct sub1 {
                    int a;      /**< A */
                    int b;      /**< B */
                };          /**< Substruct */
            } struct_s;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_enum_1(self):
        code = '''
            typedef enum _tag1 {
                ENUM_VAL_1,
                ENUM_VAL_2,
                ENUM_VAL_3
            } enum_e;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_enum_2(self):
        code = '''
            typedef enum _tag1 {
                ENUM_VAL_1,     /**< Val 1 */
                ENUM_VAL_2,     /**< Val 2 */
                ENUM_VAL_3      /**< Val 3 */
            } enum_e;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_union_1(self):
        code = '''
            typedef union _tag1 {
                /**
                 * X
                 */
                int x;
                /**
                 * Y
                 */
                int y;
                /**
                 * S
                 */
                char *s;
                /**
                 * Substruct
                 */
                struct sub1 {
                    int a;
                    int b;
                };
            } struct_s;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)

    def test_union_2(self):
        code = '''
            typedef union _tag1 {
                int x;      /**< X */
                int y;      /**< Y */
                char *s;    /**< S */
                struct sub1 {
                    int a;      /**< A */
                    int b;      /**< B */
                };          /**< Substruct */
            } struct_s;'
        '''

        cr = gc.CodeReader()
        cr.string = code
        cr.tokenize()

        self.assertEqual(cr.is_callback_typedef(0), False)
        self.assertEqual(cr.is_struct_typedef(0), True)
