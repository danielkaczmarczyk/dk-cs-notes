const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');
  const re = /\d+/g;
  const matches = [...input.matchAll(re)]
    .map(match => parseInt(match[0], 10))
    .sort((a, b) => a - b);

  /*
   * Looking at the dataset, it appears that there are not many
   * numbers that when summed woul be <= to 2020. That influences
   * the decisions regarding iteration.
   */

  for (let i = 0; i < matches.length; i++) {
    for (let j = matches.length - 1; j > 0; j--) {
      if (matches[i] + matches[j] === 2020) {
        console.log(`found it! ${matches[i]} + ${matches[j]}`);
        console.log(`multiplied: ${matches[i] * matches[j]}`);
      }
    }
  }

}

solve();

