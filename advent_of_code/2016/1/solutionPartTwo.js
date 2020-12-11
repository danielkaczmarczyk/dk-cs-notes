const readFile = require("../../utils/readFile");


const solve = async () => {
  console.log(new Date(Date.now()));
  let input = await readFile("input.txt");
  let moves = [];
  let parsing = true;
  const position = [0, 0];
  let currentDirection = "N";
  const locationsVisited = [];

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

  const makeLocationString = () => `${position[0]}${position[1]}`;

  const getDistance = () => Math.abs(position[0]) + Math.abs(position[1]);

  const makeMove = (distance) => {
    let positionToChange = 0;
    let direction = '+';

    if (currentDirection === 'N') positionToChange = 1;
    if (currentDirection === 'S') {
      positionToChange = 1;
      direction = '-';
    }
    if (currentDirection === 'W') direction = '-';

    for (let i = 0; i < distance; i++) {
      eval(`position[positionToChange] ${direction}= 1`)
      if (locationsVisited.includes(makeLocationString())) {
        console.log(`I have been here. ${getDistance()}`);
        process.exit(0);
      }
      locationsVisited.push(makeLocationString());
    }

  }

  locationsVisited.push(makeLocationString());
  for (let i = 0; i < moves.length; i++) {
    const move = moves[i];
    currentDirection = getNewDirection(move.rotation);
    makeMove(move.distance);
  }
};

solve();
