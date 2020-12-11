const readFile = require('../../utils/readFile');

const solve = async () => {
  // let input = await readFile('./input.txt');
  let input = await readFile('./testInput.txt');

  const re = /(?<letters>[a-z|-]+)(?<id>\d{3})(?<checksum>\[[a-z]{5}\])/g;

  let idSum = 0;

  [...input.matchAll(re)].forEach(line => {
    let {checksum, id, letters} = line.groups;
    // calculate my own checksum
    letters = letters.replace(/-/g, '');
    const letterCounts = {};

    for (letter of letters) {
      if (letterCounts[letter] === undefined) {
        letterCounts[letter] = 1;
      } else {
        letterCounts[letter]++;
      }
    }

    let lettersArray = [];

    for (let letter in letterCounts) {
      lettersArray.push([letter, letterCounts[letter]]);
    }

    console.log(lettersArray);

    lettersArray = lettersArray
      .sort((a, b) => a[1] - b[1])
      .reverse()
      .map(item => item[0])

    let mostPopular = lettersArray.slice(0, 5).sort();

    console.log(lettersArray);
    console.log(mostPopular);
    console.log('---------------');
    // compare to the original
    // if matches, sum up the sector ids
  });
}

solve();

