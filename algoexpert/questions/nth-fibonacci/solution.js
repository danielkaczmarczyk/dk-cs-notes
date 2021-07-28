function getNthFibRecursive(n) {
  if (n == 1) return 0;
  if (n < 4) return 1;
  return getNthFibRecursive(n - 1) + getNthFibRecursive(n - 2);
}

function getNthFibIterative(n) {
  console.log(n);
  console.log('uh');
  if (n == 1) return 0;
  if (n < 4) return 1;

  let first = 1;
  let second = 2;
  let i = 4;

  while (i <= n) {
    let swap = first + second;
    first = second;
    second = swap;
    i++;
  }


  return second;
}


const fn = getNthFibIterative;
const result = [1,2,3,4,5,6,7,8].map(n => fn(n));
const answers = [0, 1, 1, 2, 3, 5, 8, 13];

for (let i = 0; i < result.length; i++) {
  console.log(result[i], answers[i]);
}
