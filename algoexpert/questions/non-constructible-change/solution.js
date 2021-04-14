// O(nlogn) time, O(n) size.
function nonConstructibleChange(coins) {
  coins = coins.sort((a, b) => a - b); // O(nlogn) time operation
  let change = 0;

  for (coin of coins) {
    if (coin > change + 1) return change + 1;
    change += coin;
  }

  return change + 1;
}
