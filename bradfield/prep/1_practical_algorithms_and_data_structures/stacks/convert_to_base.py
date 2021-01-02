from stack import Stack

DIGITS_16 = '0123456789ABCDEF'


def convert_to_base(i, base):
    stack = Stack()

    while i > 0:
        res, rem = divmod(i, base)
        i = res
        if base == 16:
            stack.push(DIGITS_16[rem])
        else:
            stack.push(rem)

    result = '' 

    while not stack.is_empty():
        result += str(stack.pop())
    return result


assert convert_to_base(42, 2) == '101010', 'oops'
assert convert_to_base(233, 8) == '351', 'oops'
assert convert_to_base(233, 16) == 'E9', 'oops'

