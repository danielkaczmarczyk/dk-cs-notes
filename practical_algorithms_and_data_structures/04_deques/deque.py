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
        pass

    def is_empty(self):
        pass

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

        def test_remove(self):
            deque = Deque()
            deque.add_rear('a')
            deque.add_rear('b')

            result = deque.remove_front()

            self.assertEqual(result, 'b')
            self.assertEqual(deque.size(), 1)

    unittest.main()



