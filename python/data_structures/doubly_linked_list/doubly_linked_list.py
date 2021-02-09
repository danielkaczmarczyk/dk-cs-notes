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

    def remove_by_index(self, index):
        if index >= self.count:
            return self.count
        
        node = self.find_by_index(index)
        if index == 0:
            self.shift()
        elif index == self.count - 1:
            self.pop()
        else:
            node.prev.next = node.next
            node.next.prev = node.prev

            node.prev = None
            node.next = None

            self.count -= 1
        return self.count

    def find_by_index(self, index):
        if index == 0:
            return self.first
        elif index == self.count:
            return self.last

        current_index = 0
        node = self.first
        while current_index < self.count:
            if current_index == index:
                return node
            else:
                node = node.next
                current_index += 1
        return None

    def find_by_value(self, value):
        current_index = 0
        node = self.first
        while current_index < self.count:
            if node.value == value:
                return node
            else:
                node = node.next
                current_index += 1
        return None

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

