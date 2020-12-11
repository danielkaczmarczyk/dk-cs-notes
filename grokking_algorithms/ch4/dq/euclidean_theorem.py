"""
we can use euclidean theorem to find a greatest common denominator
of two numbers.

to find GCD(A,B):
    - if A == 0, then GCD(A,B) == B, since GCD(0, B) = B
    - if B == 0, then GCD(A,B) == A, since GCD(A, 0) = A
    - write A in quotient remainder form:
        A = B * Q + R
    - find GCD(B,R) since GCD(A,B) == GCD(BR)
"""

def find_gcd(a,b):
    if a == 0:
        return b
    elif b == 0:
        return a

    r = a % b
    return find_gcd(b, r)

assert find_gcd(270, 192) == 6, 'find_gcd failed'

