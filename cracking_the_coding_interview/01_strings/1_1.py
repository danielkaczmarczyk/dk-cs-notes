"""
Question from page 90.
"""

def is_unique(string):
    """
    Check whether <string> has got all unique characters and return a boolean
    """
    letters = []
    for letter in string:
        if letter in letters:
            return False
        else:
            letters.append(letter)
    return True


if __name__ == '__main__':
    import unittest

    class Test(unittest.TestCase):

        def test(self):
            string = 'daniel'
            exp = True
            result = is_unique(string)

            self.assertEqual(exp, result)

    unittest.main()
