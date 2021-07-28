function calc(arr) {
	arr = arr.sort((a, b) => a - b);

  let sum = 0;
  let toAdd = arr[0];
  
  for (let i = 1; i < arr.length; i++) {
    const number = arr[i];
    sum += toAdd;
    toAdd += number;
  }

  return sum;
}


arrs = [
  [1,4,5],
  [5,4,1],
  [1,5,4],
]

arrs = arrs.map(arr => calc(arr));
console.log(arrs); // \m/
