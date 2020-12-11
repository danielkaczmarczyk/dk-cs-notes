from stack import Stack

def reverse(string):
    stack = Stack()

    reversed_string = ''

    for letter in string:
        stack.push(letter)

    while not stack.is_empty():
        reversed_string += stack.pop()

    return reversed_string

print(reverse('daniel'))

