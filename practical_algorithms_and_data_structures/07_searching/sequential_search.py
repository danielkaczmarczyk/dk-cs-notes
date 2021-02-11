def sequential_search(array, item):
    for thing in array:
        if thing == item:
            return True
    return False

if __name__ == '__main__':
    array = [1, 15, 253, 4306, 543, 603, 43, 0, 436]
    item = 543
    print(sequential_search(array, item))
    item = 5433
    print(sequential_search(array, item))
