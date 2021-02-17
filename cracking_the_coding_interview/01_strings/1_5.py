"""
Cracking the Coding Interview, question 1.5, Page 91

there are three types of edits that can be performed on a string:
insert, remove, or replace a character

the function should check if those strings are one edit away

hints 23 97 130
"""
def one_away(string_1, string_2):
    # removing / inserting case
    # if the length difference is greater than 1
    # that means they're not one away
    if abs(len(string_1) - len(string_2)) > 1:
        return False
    
    pass


if __name__ == '__main__':
    import unittest

    class Test(unittest.TestCase):

        def test_1(self):
            string_1 = 'pale'
            string_2 = 'ple'

            self.assertTrue(one_away(string_1, string_2))

        def test_2(self):
            string_1 = 'pale'
            string_2 = 'bake'

            self.assertFalse(one_away(string_1, string_2))

        def test_3(self):
            string_1 = 'pale'
            string_2 = 'bakery'

            self.assertFalse(one_away(string_1, string_2))


    unittest.main()
