def build_tree(expression):
    OPERATORS = ['*', '-', '+', '/']
    LEFT_PAREN = '('
    RIGHT_PAREN = ')'


    for token in expression:
        if token == LEFT_PAREN:
            print('Add a new node as the left child of the current node, and descend to the left child')
        elif token == RIGHT_PAREN:
            print('Go to the parent of the current node')
        elif isinstance(token, int):
            print('Set the root value of the current node to the number and return to parent')
        elif token in OPERATORS:
            print('Set the root value of the current node to the operator represented by th ecurrent token. Add a new node as the right child of the current node and descend to the right child.')
    pass


if __name__ == "__main__":
    expression = ['(', '3', '+', '(', '4', '*', '5' ,')',')']
    tree = build_tree(expression)
    expected = {'val': '+', 'left': { 'val': 3 }, 'right': { 'val': 'x', 'left': { 'val': 4 }, 'right': { 'val': 5 }}}
