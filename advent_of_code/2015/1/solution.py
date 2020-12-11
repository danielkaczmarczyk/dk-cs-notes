class Solver():
    def __init__(self):
        self.input = open('input.txt', 'r').read()
        self.floor = 0
        # for solve_2, to track the position of the char
        self.current_char = 0
        self.basement_logged = False

    def move(self):
        for bracket in self.input:
            if self.floor == -1 and not self.basement_logged:
                print(f'Santa enters the basement at {self.current_char}')
                self.basement_logged = True
            if bracket == '(':
                self.floor +=1
            elif bracket == ')':
                self.floor -= 1
            self.current_char += 1

    def reset_counters(self):
        self.current_char = 0
        self.floor = 0

    def solve(self):
        self.move()
        print(f'Santa ended on floor {self.floor} in part 1')
        self.reset_counters()

solver = Solver()
solver.solve()



