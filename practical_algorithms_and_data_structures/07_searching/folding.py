"""
    Folding method for constructing hash functions.
"""
def fold(number, table_size):
    # make it a string 
    number = str(number)
    container = []

    index = 0 
    step = 2

    while index < len(number):
        print(number[index])
        container.append(int(number[index] + number[index + 1]))
        index += step

    return sum(container) % table_size

if __name__ == '__main__':
    import unittest

    class TestFold(unittest.TestCase):

        def test_fold_1(self):
            number = 4365554601
            table_size = 11
            result = fold(number, table_size)
            expected = 1
            message = f"folding {number} did not give {expected}, got {result} instead"

            self.assertEqual(result, expected, message)

    unittest.main()
