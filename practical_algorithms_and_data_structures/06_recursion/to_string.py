NUMS = '0123456789ABCDEF'

def to_string(n, base):
    if n < base:
        return NUMS[n]
    result, remainder = divmod(n, base)
    return to_string(result, base) + NUMS[remainder]



if __name__ == '__main__':
    import unittest

    class TestToString(unittest.TestCase):

        def test_233_10(self):
            result = to_string(233, 10)
            self.assertEqual(result, '233')

        def test_233_2(self):
            result = to_string(233, 2)
            self.assertEqual(result, '11101001')

        def test_1453_16(self):
            result = to_string(1453, 16)
            self.assertEqual(result, '5AD')

    unittest.main()
