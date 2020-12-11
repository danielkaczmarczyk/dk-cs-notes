/*
 * `(` - open bracket symbol, takes santa one floor up.
 * `)` - closed bracket symbol, takes him one floor down.
 *
 * given a file containing those parens as input, answer: which floor
 * does santa get to?
 *
 */

const fs = require("fs");

const solveSantasProblem = () => {
  return new Promise((resolve, reject) => {
    const processFloorInput = (err, floorText) => {
      if (err) {
        reject(err);
      }

      let floor = 0;
      let visitedBasement = false;
      let indexOfBasementVisitCharacter;

      for (let i = 0; i < floorText.length; i++) {
        const char = floorText[i];
        console.log(i, char, floor);
        if (!visitedBasement) {
          if (floor === -1) {
            visitedBasement = true;
            indexOfBasementVisitCharacter = i;
          }
        }

        switch (char) {
          case "(":
            floor++;
            break;
          case ")":
            floor--;
            break;
          default:
            break;
        }
      }
      resolve({ floor, indexOfBasementVisitCharacter });
    };
    fs.readFile("./input.txt", "utf8", processFloorInput);
  });
};

const solve = async () => {
  const { floor, indexOfBasementVisitCharacter } = await solveSantasProblem();
  console.log(
    `Santa will end up on floor ${floor}. First time in basement on character ${indexOfBasementVisitCharacter}`
  );
};

solve();
