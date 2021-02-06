class DoublyLinkedList():
    def __init__(self):
        self.count = 0
        self.first = None
        self.last = None

    def clear(self):
        node = self.first
        while node:
            node.value = None
            node = node.next

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
        node_to_return = self.last
        self.last.prev.next = None
        self.last = self.last.prev
        self.count -= 1

        return node_to_return

    def unshift(self, value):
        node = ListNode(value)
        node.next = self.first
        self.first.prev = node
        self.first = node
        self.count += 1
        pass

    def shift(self):
        new_first = self.first.next
        new_first.prev = None
        self.first.next = None
        self.first = new_first
        self.count -= 1
        pass

    def remove(self, node):
        pass

    def remove_by_index(self, index):
        pass

    def find_by_index(self, index):
        current_index = 0
        node = self.first
        while current_index <= self.count:
            if current_index == index:
                return node
            else:
                node = node.next
                current_index += 1
        return None

    def find_by_value(self, value):
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

