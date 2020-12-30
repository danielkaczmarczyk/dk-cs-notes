PAIRINGS = {
    '(': ')',
    '{': '}',
    '[': ']'
}

def is_balanced(parens):
    stack = []
    for p in parens:
        if p in PAIRINGS:
            stack.append(p)
        else:
            try:
                for k, v in PAIRINGS.items():
                    if v == p:
                        expected_bracket = k
                if stack[-1] == expected_bracket:
                    stack.pop()
            except IndexError:
                print(stack, parens)
                return False
    print(stack, parens)
    return len(stack) == 0


results = [
    is_balanced('{{([][])}()}'),
    is_balanced('{[])'),
    is_balanced('((()))'),
    is_balanced('(()'),
    is_balanced('())')
]

print(results)
print([True, False, True, False, False])

