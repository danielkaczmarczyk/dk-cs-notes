def find_2dg7():
    for n in range(10, 100):
        original = n
        second_digit = n % 10
        if second_digit == 0:
            pass
        elif original / second_digit == 7:
            print(f'{original = }')

find_2dg7()

