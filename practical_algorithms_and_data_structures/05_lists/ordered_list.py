from unordered_list import Node, UnorderedList


class OrderedList(UnorderedList):

    def print(self):

        current = self.head

        while current is not None:
            print(current.value)
            current = current.next

    def search(self, item):
        current = self.head

        while current is not None:
            if current.value > item:
                return False
            if current.value == item:
                return True
            current = current.next

        return False

    def add(self, item):
        node = Node(item)
        if self.head is None:
            self.head = node
        else:
            previous = None
            current = self.head

            if current.value > node.value:
                node.next = self.head
                self.head = node
                return

            while current is not None and current.value < node.value:
                previous, current = current, current.next

            node.next = current

            if previous is not None:
                previous.next = node


if __name__ == '__main__':
    import unittest

    
    class OrderedListTests(unittest.TestCase):

        def list_setup(self):
            ol = OrderedList()
            for n in [26, 31, 17, 54, 93, 77, 101]:
                ol.add(n)
            return ol

        def test_search(self):
            ol = self.list_setup()

            result = ol.search(17)
            self.assertTrue(result)

            result = ol.search(77)
            self.assertTrue(result)

            result = ol.search(101)
            self.assertTrue(result)

            result = ol.search(69)
            self.assertFalse(result)

        def test_add(self):
            ol = self.list_setup()

            self.assertEqual(ol.size(), 7)


    unittest.main()

