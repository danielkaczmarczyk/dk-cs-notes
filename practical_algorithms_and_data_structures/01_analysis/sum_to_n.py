import time

def sum_to_n(n):
    start = time.time()

    total = 0
    for i in range(n + 1):
        total += i

    end = time.time()
    return total, end - start

def smarter_sum(n):
    start = time.time()
    result = (n * (n + 1)) / 2
    return  result, time.time() - start

if __name__ == "__main__":
    n = 1_000_000
    for _ in range(15):
        result, t = sum_to_n(n)
        result_2, t_2 = smarter_sum(n)
        print(f"sum_to_n({n}) = {result}, in: {t} seconds")
        print(f"smarter_sum({n}) = {result_2}, in: {t_2} seconds")
        print()
