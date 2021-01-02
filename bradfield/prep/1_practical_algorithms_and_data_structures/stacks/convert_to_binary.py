from stack import Stack

def convert_to_binary(i):
    stack = Stack()
    while i > 0:
        res, rem = divmod(i, 2)
        stack.push(rem)
        i = res

    binary = ''
    while not stack.is_empty():
        binary += str(stack.pop())
    return binary

assert convert_to_binary(233) == '11101001', 'oops'
assert convert_to_binary(42) == '101010', 'oops'

