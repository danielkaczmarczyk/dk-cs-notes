const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');
  console.log(input);
}

const time = process.hrtime();
solve();
const diff = process.hrtime(time);
const nanoseconds = diff[0] * 1e9 + diff[1];
console.log(`Completed in: ${nanoseconds * 1e-6} ms`);

