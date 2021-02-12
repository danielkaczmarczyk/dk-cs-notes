def build_tree(expression):
    OPERATORS = ['*', '-', '+', '/']
    LEFT_PAREN = '('
    RIGHT_PAREN = ')'

    tree = {}
    stack = [tree]
    current_node = tree

    for token in expression:
        if token == LEFT_PAREN:
            pass
        elif token == RIGHT_PAREN:
            pass
        elif isinstance(token, int):
            pass
        elif token in OPERATORS:
            pass


if __name__ == "__main__":
    expression = ['(', '3', '+', '(', '4', '*', '5' ,')',')']
    tree = build_tree(expression)
    expected = {'val': '+', 'left': { 'val': 3 }, 'right': { 'val': 'x', 'left': { 'val': 4 }, 'right': { 'val': 5 }}}
