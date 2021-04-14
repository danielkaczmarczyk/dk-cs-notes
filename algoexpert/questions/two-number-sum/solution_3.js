function twoNumberSum(array, targetSum) {
  const numbers = {};
  for (let i = 0; i < array.length; i++) {
    const currentInt = array[i];
    const complement = targetSum - currentInt;
    numbers[currentInt] = complement;
    if (currentInt === complement) continue;
    if (numbers[complement]) {
      return [currentInt, complement];
    }
  }
  return [];
}
