def multiply(m, n):
    if n == 1:
        return m
    return multiply(m, n - 1) + m

def hailstone_iter(n):
    """Print out the hailstone sequence starting at and and return the n elements in it.
    Hailstone sequence: if n is even, divide it by 2. If it is odd, multiply by 3 and + 1.
    Repeat process until n is 1.
    """
    count = 1
    print(n)
    while n != 1:
        count += 1
        if n % 2 == 0:
            n = n // 2
        else:
            n = (n * 3) + 1
        print(n)
    print(f'{count = }')

def hailstone(n):
    print(n)
    if n == 1:
        return 1
    elif n % 2 == 0:
        return hailstone(n // 2) + 1
    else:
        return hailstone((n * 3) + 1) + 1
        
def merge(n1, n2):
    '''takes as input two numbers with their digits in decreasing order and
    returns a single number with the digits of the two, in decreasing order.
    any number merged with 0 is that number.'''
    if n1 // 10 == 0 and n2 // 10 == 0:
        big = max([n1, n2])
        small = min([n1, n2])
        if small == 0:
            small = '' 
        return(str(big) + str(small))
    return merge(n1 // 10, n2 // 10) + merge(n1 % 10, n2 % 10) 

def make_repeater(f, x):
    '''return a function that will call f on x n times'''
    def repeat(n):
        result = x
        i = 1
        while i <= n:
            result = f(result)
            i += 1
        return result
    return repeat

def make_repeater(f, x):
    '''recursive version of the above'''
    def repeat(n):
        if n == 0:
            return x
        else:
            return f(repeat(n - 1))
    return repeat

incr_1 = make_repeater(lambda x : x + 1, 1)
print(incr_1(3))





















