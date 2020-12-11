from stack import Stack

def dec_to_bin(decimal):
    binary = ''
    stack = Stack()

    while decimal > 0:
        remainder = decimal % 2
        decimal = decimal // 2
        stack.push(remainder)

    while not stack.is_empty():
        binary += str(stack.pop())

    return binary

assert dec_to_bin(242) == '11110010', 'dec_to_bin failed'

