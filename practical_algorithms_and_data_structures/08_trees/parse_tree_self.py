def build_tree(expression):
    OPERATORS = ['*', '-', '+', '/']
    LEFT_PAREN = '('
    RIGHT_PAREN = ')'

    tree = {}
    stack = [tree]
    current_node = tree

    for token in expression:
        print(f"{stack=}")
        if token == LEFT_PAREN:
            new_node = {}
            current_node['left'] = new_node
            stack.append(new_node)
            current_node = stack[-1]
        elif token == RIGHT_PAREN:
            current_node = stack.pop()
        elif token in OPERATORS:
            current_node['val'] = token
            new_node = {}
            current_node['right'] = new_node
            stack.append(new_node)
            current_node = stack[-1]
        elif isinstance(int(token), int):
            current_node['val'] = token
            current_node = stack.pop()
        else:
            print(f"THIS SHOULD NOT HAPPEN. {token=}")

    print(f"{stack=}")
    print(f"{tree=}")
    return tree


if __name__ == "__main__":
    #expression = ['(', '3', '+', '(', '4', '*', '5' ,')',')']
    expression = ['(', '2', '+', '2', ')']
    tree = build_tree(expression)
    #expected = {'val': '+', 'left': { 'val': 3 }, 'right': { 'val': 'x', 'left': { 'val': 4 }, 'right': { 'val': 5 }}}
