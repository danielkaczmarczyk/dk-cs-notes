const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');
  const re = /\d+/g;
  const matches = [...input.matchAll(re)]
    .map(match => parseInt(match[0], 10))
    .sort((a, b) => a - b);

  /*
   * with a triple nested loop
   * it would be wise to, for bigger sets
   * limit the amount of numbers considered
   * based on a rule that the sum can't exceed 2020
   * it would be beneficial to rule out too big results
   */

  for (let i = 0; i < matches.length; i++) {
    for (let j = 0; j < matches.length; j++) {
      for (let k = 0; k < matches.length; k++) {
        let indicies = new Set([i, j, k]);
        if (indicies.size !== 3) continue;
        if (matches[i] + matches[j] + matches[k]  === 2020) {
          console.log(matches[i], matches[j], matches[k]);
          console.log(matches[i] * matches[j] * matches[k]);
          process.exit(0);
        }
      }
    }
  }
}

solve();

