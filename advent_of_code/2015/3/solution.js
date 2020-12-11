const readFile = require("../../utils/readFile");

/*
  Since the point of this exercise is to find out about the amount of houses
  that will receive _at least one_ presnt, the only thing I need to know
  is to collect information about which places on the grid have been
  visited. To store this data, I will employ an object with integers as keys
  representing the x coord and values will be arrays of the y coords visited

  for example, with input `^>v<` he delivers presents to 4 houses in a square
  , including twice to the house at his starting/end location

  that means, that if i assume that he starts at location [0,0], his path
  is this:

  [0,0] start
  [0,1] ^
  [1,1] >
  [0,1] v
  [0,0] <

  and the resulting object would be this:

  visited = {
    0: [0, 1],
    1: [0, 1]
  }

  the answer to the questions of how many houses receive at least one present
  is a sum of all lengths of the object's values.

  --- Addendum for pt 2

  since there is now a new santa, robo-santa, although the whole mechanic
  does not change, there needs to be a change to how i store the position, and
  who gets to move on what turn.
*/

const positions = [
  [0, 0],
  [0, 0],
];
const visitedHouses = {};

// used not to unnecessarily iterate over all the arrays in the
// visitedHouses object.
let totalHousesVisited = 0;

const moveUp = (position) => position[0]++;
const moveDown = (position) => position[0]--;
const moveRight = (position) => position[1]++;
const moveLeft = (position) => position[1]--;

const move = (direction, position) => {
  switch (direction) {
    case "^":
      moveUp(position);
      break;
    case "v":
      moveDown(position);
      break;
    case ">":
      moveRight(position);
      break;
    case "<":
      moveLeft(position);
      break;
    default:
      throw new Error("Invalid direction");
  }
};

const logMove = (position) => {
  const x = position[0];
  const y = position[1];

  let xArray = visitedHouses[x];
  if (xArray === undefined) {
    visitedHouses[x] = [];
    xArray = visitedHouses[x];
  }

  if (!xArray.includes(y)) {
    xArray.push(position[1]);
    totalHousesVisited++;
  }
};

const makeMoves = (instructions) => {
  logMove(positions[0]);

  let whoMoves = 0; // 0 for santa, 1 for robo santa
  for (const instruction of instructions) {
    move(instruction, positions[whoMoves]);
    logMove(positions[whoMoves]);
    if (whoMoves === 0) {
      whoMoves = 1;
    } else {
      whoMoves = 0;
    }
  }
};

const solve = async () => {
  const instructions = await readFile("./input.txt");
  makeMoves(instructions);
  console.log(`Santa has visited ${totalHousesVisited} houses at least once.`);
};

solve();
