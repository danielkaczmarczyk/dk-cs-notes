class Queue():
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        return self.items.pop()

    def is_empty(self):
        if len(self.items) == 0:
            return True
        return False

    def size(self):
        return len(self.items)

if __name__ == '__main__':
    import unittest

    class QueueTests(unittest.TestCase):

        def test_enqueue(self):
            q = Queue()
            q.enqueue('a')

            self.assertEqual(q.items, ['a'])
            self.assertEqual(q.size(), 1)

        def test_dequeue(self):
            q = Queue()
            q.enqueue('a')
            result = q.dequeue()

            self.assertEqual(result, 'a')
            self.assertEqual(q.size(), 0)

    unittest.main()
