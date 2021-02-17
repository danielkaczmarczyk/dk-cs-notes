"""
Given two strings, write a method to decide if one is a permutation of the other.
Page 90
"""

"""
if a string is a permutation of the other, it will have the same charcters in it
the first solution that comes to mind is to create sets from both strings and 
compare them

one easy win is to check the lenght of those two, if they are different, for sure
they will not be permutations
"""

def check_permutation(string_1, string_2):
    if len(string_1) != len(string_2):
        return False

    set_1 = set(string_1)
    set_2 = set(string_2)
    return set_1 == set_2

if __name__ == '__main__':
    import unittest

    class Test(unittest.TestCase):

        def test_1(self):
            input_1 = 'daniel'
            input_2 = 'dannyl'

            self.assertFalse(check_permutation(input_1, input_2))

        def test_2(self):
            input_1 = 'daniel'
            input_2 = 'leinad'

            self.assertTrue(check_permutation(input_1, input_2))

    unittest.main()
