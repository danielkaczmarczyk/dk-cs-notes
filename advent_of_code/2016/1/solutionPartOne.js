const readFile = require("../../utils/readFile");


const solve = async () => {
  console.log(new Date(Date.now()));
  let input = await readFile("input.txt");
  let moves = [];
  let parsing = true;
  const position = [0, 0];
  let currentDirection = "N";

  const moveRe = /([L|R])(\d+)/g;

  while (parsing) {
    const moveData = moveRe.exec(input);
    if (moveData) {
      const moveObj = {
        rotation: moveData[1],
        distance: parseInt(moveData[2], 10),
      };
      moves.push(moveObj);
    } else {
      parsing = false;
    }
  }

  // FOR TESTING - remove pre-solution
  //  moves = moves.slice(0, 5);

  const getNewDirection = (rotationDirection) => {
    const directions = ["N", "E", "S", "W"];
    let currentDirectionIndex = directions.indexOf(currentDirection);

    if (rotationDirection === "R") currentDirectionIndex++;
    if (currentDirectionIndex === 4) currentDirectionIndex = 0;
    if (rotationDirection === "L") currentDirectionIndex--;
    if (currentDirectionIndex === -1) currentDirectionIndex = 3;

    const newDirection = directions[currentDirectionIndex];
    return newDirection;
  };

  const makeMove = (distance) => {
    if (currentDirection === 'N') position[1] += distance;
    if (currentDirection === 'S') position[1] -= distance;
    if (currentDirection === 'E') position[0] += distance;
    if (currentDirection === 'W') position[0] -= distance;
  }


  moves.forEach((move) => {
    currentDirection = getNewDirection(move.rotation);
    makeMove(move.distance);
    console.log(move, currentDirection, position);
  });

  console.log(position);
  console.log(`the distance is ${Math.abs(position[0]) + Math.abs(position[1])}`);
};

solve();
