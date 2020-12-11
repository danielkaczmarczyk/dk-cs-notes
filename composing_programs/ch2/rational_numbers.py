from math import gcd

def rational(n, d):
    __gcd = gcd(n, d)
    return [n // __gcd, d // __gcd]

def num(rational):
    return rational[0]

def den(rational):
    return rational[1]

def represent(rational):
    print(f'{num(rational)}/{den(rational)}')

def add(r1, r2):
    _num = (num(r1) * den(r2)) + (num(r2) * den(r1))
    _den = den(r1) * den(r2)
    return rational(_num, _den)

def mul(r1, r2):
    return rational(num(r1) * num(r2), den(r1) * den(r2))

def eq(r1, r2):
    return num(r1) * den(r2) == num(r2) * den(r1)

two_thirds = rational(2, 3)
three_quarters = rational(3, 4)
seventeen_over_twelve = add(two_thirds, three_quarters)
represent(seventeen_over_twelve)

six_over_twelve = mul(two_thirds, three_quarters)
represent(six_over_twelve)

four_over_six = rational(4, 6)
print(eq(four_over_six, two_thirds))

