const readFile = require('../../utils/readFile');
const solve = async () => {
  let input = await readFile('./input.txt');
  const re = /(\d+)-(\d+)\s+([a-z]):\s+([a-z]+)/g
  let validPws = 0;

  input = [...input.matchAll(re)].forEach(match => {
    let [, firstIndex, secondIndex, letter, password] = match;
    let isValid = false;

    firstIndex = parseInt(firstIndex);
    secondIndex = parseInt(secondIndex); 

    const firstIndexRequirement = password[firstIndex - 1] === letter;
    const secondIndexRequirement = password[secondIndex - 1] === letter;

    isValid = firstIndexRequirement ^ secondIndexRequirement;
    if (isValid) validPws += 1;
  });
  console.log(`n of valid passwords: ${validPws}`);
}

const hrstart = process.hrtime();
solve();
console.log(`took ${(process.hrtime(hrstart)[1] * 1e-6).toFixed(4)}ms`);

