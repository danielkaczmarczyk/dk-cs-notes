const assert = require('assert');

const arr = [-15, -5, -1, 0, 3, 5, 12, 59, 81, 333, 1539, 4964];
const binarySearch = (array, n) => {
  let min = 0;
  let max = array.length - 1;

  while (min <= max) {
    let guessIndex = Math.floor((max + min) / 2);
    let guess = array[guessIndex]; 
    if (guess === n) return guessIndex;
    if (guess < n) {
      min = guessIndex + 1;
    } else if (guess > n) {
      max = guessIndex - 1;
    }
  }
  return null;
}

const assertSearch = (n, i) => {
  assert.equal(binarySearch(arr, n), i, `finding ${n} has failed`);
}

const searches = [
  [-15, 0],      // find a small number
  [0, 3],        // find a med number
  [4964, 11],    // find a high number 
  [9999, null],  // non existing on the right
  [-9999, null], // non existing on the left
]

searches.forEach(search => assertSearch(...search));


