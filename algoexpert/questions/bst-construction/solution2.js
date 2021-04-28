const util = require("util");

class BST {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }

  insert(valueInsert) {
    let currentNode = this;
    while (true) {
      if (valueInsert < currentNode.value) {
        if (currentNode.left) {
          currentNode = currentNode.left;
        } else {
          currentNode.left = new BST(valueInsert);
          break;
        }
      } else {
        if (currentNode.right) {
          currentNode = currentNode.right;
        } else {
          currentNode.right = new BST(valueInsert);
          break;
        }
      }
    }
  }
}

const tree = new BST(10);
[5, 15, 2, 5, 1, 13, 22, 14, 12].forEach((n) => tree.insert(n));

console.log(util.inspect(tree, false, null, true));
