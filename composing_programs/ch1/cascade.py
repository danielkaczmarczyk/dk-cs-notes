def cascade(n):
    if n < 10:
        print(n)
    else:
        print(n)
        cascade(n // 10)
        print(n)

# cascade(2013)

'''
    there is a redundancy of one print statement,
    to alleviate it, we can omit the base case statement
    at the beginning. i find it less readable
'''

def cascade(n):
    print(n)
    if n >= 10:
        cascade(n // 10)
        print(n)


cascade(2013)

