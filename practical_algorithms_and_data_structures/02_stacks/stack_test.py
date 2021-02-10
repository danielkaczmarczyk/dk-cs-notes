import unittest
from stack import Stack

class TestStack(unittest.TestCase):

    def setup_stack(self):
        stack = Stack()
        for item in ['a', 'b', 'c']:
            stack.push(item)
        return stack

    def test_init(self):
        stack = Stack()

        self.assertEqual(stack.count, 0)
        self.assertEqual(stack.items, [])

if __name__ == '__main__':
    unittest.main()
