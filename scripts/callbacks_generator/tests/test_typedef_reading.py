# Copyright 2023 Samsung Electronics Co., Ltd. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import unittest
import gen_callbacks as gc


class TestHandlefReading(unittest.TestCase):
  def test_handle_1(self):
    code = 'typedef void *handle_h;'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {'handle_h': 'void *'})

  def test_handle_2(self):
    code = 'typedef void* handle_h;'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {'handle_h': 'void *'})

  def test_handle_3(self):
    code = 'typedef int handle_h;'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {'handle_h': 'int'})

  def test_handle_4(self):
    code = '''
typedef void *handle_1_h;
typedef void* handle_2_h;
typedef void * handle_3_h;
typedef int handle_4_h;
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {
        'handle_1_h': 'void *',
        'handle_2_h': 'void *',
        'handle_3_h': 'void *',
        'handle_4_h': 'int'
    })

  def test_handle_5(self):
    code = '''
/**
 * @brief Handle 1.
 * @since_tizen 6.5
 */
typedef void *handle_1_h;

/**
 * @brief Handle 2.
 * @since_tizen 6.5
 */
typedef void* handle_2_h;

/**
 * @brief Handle 3.
 * @since_tizen 6.5
 */
typedef void * handle_3_h;

/**
 * @brief Handle 4.
 * @since_tizen 6.5
 */
typedef int handle_4_h;
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {
        'handle_1_h': 'void *',
        'handle_2_h': 'void *',
        'handle_3_h': 'void *',
        'handle_4_h': 'int'
    })

  # typedefs in comments should be ignored.
  def test_handle_in_comment_1(self):
    code = '/* typedef void *handle_h; */'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {})

  def test_handle_in_comment_2(self):
    code = '/** typedef void *handle_h; */'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {})

  def test_handle_in_comment_3(self):
    code = '''
/*
 * typedef void *handle_h;
 */
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {})

  def test_handle_in_comment_4(self):
    code = '''
/**
 * typedef void *handle_h;
 */
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {})

  # Handle typedef in line comment without newline at the end.
  def test_handle_in_line_comment_1(self):
    code = '// typedef void *handle_h;'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {})

  # Handle typedef in line comment with newline at the end.
  def test_handle_in_line_comment_2(self):
    code = '''
//
// typedef void *handle_h;
//
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.handles, {})


class TestCallbackReading(unittest.TestCase):
  def test_void_cb_no_params(self):
    code = 'typedef void (*scan_completed_cb)();'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = []

    self.assertEqual(cr.callbacks, [cb])

  def test_int_cb_no_params(self):
    code = 'typedef int (*scan_completed_cb)();'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'int'
    cb.name = 'scan_completed_cb'
    cb.params = []

    self.assertEqual(cr.callbacks, [cb])

  def test_cb_one_param(self):
    code = 'typedef void (*scan_completed_cb)(int result);'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = [gc.ParamInfo('int', 'result')]

    self.assertEqual(cr.callbacks, [cb])

  def test_cb_two_params(self):
    code = 'typedef void (*scan_completed_cb)(int result, void *user_data);'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('void *', 'user_data'),
    ]

    self.assertEqual(cr.callbacks, [cb])

  def test_cb_three_params(self):
    code = 'typedef void (*scan_completed_cb)(int result, char **name, void *user_data);'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('char **', 'name'),
        gc.ParamInfo('void *', 'user_data'),
    ]

    self.assertEqual(cr.callbacks, [cb])

  def test_cb_multi_line_1(self):
    code = '''
typedef void (*scan_completed_cb)(
    int result,
    char **name,
    void *user_data);
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('char **', 'name'),
        gc.ParamInfo('void *', 'user_data'),
    ]

    self.assertEqual(cr.callbacks, [cb])

  def test_cb_multi_line_2(self):
    code = '''
typedef
void
(
*
scan_completed_cb
)
(
int
result
,
char
*
*
name
,
void
*
user_data
)
;
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('char **', 'name'),
        gc.ParamInfo('void *', 'user_data'),
    ]

    self.assertEqual(cr.callbacks, [cb])

  def test_three_callbacks(self):
    code = '''
/**
 * @brief Called when ...
 * @details ...
 * @param[out] result ...
 * @param[out] name ...
 * @param[out] user_data ...
 */
