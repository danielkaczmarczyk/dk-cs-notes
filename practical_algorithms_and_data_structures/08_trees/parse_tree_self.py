def build_tree(expression):
    pass


if __name__ == "__main__":
    expression = ['(', '3', '+', '(', '4', '*', '5' ,')',')']
    tree = build_tree(expression)
    print(tree)
