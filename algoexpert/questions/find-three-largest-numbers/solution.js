function findThreeLargestNumbers(array) {
  const threeLargest = [null, null, null];
  for (const num of array) {
    update(threeLargest, num);
  }
  return threeLargest;
}

function update(threeLargest, num) {
  if (threeLargest[2] == null | num > threeLargest[2]) {
    shiftAndUpdate(threeLargest, num, 2);
  } else if (threeLargest[1] == null | num > threeLargest[1]) {
    shiftAndUpdate(threeLargest, num, 1);
  } else if (threeLargest[0] == null | num > threeLargest[0]) {
    shiftAndUpdate(threeLargest, num, 0);
  }
}

function shiftAndUpdate(threeLargest, num, idx) {
  for (let i = 0; i <= idx; i++) {
    if (i === idx) {
      threeLargest[i] = num;
    } else {
      threeLargest[i] = threeLargest[i + 1];
    }
  }
}

console.log(findThreeLargestNumbers([10, 5, 9, 10, 12]));
