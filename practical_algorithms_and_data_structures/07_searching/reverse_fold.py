"""
    Mid square folding method for constructing hash functions.
"""
def reverse_fold(number, table_size):
    # make it a string 
    number = str(number)
    container = []

    index = 0 
    step = 2
    odd = True

    while index < len(number):
        # reverse every other item
        if odd:
            container.append(int(number[index] + number[index + 1]))
            odd = False
        else:
            container.append(int(number[index + 1] + number[index]))
            odd = True

        index += step

    print(container)
    return sum(container) % table_size

if __name__ == '__main__':
    import unittest

    class TestFold(unittest.TestCase):

        def test_fold(self):
            number = 4365554601
            table_size = 11
            result = reverse_fold(number, table_size)
            expected = 10
            message = f"folding {number} did not give {expected}, got {result} instead"

            self.assertEqual(result, expected, message)

    unittest.main()
