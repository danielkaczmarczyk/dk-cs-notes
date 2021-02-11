
def recursive_fib(n):
    if n <= 1:
        return 1
    return recursive_fib(n - 1) + recursive_fib(n - 2)

def dynamic_fib(n):
    previous, current = 0, 1
    while previous < n:
        previous, current = current, previous + current
    return current

if __name__ == '__main__':
    print(recursive_fib(5))
    print(dynamic_fib(5))
