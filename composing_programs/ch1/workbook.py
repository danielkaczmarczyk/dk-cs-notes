def sum_naturals(n):
    total, i = 0, 1
    while i <= n:
        total += i
        i += 1
    return total

print(sum_naturals(5))

def sum_naturals_rec(n):
    if n == 1:
        return 1
    return n + sum_naturals_rec(n - 1)

print(sum_naturals_rec(5))

def sum_cubes(n):
    total, i = 0, 1
    while i <= n:
        total += i ** 3
        i += 1
    return total

print(sum_cubes(4))

def sum_cubes_rec(n):
    if n == 1:
        return 1
    return (n ** 3) + sum_cubes_rec(n - 1)

print(sum_cubes_rec(4))

def sum(n, term):
    total, i = 0, 1
    while i <= n:
        total += term(i)
        i += 1
    return total

print(sum(4, lambda x : x ** 3))
print(sum(5, lambda x : x ))


