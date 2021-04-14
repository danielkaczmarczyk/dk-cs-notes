// O(n) time | O(n) space
function sortedSquaredArray(array) {
  // declaring an array of size n to hold the final results of squaring
  const squared = new Array(array.length).fill(0);

  let squaredPointer = squared.length - 1;
  let smallPointer = 0;
  let largePointer = array.length - 1;

  while (smallPointer <= largePointer) {
    const smaller = array[smallPointer];
    const larger = array[largePointer];
    // check which number gives us a larger square
    const largerNumber = Math.max(Math.abs(smaller), Math.abs(larger));
    // square it, assign it to the squared array
    const squaredLarger = Math.pow(largerNumber, 2);
    squared[squaredPointer] = squaredLarger;
    squaredPointer--;
    // move the pointer of the larger number up or down, depending on which pointer it was.
    if (squaredLarger === Math.pow(smaller, 2)) {
      // the number we placed in the array was the one that was pointed at by the smaller pointer
      smallPointer++;
    } else {
      // the number we placed in the array was the one that was pointed at by the larger pointer
      largePointer--;
    }
  }
  return squared;
}
