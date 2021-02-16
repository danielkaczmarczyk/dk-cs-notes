def right_rotate(a_list, n):
    result = [None for x in a_list]

    for index in range(n):
        result[index + n - 1] = a_list[index]

    for index in range(n, len(a_list)):
        print(f"{index=}")
        print(f"{a_list[index]=}")
        location = index - n
        print(f"{location=}")
        result[location] = a_list[index]

    return result

if __name__ == '__main__':
    a_list = [10, 20, 30, 40, 50]
    a_n = 3
    a_result = [30, 40, 50, 10, 20]
    result = right_rotate(a_list, a_n)
    message = f"No match. {result=}"

    assert result == a_result, message

