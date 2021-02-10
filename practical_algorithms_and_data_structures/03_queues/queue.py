class Queue():
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        pass

    def is_empty(self):
        pass

    def size(self):
        pass

if __name__ == '__main__':
    import unittest

    class QueueTests(unittest.TestCase):

        def test_enqueue(self):
            q = Queue()
            q.enqueue('a')

            self.assertEqual(q.items, ['a'])

    unittest.main()
