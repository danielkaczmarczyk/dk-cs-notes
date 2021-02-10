class Converter():
    def __init__(self, n, base):
        self.n = n
        self.base = base
        self.result = None
        self.convert()

    def convert():

        while self.n != 0:
            remainder = self.n % self.base
            result = self.n // self.base
            print(f"{self.n} // {self.base} = {result}. remainder: {rem}")
            self.n = result
        pass

if __name__ == "__main__":
    c = Converter(233, 2)
    print(c.result)

