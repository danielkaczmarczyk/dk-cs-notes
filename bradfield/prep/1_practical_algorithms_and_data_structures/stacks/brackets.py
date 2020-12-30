OPENING = '('

def is_balanced(parens):
    stack = []
    for p in parens:
        if p == OPENING:
            stack.append(p)
        else:
            try:
                stack.pop()
            except IndexError:
                return False
    return len(stack) == 0


results = [
    is_balanced('((()))'),
    is_balanced('(()'),
    is_balanced('())')
]

print(results)
print([True, False, False])

