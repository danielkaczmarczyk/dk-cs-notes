def sequential_search(array, item):
    for thing in array:
        if thing == item:
            return True
    return False

def ordered_sequential_search(alist, item):
    position = 0

    while position < len(alist):
        if alist[position] == item:
            return True

        if alist[position] > item:
            return False

        position = position + 1

    return False


if __name__ == '__main__':
    array = [1, 15, 253, 4306, 543, 603, 43, 0, 436]
    item = 543
    print(sequential_search(array, item))
    item = 5433
    print(sequential_search(array, item))

    testlist = [0, 1, 2, 8, 13, 17, 19, 32, 42,]
    print(ordered_sequential_search(testlist, 3))
    print(ordered_sequential_search(testlist, 13))
