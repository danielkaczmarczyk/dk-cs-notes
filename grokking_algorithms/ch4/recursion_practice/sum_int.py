
# sum all non-negative ints up to n

def sum_iter(n):
    sum = 0
    for i in range(n + 1):
        sum += i

    return sum

def sum(n):
    if n == 1:
        return 1
    return n + sum(n - 1)

print(sum_iter(10))
print(sum(10))
