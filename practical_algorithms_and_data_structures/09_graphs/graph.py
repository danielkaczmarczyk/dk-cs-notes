class Vertex(object):
    def __init__(self, key):
        self.key = key
        self.neighbors = {}

    def add_neighbor(self, neighbor, weight=0):
        self.neighbors[neighbor] = weight

    def __str__(self):
        return '{} neighbors: {}'.format(self.key, [x.key for x in self.neighbors])

    def get_connections(self):
        return self.neighbors.keys()

    def get_weight(self, neighbor):
        return self.neighbors[neighbor]
