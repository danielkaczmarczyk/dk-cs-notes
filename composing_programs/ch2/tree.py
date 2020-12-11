def tree(root_label, branches=[]):
    for branch in branches:
        assert is_tree(branch), 'branches must be trees'
    return [root_label] + branches # i've deleted the list() call on branches.

def label(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if len(tree) < 1 or type(tree) != list:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def is_leaf(tree):
    return not branches(tree)

def count_leaves(tree):
    if is_leaf(tree):
        return 1
    else:
        leaf_count = 0
        for branch in branches(tree):
            leaf_count += count_leaves(branch)
        return leaf_count

def fib(n):
    '''
        returns a fib number at position n, 1-indexed
        where fibonacci numbers are: 0, 1, 1, 2, 3, 5, 8, 13 etc.
    '''
    if n == 1:
        return 0
    if n == 2:
        return 1
    return fib(n - 2) + fib(n - 1)

def fib_tree(n):
    if n == 0 or n == 1:
        return tree(n)
    else:
        left, right = [fib_tree(n - 2), fib_tree(n -1)]
        fib_n = label(left) + label(right)
        return tree(fib_n, [left, right])

# data for testing
t = tree(3, [tree(1), tree(2, [tree(1), tree(1)])])
t1 = tree(1)
t2 = tree(1, [tree(2)])
t3 = tree(1, [tree(2), tree(3)])
t4 = tree(1, [tree(2), tree(3), tree(4)])
t5 = tree(1, [tree(2, [tree(5), tree(6)]), tree(3), tree(4)])
t6 = tree(1, [tree(2, [tree(5, [tree(7), tree(8), tree(9)]), tree(6)]), tree(3), tree(4)])

print(tree(0, [tree(x) for x in [1, 2, 3, 4, 5, 6, 7]]))
