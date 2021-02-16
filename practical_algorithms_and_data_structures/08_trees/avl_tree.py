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

    def update_balance(self, node):
        if node.balance_factor > 1 or node.balance_factor < -1:
            self.rebalance(node)
            return
        if node.parent is not None:
            if node.is_left_child():
                node.parent.balance_factor += 1
            elif node.is_right_child():
                node.parent.balance_factor -= 1

            if node.parent.balance_factor != 0:
                self.update_balance(node.parent)

    def rotate_left(self, rotation_root):
        new_root = rotation_root.right
        rotation_root.right = new_root.left
        if new_root.left is not None:
            new_root.left.parent = rotation_root
        new_root.parent = rotation_root.parent
        if not rotation_root.parent:
            self.root = new_root
        else:
            if rotation_root.is_left_child():
                rotation_root.parent.left = new_root
            else:
                rotation_root.parent.right = new_root
        new_root.left = rotation_root
        rotation_root.parent = new_root
        rotation_root.balance_factor = \
            rotation_root.balance_factor + 1 - min(new_root.balance_factor, 0)
        new_root.balance_factor = \
            new_root.balance_factor + 1 + max(rotation_root.balance_factor, 0)

    def rotate_right(self, rotation_root):
        new_root = rotation_root.left
        rotation_root.left = new_root.right
        if new_root.right is not None:
            new_root.right.parent = rotation_root
        new_root.parent = rotation_root.parent
        if not rotation_root.parent:
            self.root = new_root
        else:
            if rotation_root.is_right_child():
                rotation_root.parent.right = new_root
            else:
                rotation_root.parent.left = new_root
        new_root.right = rotation_root
        rotation_root.parent = new_root
        rotation_root.balance_factor = \
            rotation_root.balance_factor + 1 - min(new_root.balance_factor, 0)
        new_root.balance_factor = \
            new_root.balance_factor + 1 + max(rotation_root.balance_factor, 0)

    def rebalance(self, node):
        if node.balance_factor < 0 and node.right:
            if node.right.balance_factor > 0:
                self.rotate_right(node.right)
                self.rotate_left(node)
            else:
                self.rotate_left(node)
        elif node.balance_factor > 0 and node.left:
            if node.left.balance_factor < 0:
                self.rotate_left(node.left)
                self.rotate_right(node)
            else:
                self.rotate_right(node)

