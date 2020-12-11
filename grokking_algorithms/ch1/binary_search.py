def binary_search(array, number):
    low = 0
    high = len(array) - 1

    while low <= high:
        mid = (low + high) // 2 # the guess index
        guess = array[mid]
        if guess == number:
            return mid
        if guess < number:
            low = mid + 1
        else:
            high = mid - 1
    return None

nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

assert binary_search(nums, 3) == 3, 'binary search for 3 failed'
assert binary_search(nums, 11) == None, 'binary search for 11 failed'
assert binary_search(nums, 9) == 9, 'binary search for 9 failed'

print('all ok')
