// 'foolish' solution with O(n^2) running time.
function twoNumberSum(array, targetSum) {
  console.log(array);
  for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array.length; j++) {
      if (i == j) continue;
      if (array[i] + array[j] === targetSum) return [array[i], array[j]];
      console.log(`${array[i]}:${array[j]}`);
    }
  }

  return [];
}
