const readFile = require('../../utils/readFile');

const solve = async () => {
  let input = await readFile('./input.txt');

  const re = /(\d+)\s+(\d+)\s+(\d+)\n/g
  input = [...input.matchAll(re)].map(match => {
    return [match[1], match[2], match[3]].map(n => parseInt(n, 10));
  });

  const isTriangleValid = (x, y, z) => {
    const isValid = x + y > z && x + z > y && y + z > x;
    if (isValid) { validTriangles++ };
  }

  const areTrianglesValid = () => {
    triangles.forEach(triangle => isTriangleValid(...triangle));
  };

  let triangles = [[], [], []];
  let validTriangles = 0;

  for (let line of input) {
    if (triangles[0].length === 3) {
      areTrianglesValid();
      triangles = [[], [], []];
    }
    for (let i = 0; i < 3; i++ ) {
      triangles[i].push(line[i]);
    }
  }

  areTrianglesValid();
  console.log(validTriangles);
}

solve();

