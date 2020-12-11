from doctest import testmod

def sum_naturals(n):
    """Return a sum of x natural numbers
    
    >>> sum_naturals(10)
    55
    >>> sum_naturals(100)
    5050
    """
    total, i = 0, 1
    while i <= n:
        total, i = total + i, i + 1
    return total

if __name__ == "__main__":
    testmod(verbose = True)

