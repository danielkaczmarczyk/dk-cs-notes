from stack import Stack

class Balancer():
    def __init__(self, input_string):
        self.data = Stack()
        self.input_string = input_string
        self.balanced = False
        self.balance()

    def balance(self):
        return False