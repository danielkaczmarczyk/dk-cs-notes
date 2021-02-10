from stack import Stack

class Converter():
    def __init__(self, n, base):
        self.nums = "123456789ABCDEF"
        self.n = n
        self.base = base
        self.result = None
        self.stack = Stack()

    def convert(self):

        while self.n != 0:
            rem = self.n % self.base
            self.stack.push(rem)
            result = self.n // self.base
            print(f"{self.n} // {self.base} = {result}. remainder: {rem}")
            self.n = result
        pass

        self.result = self.pop_numbers()

    def pop_numbers(self):
        result = ''
        while self.stack.size() > 0:
            result += str(self.stack.pop())
        return result


if __name__ == "__main__":
    c = Converter(233, 2)
    c.convert()
    print(c.result)

