import unittest
from doubly_linked_list import DoublyLinkedList, ListNode

class TestList(unittest.TestCase):

    def test_init(self):
        dllist = DoublyLinkedList()
        self.assertIsInstance(dllist, DoublyLinkedList)
        self.assertIsNone(dllist.first)
        self.assertIsNone(dllist.last)
        self.assertEqual(dllist.count, 0)

    def test_push(self):
        dllist = DoublyLinkedList()

        dllist.push('a')
        self.assertIsNotNone(dllist.first)
        self.assertEqual(dllist.first.value, 'a')

        self.assertIsNotNone(dllist.last)
        self.assertEqual(dllist.last.value, 'a')

        self.assertEqual(dllist.count, 1)

        dllist.push('b')

        self.assertEqual(dllist.first.value, 'a')
        self.assertEqual(dllist.last.value, 'b')
        self.assertEqual(dllist.count, 2)
        
        dllist.push('c')
        self.assertEqual(dllist.first.value, 'a')
        self.assertEqual(dllist.last.value, 'c')
        self.assertEqual(dllist.count, 3)

    def test_unshift(self):
        dllist = DoublyLinkedList()
        dllist.batch_populate(['a', 'b', 'c'])
        dllist.unshift('d')

        self.assertEqual(dllist.count, 4)
        self.assertEqual(dllist.first.value, 'd')
        self.assertEqual(dllist.first.next.value, 'a')

    def test_shift(self):
        dllist = DoublyLinkedList()
        dllist.batch_populate(['a', 'b', 'c'])
        dllist.shift()

        self.assertEqual(dllist.count, 2)
        self.assertEqual(dllist.first.value, 'b')

    def test_print(self):
        dllist = DoublyLinkedList()
        dllist.batch_populate(['a', 'b', 'c'])
        printout = dllist.print()
        self.assertEqual(printout, "a -> b -> c -> None")

    def test_pop(self):
        dllist = DoublyLinkedList()
        dllist.batch_populate(['a', 'b', 'c'])
        self.assertEqual(dllist.count, 3)

        popped = dllist.pop()

        self.assertIsInstance(popped, ListNode)
        self.assertEqual(dllist.count, 2)
        self.assertEqual(popped.value, 'c')

        self.assertEqual(dllist.last.value, 'b')

        dllist.push('d')
        popped = dllist.pop()

        self.assertIsInstance(popped, ListNode)
        self.assertEqual(dllist.count, 2)
        self.assertEqual(popped.value, 'd')

        self.assertEqual(dllist.last.value, 'b')

    def test_clear(self):
        dllist = DoublyLinkedList()
        dllist.batch_populate(['a', 'b', 'c'])
        dllist.clear()

        node = dllist.first
        while node:
            self.assertEqual(node.value, None)
            node = node.next

        self.assertEqual(dllist.count, 3)


if __name__ == '__main__':
    unittest.main()
