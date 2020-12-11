from stack import Stack

def check_brackets(brackets):
    stack = Stack()

    opening_brackets = ['(', '[', '{']
    closing_brackets = [')', ']', '}']

    def is_opening(bracket):
        if bracket in opening_brackets:
            return True
        return False

    def is_pair(peeked_bracket, closing_bracket):
        peeked_index = opening_brackets.index(peeked_bracket)
        closing_index = closing_brackets.index(closing_bracket)
        if peeked_index == closing_index:
            return True
        return False

    for bracket in brackets:
        if is_opening(bracket):
            stack.push(bracket)
        else:
            peeked = stack.peek()
            if peeked is None:
                return False
            if is_pair(peeked, bracket):
                stack.pop()

    if (stack.size() == 0):
        return True
    return False

balanced = '[(([[(()()[]{})]]))]'
unbalanced = '[{[()]]}}'
no_opening = ')))[]'

print('checking balanced')
print(check_brackets(balanced))
print('checking unbalanced')
print(check_brackets(unbalanced))
print('checking no_opening')
print(check_brackets(no_opening))

