const util = require("util");

const log = console.log;

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

  getMinValue() {
    let currentNode = this;
    while (true) {
      if (currentNode.left === null) return currentNode.value;
      currentNode = currentNode.left;
    }
  }

  getMaxValue() {
    let currentNode = this;
    while (true) {
      if (currentNode.right === null) return currentNode.value;
      currentNode = currentNode.right;
    }
  }

  remove(value, parentNode = null) {
    let currentNode = this;

    // removal is a 2- step process. first find the node you want to remove
    while (currentNode !== null) {
      if (value < currentNode.value) {
        parentNode = currentNode;
        currentNode = currentNode.left;
      } else if (value > currentNode.value) {
        parentNode = currentNode;
        currentNode = currentNode.right;
      } else {
        // the main branch of deletion -> it means we've found the node we are to delete!
        // CASE: node that has 2 children nodes
        // find the smallest val of the right subtree
        // replace it with the value that we're removing
        if (currentNode.left !== null && currentNode.right !== null) {
          currentNode.value = currentNode.right.getMinValue();
          // we've set currentNode.value to be the smallest value
          // now we want to remove the node whose value we snatched
          // important - we're passing the parent node!
          currentNode.right.remove(currentNode.value, currentNode);
          // we are gonna come back to the root node case
        } else if (parentNode === null) {
          // we already dealt with a case where the node has two kids so we gon'
          // just do left and right here
          if (currentNode.left !== null) {
            currentNode.value = currentNode.left.value;
            currentNode.right = currentNode.left.right;
            currentNode.left = currentNode.left.left;
          } else if (currentNode.right !== null) {
            currentNode.value = currentNode.right.value;
            currentNode.left = currentNode.right.left;
            currentNode.right = currentNode.right.right;
          } else {
            // the root node has no parent nodes and has no children
            // more of a mock case - could be disregarded
            currentNode.value = null;
          }
        } else if (parentNode.left == currentNode) {
          // that node is a left child of its parent node
          // therefore the parent node.left is gonna be reassigned to either
          // the left child node of our current node, if it has one
          // otherwise, the rc n
          if (currentNode.left !== null) {
            parentNode.left = currentNode.left;
          } else {
            parentNode.left = currentNode.right;
          }
        } else if (parentNode.right == currentNode) {
          if (currentNode.left !== null) {
            parentNode.right = currentNode.left;
          } else {
            parentNode.right = currentNode.right;
          }
        }
      }
      break;
    }
    return this;
  }
}

tree = new BST(10);
[5, 15, 2, 5, 1, 13, 22, 14].forEach((n) => tree.insert(n));
