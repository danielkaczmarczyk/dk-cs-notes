const readFile = require("../../utils/readFile");
const _ = require("lodash");

/*
  a string is nice if:
    - contains at least three vowels (can repeat)
    - at least one letter that appears twice in a row
    - it does not contain specific strings (ab, cd, pq, xy)

  to assert the first two things, it is necessary to look at the whole string
  whereas for the third criterium, in best cases it is possible to know on
  character 2.

  that assumes iterative process, though, and I wonder whether writing
  a regex wouldn't actually be way faster

*/

/**
 *
 * @param {String} string
 * @returns {Boolean} is the string nice or not
 */
const checkIfStringIsNice = (string) => {
  const bannedStrings = ["ab", "cd", "pq", "xy"];

  let nVowels = 0;
  let hasRepeat = false;
  let noBannedPairs = true;

  for (let i = 0; i < string.length; i++) {
    const char = string[i];

    if (/[aeiou]/g.test(char)) nVowels++;

    if (i !== 0) {
      const currentPair = `${string[i - 1]}${string[i]}`;

      // check for row-ness
      if (currentPair[0] === currentPair[1]) {
        hasRepeat = true;
      }

      // check for banned chars
      if (bannedStrings.includes(currentPair)) {
        noBannedPairs = true;
        return false;
      }
    }
  }
  return nVowels >= 3 && hasRepeat && noBannedPairs;
};

/**
 * A real quick test just to make sure that my checks are 'aight
 */
const test1 = () => {
  const niceStrings = ["ugknbfddgicrmopn", "aaa"];
  const naughtyStrings = [
    "jchzalrnumimnmhp",
    "haegwjzuvuyypxyu",
    "dvszwmarrgswjxmb",
  ];

  for (const string of niceStrings) {
    console.log(checkIfStringIsNice(string) === true);
  }

  for (const string of naughtyStrings) {
    console.log(checkIfStringIsNice(string) === false);
  }
};

/***** SOLUTIONS SECTION *****/

const solve = async () => {
  let strings = await readFile("./input.txt");
  strings = strings.split("\n").filter((s) => Boolean(s));
  let totalNiceStrings = 0;

  strings.forEach((string) => {
    if (checkIfStringIsNice(string)) totalNiceStrings++;
  });

  console.log(`There is a total of ${totalNiceStrings} nice strings.`);
};

/*
  Since for part2 santa changed his mind, we're gonna write another solve, with
  mostly duplicated code. It's not dry. It doesn't have to be. It's just a solve
  function. Please stop emailing me about this.

  This time it's ok to start iteration from the 1st index of the string, since
  i'm checking for pairs and i will be looking back.
*/

const test2 = () => {
  const niceStrings = ["qjhvhtzxzqqjkmpb", "xxyxx"];
  const naughtyStrings = ["uurcxstgmygtbstg", "ieodomkazucvgmuy"];

  for (const string of niceStrings) {
    console.log(checkIfStringIsNice2(string) === true);
  }

  for (const string of naughtyStrings) {
    console.log(checkIfStringIsNice2(string) === false);
  }
};

const checkIfStringIsNice2 = (string) => {
  // santa's wishes
  let pairOfTwoNotOverlapping = false;
  let oneLetterTwiceWithOneBetweenThem = false;

  const pairs = {};

  for (let i = 1; i < string.length; i++) {
    // do checks for potno
    const currentPair = string[i - 1] + string[i];
    if (pairs[currentPair] === undefined) {
      pairs[currentPair] = [];
      pairs[currentPair].push([i - 1, i]);
    } else {
      pairs[currentPair].push([i - 1, i]);
    }

    // do checks for oltwobt
    if (i > 1) {
      if (string[i] === string[i - 2]) {
        oneLetterTwiceWithOneBetweenThem = true;
      }
    }
  }

  // clean up the pairs object and just look at the ones that have more
  // than one entry
  for (const pair in pairs) {
    if (pairs[pair].length < 2) {
      delete pairs[pair];
    }
  }

  // the condition that this pair appears in the string at least twice
  // without overlapping will be apparent if we flatten the arrays
  // and if the amount of integers in a flattened array of indices
  // is double the amount of the amount of original arrays,
  // we are good
  for (const pair in pairs) {
    const arrayOfIndicesOfAPair = pairs[pair];
    const sizeOfAOIOAP = arrayOfIndicesOfAPair.length;
    let flattened = _.flatten(arrayOfIndicesOfAPair);
    flattened = _.uniq(flattened);
    console.log(flattened);
    const sizeFlattened = flattened.length;
    if (sizeOfAOIOAP === sizeFlattened / 2) {
      pairOfTwoNotOverlapping = true;
    }
  }

  return pairOfTwoNotOverlapping && oneLetterTwiceWithOneBetweenThem;
};

const solve2 = async () => {
  let strings = await readFile("./input.txt");
  strings = strings.split("\n").filter((s) => Boolean(s));
  let totalNiceStrings = 0;

  strings.forEach((string) => {
    if (checkIfStringIsNice2(string)) totalNiceStrings++;
  });

  console.log(`There is a total of ${totalNiceStrings} nice strings`);
};

solve2();
