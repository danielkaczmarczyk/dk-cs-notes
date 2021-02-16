from binary_search_tree import BinarySearchTree, TreeNode


class AVLTreeNode(TreeNode):
    def __init__(self, *args, **kwargs):
        super(AVLTreeNode, self).__init__(*args, **kwargs)
        self.balance_factor = 0


class AVLTree(BinarySearchTree):

    TreeNodeClass = AVLTreeNode

    def _put(self, key, val, node):
        if key < node.key:
            if node.left:
                self._put(key, val, node.left)
            else:
                node.left = self.TreeNodeClass(key, val, parent=node)
                self.update_balance(node.left)
        else:
            if node.right:
                self._put(key, val, node.right)
            else:
                node.right = self.TreeNodeClass(key, val, parent=node)
                self.update_balance(node.right)
