import unittest
import gen_callbacks as gc


class TestCallbacksData(unittest.TestCase):
  def test_empty_string(self):
    callbacks = gc.CodeReader.read_callbacks_from_string(
        'typedef void (*cb)(int a, const char* b, some_h c, some_e d);')
    cb = callbacks[0]
    api = gc.CallbackDataCollector()
    print(cb)
    api.rewrite_types(cb)
    print(cb)
