from stack import Stack

class Balancer():
    def __init__(self, input_string):
        self.opening = ['(', '{', '[']
        self.closing = [')', '}', ']']
        self.data = Stack()
        self.input_string = input_string
        self.balanced = False
        self.stack = Stack()
        self.balance()

    def balance(self):
        for bracket in self.input_string:
            if bracket in self.opening:
                self.stack.push(bracket)
            else:
                top = self.stack.peek()
                if self.matching_brackets(top, bracket):
                    self.stack.pop()

        if self.stack.is_empty():
            self.balanced = True
            return True
        return False

    def matching_brackets(self, opening, closing):
        if self.opening.index(opening) == self.closing.index(closing):
            return True
        return False
