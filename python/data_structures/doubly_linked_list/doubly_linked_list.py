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
        node = self.last
        while node != None:
            print(node.value)
            node = node.next




class ListNode():
    def __init__(self, value):
        self.next = None
        self.prev = None
        self.value = value


# tests - to be moved out to a diff file (with an actual testing framework)

import unittest

class TestList(unittest.TestCase):

    def test_init(self):
        dllist = DoublyLinkedList()
        self.assertIsInstance(dllist, DoublyLinkedList)

if __name__ == '__main__':
    unittest.main()

