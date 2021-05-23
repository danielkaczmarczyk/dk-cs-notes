const fs = require("fs");

/*
  > = increases memory pointer, or moves the pointer to the right 1 block.
  < = decreases memory pointer, or moves the pointer to the left 1 block.
  + = increases value stored at the block pointed to by the memory pointer
  - = decreases value stored at the block pointed to by the memory pointer
  [ = like c while(cur_block_value != 0) loop.
  ] = if block currently pointed to's value is not zero, jump back to [
  , = like c getchar(). input 1 character.
  . = like c putchar(). print 1 character to the console
 */
const TAPE_SIZE = 80;
const tape = [];
for (let i = 0; i < TAPE_SIZE; i++) {
  tape.push(0);
}
let index = 0;
let loop = false;

const tokens = {
  ">": () => {
    index++;
  },
  "<": () => index--,
  "+": () => tape[index]++,
  "-": () => tape[index]--,
  "[": () => {
    let char = tape[index];
    if (char === 0) {
      while(char != '[')
    }
  },
  "]": () => index++,
  ",": () => index++,
  ".": () => index++,
};

const execute = (filename) => {
  console.log(`Reading file ${filename}`);
  const data = fs.readFileSync(filename, "utf8");
  console.log(`data: ${data}`);
  for (char of data) {
    let contains = Object.keys(tokens).includes(char);
    if (contains) {
      tokens[char]();
    }
  }
};

const filename = process.argv[2];
execute(filename);
console.log(tape);
console.log(index);
