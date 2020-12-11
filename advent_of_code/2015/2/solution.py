import re
from functools import reduce

class Box():
    def __init__(self, dimensions_string):
        self.dimensions_string = dimensions_string
        self.parsed_dimensions = self.parse_dimensions(dimensions_string)
        self.l = self.parsed_dimensions[0]
        self.w = self.parsed_dimensions[1]
        self.h = self.parsed_dimensions[2]
        self.surfaces = self.calculate_surfaces()
        self.slack = self.calculate_slack()
        self.ribbon = self.calculate_ribbon()

    def __repr__(self):
        return f'_Box: {self.dimensions_string}_'

    def parse_dimensions(self, dimensions_string):
        dimensions = dimensions_string.split('x')
        return list(map(lambda n : int(n), dimensions))

    def calculate_surfaces(self):
        return [
                   2 * self.l * self.w,
                   2 * self.w * self.h,
                   2 * self.h * self.l
               ]

    def calculate_slack(self):
        surfaces_sorted = sorted(self.surfaces)
        return surfaces_sorted[0] / 2

    def total_paper_needed(self):
        return reduce(lambda a, b : a + b, self.surfaces) + self.slack

    def calculate_ribbon(self):
        sorted_dimensions = sorted(self.parsed_dimensions)
        ribbon = (sorted_dimensions[0] + sorted_dimensions[1]) * 2
        bow = self.h * self.l * self.w
        return ribbon + bow
        

class Solver():
    def __init__(self):
        self.input = open('input.txt', 'r').read()
        self.boxes = []
        self.total_paper_needed = 0
        self.total_ribbon_needed = 0

    def parse_input(self):
        dimensions_collection = re.findall(r'\d+x\d+x\d+', self.input)
        for dimensions in dimensions_collection:
            self.boxes.append(Box(dimensions))

    def calculate_total_paper_needed(self):
        for box in self.boxes:
            self.total_paper_needed += box.total_paper_needed()
        print(f'Total paper needed is {self.total_paper_needed}')

    def calculate_total_ribbon_needed(self):
        for box in self.boxes:
            self.total_ribbon_needed += box.calculate_ribbon()

    def solve(self):
        self.parse_input()
        self.calculate_total_paper_needed()
        self.calculate_total_ribbon_needed()
        print(f'Total ribbon needed is {self.total_ribbon_needed}')

solver = Solver()
solver.solve()

