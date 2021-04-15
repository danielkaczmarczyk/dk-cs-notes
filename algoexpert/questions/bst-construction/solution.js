const util = require("util");

class BST {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }

  insert(value) {
    let currentNode = this;
    while (true) {
      if (value < currentNode.value) {
        if (currentNode.left) {
          currentNode = currentNode.left;
        } else {
          currentNode.left = new BST(value);
          break;
        }
      } else {
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
    let currentNode = this;

    while (true) {
      if (currentNode.value === value) return true;

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
