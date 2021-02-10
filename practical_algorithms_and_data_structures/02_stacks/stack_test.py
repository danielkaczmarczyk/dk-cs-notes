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

    def test_is_empty(self):
        stack = self.setup_stack()
        while not stack.is_empty():
            stack.pop()
        
        self.assertEqual(stack.count, 0)
        self.assertEqual(stack.items, [])

    def test_push(self):
        stack = Stack()
        stack.push('a')
        
        self.assertEqual(stack.count, 1)
        self.assertEqual(stack.items, ['a'])

        stack.push('b')
        stack.push('c')
        
        self.assertEqual(stack.count, 3)
        self.assertEqual(stack.items, ['a', 'b', 'c'])

    def test_pop(self):
        stack = self.setup_stack()

        self.assertEqual(stack.count, 3)
        
        popped = stack.pop()
        
        self.assertEqual(stack.count, 2)
        self.assertEqual(popped, 'c')

    def test_peek(self):

        stack = self.setup_stack()
        peeked = stack.peek()

        self.assertEqual(peeked, 'c')
        self.assertEqual(stack.count, 3)

    def test_size(self):

        stack = self.setup_stack()
        self.assertEqual(stack.count, 3)


if __name__ == '__main__':
    unittest.main()
