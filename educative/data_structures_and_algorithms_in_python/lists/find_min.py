def find_min(array):
    result = array[0]
    for item in array:
        if item < result:
            result = item
    return result

if __name__ == '__main__':
    list_1 = [9, 2, 3, 6]
    result_1 = 2

    assert find_min(list_1) == result_1
