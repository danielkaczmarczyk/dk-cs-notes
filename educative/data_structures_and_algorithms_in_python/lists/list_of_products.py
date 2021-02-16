def find_product(array):
    result = [1 for x in array]
    for i in range(len(array)):
        for j in range(len(array)):
            if j is not i:
                result[i] *= array[j]
    return result

if __name__ == '__main__':
    list_1 = [1, 2, 3, 4]
    list_2 = [4, 2, 1, 5, 0]
    result_1 = [24, 12, 8, 6]
    result_2 = [0, 0, 0, 0, 40]

    assert find_product(list_1) == result_1
    assert find_product(list_2) == result_2
