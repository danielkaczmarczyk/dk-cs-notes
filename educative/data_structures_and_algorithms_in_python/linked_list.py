from node import Node

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        node = Node(data)

        if self.head is None:
            self.head = node
            return

        current_node = self.head
        while current_node.next is not None:
            current_node = current_node.next

        current_node.next = node

    def __len__(self):
        length = 0

        current_node = self.head
        while current_node is not None:
            length += 1
            current_node = current_node.next

        return length

    def __str__(self):
        result = ''

        node = self.head
        while node.next:
            result += f"{node.data} -> "
            node = node.next

        result += f"{node.data}"

        return result

    def prepend(self, data):
        node = Node(data)
        if not self.head:
            self.append(node)

        node.next = self.head
        self.head = node


if __name__ == '__main__':
    import unittest

    class TestLinkedList(unittest.TestCase):

        def test_append(self):
            ll = LinkedList()
            ll.append("A")
            self.assertEqual(ll.head.data, "A")

            ll.append("B")

        def test__len__(self):
            ll = LinkedList()
            self.assertEqual(len(ll), 0)

            for letter in ["A", "B", "C"]:
                ll.append(letter)

            self.assertEqual(len(ll), 3)

        def test__str__(self):
            ll = LinkedList()
            for letter in ["A", "B", "C"]:
                ll.append(letter)

            self.assertEqual(str(ll), "A -> B -> C")

        def test_prepend(self):
            ll = LinkedList()
            for letter in ["A", "B", "C"]:
                ll.append(letter)

            ll.prepend("Z")
            self.assertEqual(ll.head.data, "Z")
            self.assertEqual(str(ll), "Z -> A -> B -> C")
            self.assertEqual(len(ll), 4)


    unittest.main()


