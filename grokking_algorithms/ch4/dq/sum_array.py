array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

def sum_array(arr):
    if len(arr) == 1:
        return arr[0]
    if len(arr) == 0:
        return 0
    return arr[-1] + sum_array(arr[:-1])


assert sum_array(array) == 55, 'sum_array failed'

