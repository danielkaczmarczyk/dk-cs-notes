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
        if self.table[location] is not None:
            print("collision detected!")
            print(self)
            print(f"placement error, slot {location} in use by value {self.table[location]}")
            print("attempting to resolve the collision by linear probing")
            return -1
        self.table[location] = item
        return location

    def find(self, item)
        location = item % self.size
        if self.table[location] != item:
            print("need to probe")
        else:
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

    for n in [54, 26, 93, 17, 77, 31, 44, 55, 20]:
        naive_hash.place(n)

    print(naive_hash)
