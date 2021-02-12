"""
    Folding method for constructing hash functions.
"""
def fold(number):
    # make it a string 
    number = str(number)

    index = 0 
    step = 2

    while index < len(number):
        print(number[index])
        index += step

if __name__ == '__main__':
    import unittest

    class TestFold(unittest.TestCase):

        def test_fold_1(self):
            number = 4365554601
            result = fold(number)
            expected = 10
            message = f"folding {number} did not give {expected}, got {result} instead"

            self.assertEqual(result, expected, message)

    unittest.main()
