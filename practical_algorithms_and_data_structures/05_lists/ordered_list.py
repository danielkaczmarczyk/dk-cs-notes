from unordered_list import Node, UnorderedList


class OrderedList(UnorderedList):

    def search(self):
        pass

    def add(self):
        pass


if __name__ == '__main__':
    import unittest

    
    class OrderedListTests(unittest.TestCase):

        def list_setup(self):
            ol = OrderedList()

            for n in [26, 31, 17, 54, 93, 77]:
                ol.add(n)

            return ol

        def test_search(self):
            pass

        def test_add(self):
            pass

