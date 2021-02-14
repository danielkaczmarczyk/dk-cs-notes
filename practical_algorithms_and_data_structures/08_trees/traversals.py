import operator

def build_tree(expression):
    OPERATORS = {
    '+': operator.add,
    '-': operator.sub,
    '*': operator.mul,
    '/': operator.truediv
    }

    LEFT_PAREN = '('
    RIGHT_PAREN = ')'

    tree = {}
    stack = [tree]
    current_node = tree


    for token in expression:
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
            stack.pop()
            current_node = stack[-1]

    return tree

def evaluate(tree):

    OPERATORS = {
    '+': operator.add,
    '-': operator.sub,
    '*': operator.mul,
    '/': operator.truediv
    }

    item = tree['val']
    if isinstance(item, int):
        return item
    else:
        operation = OPERATORS[item]
        return operation(evaluate(tree['left']), evaluate(tree['right']))

def preorder(node):
    if node:
        print(node['val'])
        preorder(node.get('left'))
        preorder(node.get('right'))

def postorder(node):
    if node:
        postorder(node.get('left'))
        postorder(node.get('right'))
        print(node['val'])

def inorder(node):
    if node:
        inorder(node.get('left'))
        print(node['val'])
        inorder(node.get('right'))

def construct_expression(tree):
    if tree is None:
        return ''

    left = construct_expression(tree.get('left'))
    right = construct_expression(tree.get('right'))
    val = tree['val']

    if left and right:
        return f"({left}{val}{right})"

    return val

if __name__ == "__main__":
    expression = ['(', 3, '+', '(', 4, '*', 5 ,')',')']
    tree = build_tree(expression)
    result = evaluate(tree)

    preorder(tree)
    print('-' * 10)
    postorder(tree)
    print('-' * 10)
    inorder(tree)

    print(construct_expression(tree))

