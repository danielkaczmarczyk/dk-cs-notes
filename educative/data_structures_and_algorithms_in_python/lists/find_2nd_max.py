def find_2nd_max(array):
    nums = [array[0], array[0]]

    for i in range(1, len(array)):
        item = array[i]
        if item > nums[1]:
            nums[0] = nums[1]
            nums[1] = item
        else:
            nums[0] = item

    return nums[0]

if __name__ == '__main__':
    list_1 = [9, 2, 3, 6]
    result_1 = 6

    assert find_2nd_max(list_1) == result_1
