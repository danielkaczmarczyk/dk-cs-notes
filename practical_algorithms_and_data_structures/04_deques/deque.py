class Deque():
    def __init__(self):
        self.items = []

    def add_front(self, item):
        self.items.append(item)

    def add_rear(self, item):
        self.items.insert(0, item)

    def remove_front(self):
        return self.items.pop(0)

    def remove_rear(self):
        return self.items.pop()

    def is_empty(self):
        if self.size() == 0:
            return True
        return False

    def size(self):
        return len(self.items)


if __name__ == '__main__':
    import unittest

    class Test(unittest.TestCase):

        def test_add_front(self):
            deque = Deque()
            deque.add_front('a')

            self.assertEqual(deque.items, ['a'])
            self.assertEqual(deque.size(), 1)

        def test_add_rear(self):
            deque = Deque()
            deque.add_rear('a')
            deque.add_rear('b')

            self.assertEqual(deque.items, ['b', 'a'])
            self.assertEqual(deque.size(), 2)

        def test_remove_front(self):
            deque = Deque()
            deque.add_rear('a')
            deque.add_rear('b')

            result = deque.remove_front()

            self.assertEqual(result, 'b')
            self.assertEqual(deque.size(), 1)

        def test_remove_rear(self):
            deque = Deque()
            deque.add_front('a')
            deque.add_front('b')
            deque.add_front('c')

            result = deque.remove_rear()
            self.assertEqual(result, 'c')

            result = deque.remove_rear()
            self.assertEqual(result, 'b')

        def test_is_empty(self):
            deque = Deque()
            deque.add_front('a')
            deque.add_front('b')
            deque.add_front('c')

            self.assertFalse(deque.is_empty())

            deque.remove_rear()
            deque.remove_rear()
            deque.remove_rear()

            self.assertTrue(deque.is_empty())

    unittest.main()



