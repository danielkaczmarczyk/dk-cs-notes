const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');

  const re = /(\d+)\s+(\d+)\s+(\d+)\n/g
  input = [...input.matchAll(re)].map(match => {
    return [match[1], match[2], match[3]].map(n => parseInt(n, 10));
  });

  const isTriangleValid = (x, y, z) => {
    return x + y > z && x + z > y && y + z > x;
  }

  input = input.filter(tr => isTriangleValid(...tr));

  console.log(input.length);
}

solve();

