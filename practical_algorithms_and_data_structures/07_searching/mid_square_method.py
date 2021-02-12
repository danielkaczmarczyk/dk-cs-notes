"""
    Mid square folding method for constructing hash functions.
"""
def fold(number, table_size):
    pass

if __name__ == '__main__':
    import unittest

    class TestFold(unittest.TestCase):

        def test_fold(self):
            number = 4365554601
            table_size = 11
            result = fold(number, table_size)
            expected = 1
            message = f"folding {number} did not give {expected}, got {result} instead"

            self.assertEqual(result, expected, message)

    unittest.main()
