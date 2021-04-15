const util = require("util");

class BST {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }

  insert(value) {
    // we start at the root node.
    // it has two children, and both are null.
    let currentNode = this;
    while (true) {
      if (value < currentNode.value) {
        // go left in the tree
        if (currentNode.left) {
          currentNode = currentNode.left;
        } else {
          // there is no left child.
          currentNode.left = new BST(value);
          break;
        }
      } else {
        // the value is >= currentNode.value, therefore we are going to be moving right
        if (currentNode.right) {
          currentNode = currentNode.right;
        } else {
          currentNode.right = new BST(value);
          break;
        }
      }
    }
    return this;
  }
}

tree = new BST(10);
[5, 15, 2, 5, 1, 13, 22, 14].forEach((n) => tree.insert(n));
console.log(util.inspect(tree, { depth: null }));
