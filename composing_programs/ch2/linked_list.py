empty = 'empty'

def is_link(s):
    """s is a linked list if it is empty or a (first, rest) pair"""
    return s == empty or (len(s) == 2 and is_link(s[1]))

# a constructor for the linked lists
def link(first, rest):
    """Construct a linked list from its first element and the rest."""
    assert is_link(rest), "rest must be a linked list"""
    return [first, rest]

def first(s):
    """Returns a first element of a linked list s"""
    assert is_link(s), "first only applies to linked lists"
    assert s != empty, "empty linked list has no first element"
    return s[0]

def rest(s):
    """Returns the rest of the elements of a linked list s"""
    assert is_link(s), "rest only applies to linked lists"
    assert s != empty, "empty linked list has no rest"
    return s[1]

def len_link(s):
    """Returns length of a linked list s"""
    assert is_link(s), "len_link only applies to linked lists"""
    length = 0
    while s is not empty:
        s, length = rest(s), length + 1
    return length

def get_item(s, i):
    """get item of a linked list s at index i"""
    assert is_link(s), "get_item only applies to linked lists"
    index = 0
    while index != i:
        s, index = rest(s), index + 1
    return first(s)

four = link(1, link(2, link(3, link(4, empty))))

print(get_item(four, 2))

