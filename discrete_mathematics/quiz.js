const integer = 27182;

const sqrt = Math.round(Math.sqrt(integer) * 100);

console.log(sqrt);

const powd = Math.pow(sqrt, 2);

console.log(powd);
console.log(integer);

// 

for (let i = 0; i < 100; i++) {
  if (
    i % 3 === 2 
    &&
    i % 4 === 3 
    &&
    i % 5 === 4 
  ) {
    console.log(i);
  }
}


