class List():
    def __init__(self):
        self.count = 0
        self.first = None
        self.last = None

    def clear(self):
        print("clearing list")

    def push(self, value):
        node = ListNode(value)
        if list.last == None:
            list.first = node
            list.last = node
        else:
            list.last.next = node
            node.prev = list.last
            list.last = node

        list.count += 1

    def pop(self):
        pass

    def unshift(self):
        pass

    def shift(self):
        pass

    def remove(self, node):
        pass


class ListNode():
    def __init__(self, value):
        self.next = None
        self.prev = None
        self.value = value


# tests - to be moved out to a diff file (with an actual testing framework)

dllist = List()
dllist.push('hello world')

print(dllist)
