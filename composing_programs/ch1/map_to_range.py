def map_to_range(f, start, stop):
    while start < stop:
        print(f(start))
        start += 1


# map_to_range(lambda x : x ** 2, 0, 11)

def curry(f):
    def g(x):
        def h(y):
            return f(x, y)
        return h
    return g

def add(a, b):
    return a + b

curried_add = curry(add)
# print(curried_add(2)(2))

def uncurry(f):
    '''returns a two-arg version of the current curried fn'''
    def uncurried(x, y):
        return f(x)(y)
    return uncurried

uncurried_add = uncurry(curried_add)
print(uncurried_add(2, 2))

