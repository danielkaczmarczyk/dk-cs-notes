"""
Cracking the Coding Interview, question 1.4, Page 91

a string is a palindrome if every letter (or every but one) appears in the
string twice. 

hints: 106 121 134 136
"""

from collections import Counter

def palindrome_permutation(string):
    """
    Checks if string can be permutated into a palindrome
    Returns a boolean
    """
    c = Counter(string.lower())
    del c[' ']
    counts = list(c.values())
    result = [x for x in counts if x is not 2]
    if len(result) > 1:
        return False
    else:
        if result[0] != 1:
            return False
    return True


if __name__ == '__main__':
    import unittest

    class Test(unittest.TestCase):

        def test(self):
            input_ = "Tact Coa"
            self.assertTrue(palindrome_permutation(input_))

    unittest.main()
