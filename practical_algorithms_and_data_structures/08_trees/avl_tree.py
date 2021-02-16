from binary_search_tree import BinarySearchTree, TreeNode


class AVLTreeNode(TreeNode):
    def __init__(self, *args, **kwargs):
        super(AVLTreeNode, self).__init__(*args, **kwargs)
        self.balance_factor = 0
