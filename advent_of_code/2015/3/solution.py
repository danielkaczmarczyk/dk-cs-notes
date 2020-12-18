test_input = '^v<>'

class Solver():
    def __init__(self):
        self.input = open('input.txt', 'r').read()
        self.santa = [0, 0]
        self.robo_santa = [0, 0]
        self.visited_houses = [] 

    def move(self, character, position):
        if character == '^':
            position[1] += 1
        elif character == 'v':
            position[1] -= 1
        elif character == '>':
            position[0] += 1
        elif character == '<':
            position[0] -= 1

    def visit_house(self, who):
        if who == 'santa':
            str_pos = str(self.santa)
        else:
            str_pos = str(self.robo_santa)
        if str_pos not in self.visited_houses:
            self.visited_houses.append(str_pos)

    def solve(self):
        for i, character in enumerate(self.input):
            if i % 2 == 0:
                self.move(character, self.santa)
                self.visit_house('santa')
            else:
                self.move(character, self.robo_santa)
                self.visit_house('robo_santa')
        print(self.robo_santa, self.santa)
        print(len(self.visited_houses))

solver = Solver()
solver.solve()


