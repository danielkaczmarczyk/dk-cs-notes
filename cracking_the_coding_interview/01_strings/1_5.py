"""
Cracking the Coding Interview, question 1.5, Page 91

there are three types of edits that can be performed on a string:
insert, remove, or replace a character

hints 23 97 130
"""
def one_away(string_1, string_2):
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

    unittest.main()
