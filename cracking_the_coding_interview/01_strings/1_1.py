"""
Question from page 90.
"""

def is_unique(string):
    """
    Check whether <string> has got all unique characters and return a boolean.
    Assumes the string is encoded as an ASCII extended string.
    """

    # assuming it is an ASCII string, for extended ASCII there can not be more
    # than 256 unique characters in that string
    if len(string) > 256:
        return False

    # using an array for the lookups - possible increase in speed can be
    # achieved if we use a dictionary, depending on how the 
    # _in_ operator performs
    letters = []

    # arguably, the time complexity is not O(n), but O(1) cause we are
    # not going to be itearting over a string longer than 256 chars
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
