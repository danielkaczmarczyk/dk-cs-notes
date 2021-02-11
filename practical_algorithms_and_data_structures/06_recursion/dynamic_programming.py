
def recursive_fib(n):
    if n <= 1:
        return 1
    return recursive_fib(n - 1) + recursive_fib(n - 2)

def dyn_fib(n):
    previous, current = 0, 1
    while previous < n:
        previous, current = current, previous + current
    return current

def rec_num_paths(h, w):
    if h == 0 or w == 0:
        return 1
    return rec_num_paths(h - 1, w) + rec_num_paths(h, w - 1)

def dyn_num_paths(h, w):
    pass


if __name__ == '__main__':
    result = rec_num_paths(2, 2)
    print(result)
