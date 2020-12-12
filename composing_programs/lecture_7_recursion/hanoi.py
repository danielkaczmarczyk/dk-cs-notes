def pm(_from, _to):
    print(f'{_from} -> {_to}')

def hanoi(n, start, end):
    if n == 1:
        pm(start, end)
    else:
        other = 6 - (start + end)
        hanoi(n - 1, start, other)
        pm(start, end)
        hanoi(n - 1, other, end)

hanoi(3, 1, 3)
