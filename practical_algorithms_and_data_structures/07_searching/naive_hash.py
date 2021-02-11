class NaiveHash():

    def __init__(self, table_size):
        table = [None for n in range(table_size + 1)]


if __name__ == '__main__':
    naive_hash = NaiveHash(11)
    print(naive_hash.table)
