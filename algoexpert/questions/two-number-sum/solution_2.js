function twoNumberSum(array, targetSum) {
  for (let i = 0; i < array.length; i++) {
    const currentInt = array[i];
    const complement = targetSum - currentInt;
    if (complement === currentInt) continue;
    if (array.includes(complement)) return [currentInt, complement];
  }
  return [];
}
