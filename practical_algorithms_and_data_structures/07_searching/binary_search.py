def rec_binary_search(array, item):
    if not array:
        return False

    mid = len(array) // 2
    guess = array[mid]

    if guess == item:
        return True

    if guess > item:
        return rec_binary_search(array[:mid] ,item)
    elif guess < item:
        return rec_binary_search(array[mid + 1:] ,item)

    return False

if __name__ == '__main__':
    array = [n for n in range(26)]
    item = 1
    print(rec_binary_search(array, item))
