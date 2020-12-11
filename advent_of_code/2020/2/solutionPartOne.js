const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');
  const re = /(\d+)-(\d+)\s+([a-z]):\s+([a-z]+)/g
  let validPws = 0;

  input = [...input.matchAll(re)].forEach(match => {
    let [, min, max, letterToCount, password] = match;

    let letterCount = 0;
    for (letter of password) {
      if (letter === letterToCount) letterCount += 1;
    }

    min = parseInt(min); max = parseInt(max); 
    let isValid = true;

    if (letterCount > max) isValid = false;
    if (letterCount < min) isValid = false;

    let ds = `${letterToCount} in ${password}: ${letterCount}`;
    ds += ` in ${min}-${max}? : ${isValid}`;
    if (isValid) validPws += 1;

    // console.log(ds);
  });
  console.log(`-`.repeat(33));
  console.log(`n of valid passwords: ${validPws}`);
}

solve();

