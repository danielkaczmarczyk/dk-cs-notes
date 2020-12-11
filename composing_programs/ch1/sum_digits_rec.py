def sum_digits(n):
    '''sums digits of a integer

    >>>sum_digits(135)
    9
    '''
    if n < 10:
        return n
    
    return (n % 10) + sum_digits(n // 10)

print(sum_digits(13519))