typedef void (*scan_completed_cb)(int result, char **name, void *user_data);

/**
 * @brief Called when ...
 * @details ...
 * @param[out] user_data ...
 */
typedef int (*completed_cb)(void *user_data);

/**
 * @brief Called when ...
 * @details ...
 */
typedef void (*done_cb)();
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb1 = gc.CallbackInfo()
    cb1.ret_type = 'void'
    cb1.name = 'scan_completed_cb'
    cb1.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('char **', 'name'),
        gc.ParamInfo('void *', 'user_data'),
    ]

    cb2 = gc.CallbackInfo()
    cb2.ret_type = 'int'
    cb2.name = 'completed_cb'
    cb2.params = [
        gc.ParamInfo('void *', 'user_data'),
    ]

    cb3 = gc.CallbackInfo()
    cb3.ret_type = 'void'
    cb3.name = 'done_cb'
    cb3.params = []

    self.assertEqual(cr.callbacks, [cb1, cb2, cb3])

  # typedefs in comments should be ignored.
  def test_cb_in_comments_1(self):
    code = '/* typedef void (*scan_completed_cb)(int result, void *user_data); */'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.callbacks, [])

  def test_cb_in_comments_2(self):
    code = '''
/*
 * typedef void (*scan_completed_cb)(int result, void *user_data);
 */
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.callbacks, [])

  def test_cb_in_comments_3(self):
    code = '/** typedef void (*scan_completed_cb)(int result, void *user_data); */'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.callbacks, [])

  def test_cb_in_comments_4(self):
    code = '''
/**
 * typedef void (*scan_completed_cb)(int result, void *user_data);
 */
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.callbacks, [])

  # Callback typedef in line comment without newline at the end.
  def test_cb_in_line_comments_1(self):
    code = '// typedef void (*scan_completed_cb)(int result, void *user_data);'

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.callbacks, [])

  # Callback typedef in line comment with newline at the end.
  def test_cb_in_line_comments_2(self):
    code = '''
//
// typedef void (*scan_completed_cb)(int result, void *user_data);
//
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    self.assertEqual(cr.callbacks, [])

  def test_cb_with_example_1(self):
    # In the example code another function pointer type is defined,
    # It should not be considered as an actual typedef.
    # Only the typedef should be recognized.
    code = '''
/**
 * @brief Called when ...
 * @details ...
 * @code Example:
 * ...
 * typedef void (*some_other_cb)(int result, void *user_data);
 * ...
 * @endcode
 */
typedef void (*scan_completed_cb)(int result, void *user_data);
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('void *', 'user_data')
    ]

    self.assertEqual(cr.callbacks, [cb])

  def test_cb_with_example_2(self):
    # As above, with multiple typedefs.
    code = '''
//
// typedef void (*some_other_cb)(int result, void *user_data);
//
/**
 * @brief Called when ...
 * @details ...
 * @code Example:
 * // ...
 * // typedef void (*some_other_cb)(int result, void *user_data);
 * // ...
 * ...
 * typedef void (*some_other_cb)(int result, void *user_data);
 * ...
 * @endcode
 */
typedef void (*scan_completed_cb)(int result, void *user_data);
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb = gc.CallbackInfo()
    cb.ret_type = 'void'
    cb.name = 'scan_completed_cb'
    cb.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('void *', 'user_data')
    ]

    self.assertEqual(cr.callbacks, [cb])


class TestMultipleApiElements(unittest.TestCase):
  def test_handles_and_callbacks(self):
    code = '''
/**
 * @brief Data handle
 * @since_tizen 6.5
 */
typedef void *data_h;

/**
 * @brief Service handle
 * @since_tizen 6.5
 */
typedef int service_h;

/**
 * @brief Called when ...
 * @details ...
 * @param[out] result ...
 * @param[out] name ...
 * @param[out] user_data ...
 */
typedef void (*scan_completed_cb)(int result, char **name, void *user_data);

/**
 * @brief Called when ...
 * @details ...
 * @param[out] user_data ...
 */
