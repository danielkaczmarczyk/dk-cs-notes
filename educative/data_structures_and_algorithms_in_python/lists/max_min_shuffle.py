def max_min_shuffle(array):
    array.sort(reverse=True)
    result = []

    while array:
        result.append(array.pop(0))
        if array:
            result.append(array.pop())

    return result

if __name__ == '__main__':
    array = [1, 2, 3, 4, 5, 6, 7]
    expected = [7, 1, 6, 2, 5, 3, 4]
    result = max_min_shuffle(array)
    message = f"{result=}"
    assert result == expected, message
