def right_rotate(a_list, n):
    result = [None for x in a_list]

    for index in range(n - 1):
        print(f"{index=} {a_list[index]=}")
        location = index + n
        result[location] = a_list[index]

    for index in range(n - 1, len(a_list)):
        print(f"{index=} {a_list[index]=}")
        location = index - (n - 1)
        result[location] = a_list[index]

    return result


if __name__ == '__main__':
    import unittest

    class RotateTest(unittest.TestCase):

        def test_1(self):
            arr = [1, 2, 3, 4, 5]
            n = 1
            expected = [5, 1, 2, 3, 4]
            result = right_rotate(arr, n)
            self.assertEqual(expected, result)

        def test_3(self):
            arr = [300, -1, 3, 0]
            n = 1
            expected = [0, 300, -1, 3]
            result = right_rotate(arr, n)
            self.assertEqual(expected, result)

        def test_1(self):
            arr = [0, 0, 0, 2]
            n = 1
            expected = [2, 0, 0, 0]
            result = right_rotate(arr, n)
            self.assertEqual(expected, result)

        def test_1(self):
            arr = ['13', 'a', 'Python']
            n = 1
            expected = ['Python', '13', 'a']
            result = right_rotate(arr, n)
            self.assertEqual(expected, result)

        def test_1(self):
            arr = [10, 20, 30, 40, 50]
            n = 3
            expected = [30, 40, 50, 10, 20]
            result = right_rotate(arr, n)
            self.assertEqual(expected, result)

    unittest.main()

