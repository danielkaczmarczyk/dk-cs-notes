def divisors(n):
    return [x for x in range(1, n) if n % x == 0]

def width(area, h):
    return area // h

def perimeter(w, h):
    return 2 * (w + h)


area = 80
possible_h = divisors(area)
print(possible_h)
for h in possible_h:
    w = width(area, h)
    print(f'perimeter: {perimeter(w, h)}')
