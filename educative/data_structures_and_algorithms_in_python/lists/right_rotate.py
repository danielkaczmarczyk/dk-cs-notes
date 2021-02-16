def right_rotate(a_list, n):
    pass

if __name__ == '__main__':
    a_list = [10, 20, 30, 40, 50]
    a_n = 3
    a_result = [30, 40, 50, 10, 20]
    result = right_rotate(a_list, a_n)
    message = f"No match. {result=}"

    assert result == a_result, message

