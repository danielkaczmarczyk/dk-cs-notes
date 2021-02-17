"""
Cracking the Coding Interview, question 1.3, Page 90
hints 53 and 118
"""

def urlify(string):
    result = ""
    for char in string:
        if char.isspace():
            result += "%20"
        else:
            result += char
    return result


if __name__ == "__main__":
    import unittest

    class Test(unittest.TestCase):

        def test(self):
            input_ = "Mr John Smith"
            output = "Mr%20John%20Smith"

            self.assertEqual(urlify(input_), output)
            pass

    unittest.main()

