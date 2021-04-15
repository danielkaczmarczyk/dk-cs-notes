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

  contains(value) {
    // keep searching, similarly to insertion, until we find a value.
    let currentNode = this;

    // searching !
    while (true) {
      // check if we found it
      if (currentNode.value === value) return true;

      // if we did not find the node, we need to move.
      if (currentNode.value > value) {
        if (currentNode.left) {
          currentNode = currentNode.left;
        } else {
          return false;
        }
      } else if (currentNode.value < value) {
        if (currentNode.right) {
          currentNode = currentNode.right;
        } else {
          return false;
        }
      }
    }
  }
}

tree = new BST(10);
[5, 15, 2, 5, 1, 13, 22, 14].forEach((n) => tree.insert(n));
//console.log(util.inspect(tree, { depth: null }));
//console.log(tree.contains(124));
