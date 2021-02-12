"""
    Mid square folding method for constructing hash functions.
    Just for fun only, does not cover many edge cases.
"""
def mid_square_fold(number, table_size):
    squared = number ** 2
    string = str(squared)
    # big assumption, won't be true for most integers
    middle_two = int(string[1:3])
    print(f"{middle_two=}")
    return middle_two % table_size

if __name__ == '__main__':
    import unittest

    class TestFold(unittest.TestCase):

        def test_fold(self):
            table_size = 11
            test_cases = [
                            (44, 5),
                            (54, 3),
                            (26, 7),
                            (93, 9),
                            (17, 6),
                            (77, 4),
                            (31, 6)
                         ]

            for case in test_cases:
                self.assertEqual(mid_square_fold(case[0], table_size), case[1])

    unittest.main()
