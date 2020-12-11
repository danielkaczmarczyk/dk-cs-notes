const md5 = require("md5");
const secretKey = "ckczppom";

const solve = (initString) => {
  let searching = true;
  let number = 1;
  let i = 0;
  while (searching) {
    const hash = md5(`${secretKey}${number}`);
    console.log(`i: ${i} hash: ${hash}`);

    if (hash.substr(0, initString.length) === initString) {
      searching = false;
      console.log(`HASH FOUND`);
      console.log(`The value of the number that returns it is ${number}.`);
    }
    number++;
    i++;
  }
};

// solve("00000");
solve("000000");
