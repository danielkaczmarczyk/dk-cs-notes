class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    @classmethod
    def get_number_int(self, l_list):
        n_arr = []
        node = l_list
        while node is not None:
            n_arr.insert(0, str(node.val))
            node = node.next
        return int(''.join(n_arr))

    @classmethod
    def create_linked_list_from_int(self, integer):
        stringified = str(integer)[::-1]
        node = ListNode(stringified[0])
        for n in stringified[1:]:
            new_node = ListNode(n, node)
            node = new_node
        return node

    @classmethod
    def addTwoNumbers(self, l1, l2):
        lists = [l1, l2]
        numbers = [self.get_number_int(ll) for ll in lists]
        added = sum(numbers)
        reversed = str(added)[::-1]
        return self.create_linked_list_from_int(reversed)

# l1 = Solution.create_linked_list_from_int(243)
# l2 = Solution.create_linked_list_from_int(564)
# result_of_l1_plus_l2 = Solution.addTwoNumbers(l1, l2)

