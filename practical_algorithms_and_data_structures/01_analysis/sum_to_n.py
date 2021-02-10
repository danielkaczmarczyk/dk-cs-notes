def sum_to_n(n):
    total = 0
    for i in range(n + 1):
        total += i
    return total

if __name__ == "__main__":
    n = 3

    print(sum_to_n(n))
