class Node():
    def __init__(self, value):
        self.value = value
        self.next = None


class UnorderedList():
    def __init__(self):
        self.head = None

    def add(self, item):
        pass

    def remove(self, item):
        pass

    def search(self, item):
        pass

    def is_empty(self):
        return self.head is None

    def size(self):
        pass

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
        

    unittest.main()

