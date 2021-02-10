class Node():
    def __init__(self, value):
        self.value = value
        self.next = None


class UnorderedList():
    def __init__(self):
        self.head = None

    def add(self, item):
        node = Node(item)
        node.next = self.head
        self.head = node

    def remove(self, item):
        pass

    def search(self, item):
        node = self.head

        while node is not None:
            if node.value == item:
                return True
            node = node.next

        return False

    def is_empty(self):
        return self.head is None

    def size(self):
        count = 0
        node = self.head
        
        while node is not None:
            count += 1
            node = node.next

        return count


    def append(self, item):
        pass

    def index(self, item):
        pass

    def insert(self, pos, item):
        pass

    def pop(self):
        pass

    def pop(self, pos):
        pass

if __name__ == "__main__":
    import unittest

    class UnorderedListTest(unittest.TestCase):

        def test_is_empty(self):
            ul = UnorderedList()
            self.assertTrue(ul.is_empty(), "Empty list does not show up as empty")

        def test_add(self):
            ul = UnorderedList()

            ul.add(31)
            self.assertEqual(ul.head.value, 31)

            ul.add(77)
            self.assertEqual(ul.head.value, 77)

            ul.add(17)
            self.assertEqual(ul.head.value, 17)

            ul.add(93)
            self.assertEqual(ul.head.value, 93)

            ul.add(26)
            self.assertEqual(ul.head.value, 26)

            ul.add(54)
            self.assertEqual(ul.head.value, 54)

            self.assertEqual(ul.size(), 6)

        def test_size(self):
            ul = UnorderedList()

            self.assertEqual(ul.size(), 0)

            ul.add(1)
            ul.add(2)
            ul.add(3)

            self.assertEqual(ul.size(), 3)

        def test_search(self):
            ul = UnorderedList()

            ul.add(1)
            ul.add(2)
            ul.add(3)

            result = ul.search(2)
            self.assertTrue(result)

            result = ul.search(150)
            self.assertFalse(result)



    unittest.main()

