const readFile = require('../../utils/readFile');
/*
 * NOTE: In a sort of a courtesy, the author of the input has provided the input that always
 * follows the pattern of the coordinates on the left being smaller than those on the right.
 * What that means in practice, is that the rectangles of lights to operate on, are always
 * delimited from left bottom corner to the right top corner. This simplifies writing the procedure
 * for dealing with applying the operation to certain squares. And that's cool.
 */

/*
 * creates a SQUARE grid
 * @param {Number} size of the grid
 * @return {Array} array of arrays representing the grid
 */
const createGrid = (n) => {
  const xArray = [];
  for (let i = 0; i < n; i++) {
    xArray.push(new Array(n).fill("0"));
  }
  return xArray;
};

/**
 * @inputString {String} input to be parsed
 * @returns {Object} object describing the instructions
 */
const parseInstructions = (inputString) => {
  const re = /^([a-z]+\s?[a-z]+)\s(\d+),(\d+)\sthrough\s(\d+),(\d+)/g;
  const match = re.exec(inputString);
  const instructions = {};
  instructions.instruction = match[1];
  instructions.start = { x: parseInt(match[2]), y: parseInt(match[3]) };
  instructions.end = { x: parseInt(match[4]), y: parseInt(match[5]) };
  return instructions;
};

/*
 * @grid {Array} the grid of lights
 * @instructionsObject {Object} object describing the instructions
 * @returns {Array} a reference to the grid array - not a copy
 */
const applyInstructions = (grid, instructionsObject) => {
  const { start, end, instruction } = instructionsObject;
  for (let i = start.x; i <= end.x; i++) {
    for (let j = start.y; j <= end.y; j++) {
      grid[i][j] = act(grid[i][j], instruction);
    }
  }
};

/**
 * Acts out the instruction.
 * @lightStatus {String}
 * @instruction {String}
 * @returns {String} lightStatus after instruction
 */
const act = (lightStatus, instruction) => {
  if (instruction === undefined) throw new Error("instruction is not defined");
  if (lightStatus === undefined) throw new Error("lightStatus is not defined");
  if (instruction === "turn on") return "1";
  if (instruction === "turn off") return "0";
  if (instruction === "toggle") {
    return lightStatus === "0" ? "1" : "0";
  }
};

const countOn = (grid) => {
  let on = 0;
  for (let i = 0; i < grid[0].length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === '1') on++; 
    }
  }
  return on;
};

const solve = async () => {
  const input = await readFile("./input.txt");
  const inputSplit = input.split(/\r\n|\r|\n/).filter(i => Boolean(i)).map(ins => parseInstructions(ins));
  const grid = createGrid(1000);
  
  inputSplit.forEach(instruction => {
    applyInstructions(grid, instruction);
  });

  console.log(countOn(grid));
};

module.exports = {
  act,
  applyInstructions,
  countOn,
  createGrid,
  parseInstructions,
};
