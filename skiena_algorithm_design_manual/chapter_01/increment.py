def increment(y):
    if y == 0:
        return 1
    else:
        if y % 2 == 1:
            return 2 * increment(y / 2)
        else:
            return y + 1

if __name__ == '__main__':
    print(increment(530))
