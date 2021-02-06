class DoublyLinkedList():
    def __init__(self):
        self.count = 0
        self.first = None
        self.last = None

    def clear(self):
        print("clearing list")

    def push(self, value):
        node = ListNode(value)
        if self.last == None:
            self.first = node
            self.last = node
        else:
            self.last.next = node
            node.prev = self.last
            self.last = node

        self.count += 1

    def pop(self):
        pass

    def unshift(self):
        pass

    def shift(self):
        pass

    def remove(self, node):
        pass

    def print(self):
        result = ''
        node = self.first
        while node != None:
            result += f"{node.value} -> "
            node = node.next
        result += "None"
        return result

    def batch_populate(self, items):
        for item in items:
            self.push(item)


class ListNode():
    def __init__(self, value):
        self.next = None
        self.prev = None
        self.value = value


# tests -----------------------------------------------------------------------
import unittest

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

    def test_print(self):
        dllist = DoublyLinkedList()
        dllist.batch_populate(['a', 'b', 'c'])
        printout = dllist.print()
        self.assertEqual(printout, "a -> b -> c -> None")



if __name__ == '__main__':
    unittest.main()

