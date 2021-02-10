class Stack():
    def __init__(self):
        self.items = []
        self.count = 0

    def is_empty(self):
        if self.count == 0:
            return True
        return False

    def push(self, item):
        self.items.append(item)
        self.count += 1

    def pop(self):
        if not self.is_empty():
            self.count -= 1
            return self.items.pop()
        return None
    
    def peek(self):
        if not self.is_empty():
            return self.items[self.count - 1]
        return None

    def size(self):
        return self.count

