def remove_even(array):
    return [x for x in array if x % 2 != 0]

if __name__ == '__main__':
    assert remove_even([2,4,6,1]) == [1], "remove_even failed"
