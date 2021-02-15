class BinaryHeap(object):
    def __init__(self):
        self.items = [0]

    def __len__(self):
        return len(self.items) - 1


