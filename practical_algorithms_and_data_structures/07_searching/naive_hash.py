class NaiveHash():

    def __init__(self, table_size):
        self.size = table_size
        self.table = [None for n in range(self.size)]

    def __repr__(self):
        rep = ''
        for item in self.table:
            rep += f"{str(item)} "
        return rep

    def place(self, item):
        location = item % self.size
        self.table[location] = item
        return location

    def count_empty_slots(self):
        empty_slots = 0
        for slot in self.table:
            if slot is None:
                empty_slots += 1
        return empty_slots

    def load_factor(self):
        return (self.size - self.count_empty_slots()) / self.size


if __name__ == '__main__':
    naive_hash = NaiveHash(11)
    place_error = 'error placing the value in correct spot'

    assert naive_hash.place(54) == 10, place_error
    assert naive_hash.place(26) == 4, place_error
    assert naive_hash.place(93) == 5, place_error
    assert naive_hash.place(17) == 6, place_error
    assert naive_hash.place(77) == 0, place_error
    assert naive_hash.place(31) == 9, place_error

    print(naive_hash)
