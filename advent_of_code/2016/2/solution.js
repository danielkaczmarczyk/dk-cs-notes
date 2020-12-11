const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');
  // let input = await readFile('./testInput.txt');
  
  const re = /\w+/g
  instructions = [...input.matchAll(re)]
    .map(match => match[0]);

  let position = [1, 1];
  const keypad = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
  ];
  let code = [];

  const getNumber = () => {
    console.log(`attempting to get a number from the keypad`);
    console.log(`the current position is: ${position}`);
    const number = keypad[position[0]][position[1]];
    console.log(`retrieved the ${number} from the keypad`);
    return number;
  }

  /*
   * Invalid positons on keypad
   * for [x, y] are when x or y is < 0 || > 3
   * therefore, if the resulting move would cause a change
   * of coordinate as such, it should not be changed
   * otherwise, if the coordinate is valid, change it
   */

  const isPositionValid = (position) => {
    [x, y] = position;
    let valid = true;

    if (x < 0 || x > 2) valid = false;
    if (y < 0 || y > 2) valid = false;

    return valid;
  }

  const attemptMove = (letter) => {
    console.log(`I am attempting a move on the keypad`);
    console.log(`the current position is :${position}`);
    const newPosition = [...position];
    if (letter === 'U') {
      newPosition[0]--;
    } else if (letter === 'D') {
      newPosition[0]++;
    } else if (letter === 'R') {
      newPosition[1]++;
    } else if (letter === 'L') {
      newPosition[1]--;
    }

    if (isPositionValid(newPosition)) {
      console.log(`the move to ${newPosition} seems to be valid.`);
      console.log(`overwriting the value of position to ${newPosition}`);
      position = newPosition;
    } else {
      console.log(`the move to position ${newPosition} is invalid. position not changed`);
    }
  }

  console.log(instructions.length);
  
  for (let line of instructions) {
    console.log(`i am at a line: ${line}`);
    for (let letter of line) {
      console.log(`I am at ${getNumber()} on the keypad`);
      console.log(`i am at a letter: ${letter}`);
      attemptMove(letter);
      console.log(`---------`);
    }
    code.push(getNumber());
  }

  console.log(code.join(''));
  // test input result should be 1 9 8 5
}

solve();

