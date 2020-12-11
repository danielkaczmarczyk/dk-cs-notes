const assert = require('assert');

const arr = [-3, 9, 5, 7, 4, 6, 1, 8, 2, -11, 0];
const arr2 = [1234, -666, 3, 3, 0, 0, 0, 1, 3423, -1000];
const selectionSort = (arr) => {
  let sortedIndex = 0;
  let notSorted = true;

  while (notSorted) {
    let indexOfSmallestValue = sortedIndex;

    for (let i = sortedIndex; i < arr.length; i++) {
      if (arr[i] < arr[indexOfSmallestValue]) {
        indexOfSmallestValue = i;
      }
    };
    let smallestValue = arr[indexOfSmallestValue];

    if (indexOfSmallestValue === sortedIndex) {
      // pass
    } else {
      let swap = arr[sortedIndex];
      arr[sortedIndex] = smallestValue;
      arr[indexOfSmallestValue] = swap;
    }

    sortedIndex += 1;
    if (sortedIndex === arr.length) notSorted = false;
  }
  return arr;
}

console.log(arr.join(', '));
console.log(selectionSort(arr).join(', '));
console.log(arr2.join(', '));
console.log(selectionSort(arr2).join(', '));

