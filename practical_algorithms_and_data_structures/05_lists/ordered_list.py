from unordered_list import Node, UnorderedList


class OrderedList(UnorderedList):

    def print(self):

        current = self.head

        while current is not None:
            print(current.value)
            current = current.next

    def search(self):
        pass

    def add(self, item):
        node = Node(item)
        if self.head is None:
            self.head = node
        else:
            previous = None
            current = self.head

            # case where the value is the smallest in the list.
            if current.value > node.value:
                node.next = self.head
                self.head = node
                return

            # while we're not at the end and the values are still rising
            while current is not None and current.value < node.value:
                previous, current = current, current.next

            # how do we handle bigger/smaller? in that case it only works if
            # the node we're inserting is smaller than the last node.
            node.next = current

            # ensure that we're not at the beginning
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
            pass

        def test_add(self):
            ol = self.list_setup()

            self.assertEqual(ol.size(), 7)
            ol.search()


    unittest.main()

