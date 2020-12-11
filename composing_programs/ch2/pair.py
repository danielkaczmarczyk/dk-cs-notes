def pair(x, y):
    def get(index):
        if index == 0:
            return x
        elif index == 1:
            return y
    return get

def select(pair, i):
    return pair(i)

a = pair(2,3)
print(select(a, 0))
print(select(a, 1))

