// The most efficient, running in O(nlog(n)) time, space complexity O(1).
function twoNumberSum(array, targetSum) {
  let arr = array.sort((a, b) => a - b);
  console.log(array);
  let leftPointer = 0;
  let rightPointer = arr.length - 1;

  while (leftPointer !== rightPointer) {
    const left = arr[leftPointer];
    const right = arr[rightPointer];
    const sum = left + right;
    console.log(
      `L: ${left}, R: ${right}, LP: ${leftPointer} RP: ${rightPointer} sum: ${sum} targetSum: ${targetSum}`
    );
    if (sum === targetSum) return [left, right];
    if (sum < targetSum) leftPointer++;
    if (sum > targetSum) rightPointer--;
  }
  return [];
}
