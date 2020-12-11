memo_calls = 1
calls = 1
memo = {}

def fib_memo(n):
    '''computes the value of the nth number in the fibonacci series
        >>>fibonacci(5)
        5
    '''
    global memo_calls
    memo_calls += 1

    if n not in memo:
        if n == 0:
            return 1
        if n == 1:
            return 2
        val = fib_memo(n - 2) + fib_memo(n - 1)
        memo[n] = val
        return val
    else:
        return memo[n]
        
def fib(n):
    global calls
    calls += 1
    if n == 0:
        return 1
    if n == 1:
        return 2
    return fib(n - 2) + fib(n - 1)

def call(n):
    fib_memo(n)
    fib(n)

call(35)
print(f'{memo_calls = }')
print(f'{calls = }')

