const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');
  const time = process.hrtime();
  const re = /[.|#]+/g;
  input = [...input.matchAll(re)].map(match => match[0]);
  
  let x = 0;
  let y = 0;
  let movementPatterns = [
    [1, 1, 0],
    [1, 3, 0],
    [1, 5, 0],
    [1, 7, 0],
    [2, 1, 0]
  ];

  for (pattern of movementPatterns) {
    console.log(`checking pattern: ${pattern}`);
    const checkIfTree = () => {
      const tile = input[x][y];
      if (tile === '#') pattern[2]++;
      return tile;
    }

    while (x < input.length) {
      console.log(x, y, checkIfTree());
      x += pattern[0];
      y += pattern[1];
      if (y >= input[0].length) y = y % input[0].length;
    }
    x = 0; y = 0;
  }
  
  const treesMultiplied = movementPatterns
    .map(pat => pat[2])
    .reduce((a, b) => { return a * b }, 1);
  console.log(treesMultiplied);
  // perf
  const diff = process.hrtime(time);
  const nanoseconds = diff[0] * 1e9 + diff[1];
  console.log(`Completed in: ${(nanoseconds * 1e-6).toFixed(4)}ms`);
}

solve();

