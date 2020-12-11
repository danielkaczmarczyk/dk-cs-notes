const readFile = require('../../utils/readFile');

/*
 * It would be wise not to calculate the wires that we do not need for
 * that computation...
 * Since every wire can only receive signal from one destination, it seems
 * that it would be sufficient to ask for a wire name, and go back from
 * there, finding every value. Building a recursive structure that keeps
 * asking for a value of a wire, until it resolves to one, and to ensure
 * a sane execution time, for a good measure, memoize the values of wires
 * in some key-value storage.
 *
 *
 * Approach number two would be to actually write a parser for that input
 * that converts the input into a self-evaluating code. 
 */

const wires = {};

const parseInstruction = (instructionString) => {
  // replace the words with actual bitwise operations
  const operations = {
    'AND': '&',
    'OR': '|',
    'LSHIFT': '<<',
    'RSHIFT': '>>',
    'NOT': '~'
  }

  for (let operation in operations) {
    if (instructionString.includes(operation)) {
      instructionString = instructionString.replace(operation, operations[operation]);
    }
  }

  return instructionString.split(' -> ').reverse().join(' = ');
}

const findValue = (wireName) => {
  if (wires.wireName === undefined) {
    // find an instruction that ends with wireName as the last thing
    // parse the inputString into an eval-able js code
    // if any of the vars are `undefined`, call findValue on them
    // look at the instruction on how to calculate
    // assess if we have all the vars 
    // if not, calculate them
    // once they're calculated, perform instruction and assign
  } else {
    return wires.wireName;
  }
};

const solve = async () => {
  let input = await readFile('./input.txt')
  input = input.split(/\r\n|\r|\n/).filter(i => Boolean(i)).map(i => parseInstruction(i));
  console.log(input);
};

exports.findValue = findValue;
exports.parseInstruction = parseInstruction;
