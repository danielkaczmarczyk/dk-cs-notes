arr = [1, 2, 3, 4, 5, 6, 'dog', 3.14]

def count_items(arr):
    ln = len(arr)
    if ln == 0:
        return 0
    if ln == 1:
        return 1
    arr.pop()
    return 1 + count_items(arr)

assert count_items(arr) == 8, 'count_items failed'