typedef int (*completed_cb)(void *user_data);
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb1 = gc.CallbackInfo()
    cb1.ret_type = 'void'
    cb1.name = 'scan_completed_cb'
    cb1.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('char **', 'name'),
        gc.ParamInfo('void *', 'user_data')
    ]

    cb2 = gc.CallbackInfo()
    cb2.ret_type = 'int'
    cb2.name = 'completed_cb'
    cb2.params = [
        gc.ParamInfo('void *', 'user_data'),
    ]

    self.assertEqual(cr.callbacks, [cb1, cb2])
    self.assertEqual(cr.handles, {
        'data_h': 'void *',
        'service_h': 'int'
    })

  def test_handles_callbacks_funcs(self):
    code = '''
/*
 * License
 */

/**
 * @brief Data handle
 * @since_tizen 6.5
 */
typedef void *data_h;

/**
 * @brief Service handle
 * @since_tizen 6.5
 */
typedef int service_h;

/**
 * @brief Starts scanning.
 * @since_tizen 6.5
 * @param[in] service ...
 * @param[in] filter ...
 * @returns ...
 * @retval ...
 * @retval ...
 */
int start_scan(service_h service, filter_h filter);

/**
 * @brief Called when ...
 * @details ...
 * @param[out] result ...
 * @param[out] name ...
 * @param[out] user_data ...
 */
typedef void (*scan_completed_cb)(int result, char **name, void *user_data);

/**
 * @brief Starts the service.
 * @since_tizen 6.5
 * @param[in] service ...
 * @returns ...
 * @retval ...
 * @retval ...
 */
int service_start(service_h service);

/**
 * @brief Called when ...
 * @details ...
 * @param[out] user_data ...
 */
typedef int (*completed_cb)(void *user_data);
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb1 = gc.CallbackInfo()
    cb1.ret_type = 'void'
    cb1.name = 'scan_completed_cb'
    cb1.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('char **', 'name'),
        gc.ParamInfo('void *', 'user_data')
    ]

    cb2 = gc.CallbackInfo()
    cb2.ret_type = 'int'
    cb2.name = 'completed_cb'
    cb2.params = [
        gc.ParamInfo('void *', 'user_data'),
    ]

    self.assertEqual(cr.callbacks, [cb1, cb2])
    self.assertEqual(cr.handles, {
        'data_h': 'void *',
        'service_h': 'int'
    })

  def test_handle_cbs_struct_enum(self):
    code = '''
/*
 * License
 */

/**
 * @brief Service handle
 * @since_tizen 6.5
 */
typedef int service_h;

/**
 * @brief Data struct
 * @since_tizen 6.5
 */
typedef struct {
    /**
     * Id
     */
    int id;

    /**
     * Name
     */
    char *name;
} data_s;

/**
 * @brief Starts scanning.
 * @since_tizen 6.5
 * @param[in] service ...
 * @param[in] filter ...
 * @returns ...
 * @retval ...
 * @retval ...
 */
int start_scan(service_h service, filter_h filter);

/**
 * @brief Called when ...
 * @details ...
 * @param[out] result ...
 * @param[out] name ...
 * @param[out] user_data ...
 */
typedef void (*scan_completed_cb)(int result, char **name, void *user_data);

/**
 * @brief State enum
 * @since_tizen 6.5
 */
typedef enum {
    STATE_ACTIVE = 0,   /**< Active */
    STATE_INACTIVE = 1  /**< Inactive */
} state_e;

/**
 * @brief Starts the service.
 * @since_tizen 6.5
 * @param[in] service ...
 * @returns ...
 * @retval ...
 * @retval ...
 */
int service_start(service_h service);

/**
 * @brief Called when ...
 * @details ...
 * @param[out] user_data ...
 */
typedef int (*completed_cb)(void *user_data);
'''

    cr = gc.CodeReader()
    cr.string = code
    cr.tokenize()
    cr.find_typedefs()

    cb1 = gc.CallbackInfo()
    cb1.ret_type = 'void'
    cb1.name = 'scan_completed_cb'
    cb1.params = [
        gc.ParamInfo('int', 'result'),
        gc.ParamInfo('char **', 'name'),
        gc.ParamInfo('void *', 'user_data')
    ]

    cb2 = gc.CallbackInfo()
    cb2.ret_type = 'int'
    cb2.name = 'completed_cb'
    cb2.params = [
        gc.ParamInfo('void *', 'user_data')
    ]

    self.assertEqual(cr.callbacks, [cb1, cb2])
    self.assertEqual(cr.handles, {
        'service_h': 'int'
    })
