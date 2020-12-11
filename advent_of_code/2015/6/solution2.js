const readFile = require('../../utils/readFile');
/*
 * This is a modified version of the file from solution.js, adapted to the second part of the
 * challenge. I haven't written tests for it, and changed many semantics. The adjustment is small,
 * and since I've already got a way of iterating over the grid, all there is to be done is to provide
 * different behaviour for the `act` function, and changing how `countOn` works. For the sake of
 * laziness, I am not renaming the `countOn` function, since it's not only counting the amount of
 * bulbs that are on, but totals the brightness. 
/*

/*
 * creates a SQUARE grid
 * @param {Number} size of the grid
 * @return {Array} array of arrays representing the grid
 */
const createGrid = (n) => {
  const xArray = [];
  for (let i = 0; i < n; i++) {
    xArray.push(new Array(n).fill(0));
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

  let lightStatusInt = parseInt(lightStatus);
  if (instruction === "turn on") return ++lightStatusInt;
  if (instruction === "turn off") {
    if (lightStatus === 0) return 0;
    return --lightStatus;
  }
  if (instruction === "toggle") {
    return lightStatus + 2;
  }
};

const countOn = (grid) => {
  let on = 0;
  for (let i = 0; i < grid[0].length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      on += grid[i][j];
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
