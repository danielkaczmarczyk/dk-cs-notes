class Deque():
    def __init__(self):
        self.items = []

    def add_front(self, item):
        self.items.append(item)

    def add_read(self, item):
        pass

    def remove_front(self):
        pass

    def remove_rear(self):
        pass

    def is_empty(self):
        pass

    def size(self):
        pass


if __name__ == '__main__':
    import unittest

    class Test(unittest.TestCase):

        def test_add_front(self):
            deque = Deque()
            deque.add_front('a')

            self.assertEqual(deque.items, ['a'])

    unittest.main()



