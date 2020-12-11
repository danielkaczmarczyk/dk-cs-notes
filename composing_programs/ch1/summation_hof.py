def summation(n, term):
    total, k = 0, 1
    while k <= n:
        total, k = total + term(k), k + 1
    return total

def cube(x):
    return x * x * x

def sum_cubes(x):
    return summation(x, cube)

def identity(x):
    return x

def sum_naturals(x):
    return summation(x, identity)

print(sum_cubes(2))
print(sum_naturals(10))

