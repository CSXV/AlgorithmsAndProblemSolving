// Write a function sumTo(n) that calculates the sum of numbers 1 + 2 + ... + n.

function sumTo(n) {
  if (n == 1) {
    return n;
  } else {
    sum = 0;
    return n + sumTo(n - 1);
  }
}

function sumTo2(n) {
  let sum = 0;

  for (let i = 1; i <= n; i++) {
    sum += i;
  }

  return sum;
}

function sumTo3(n) {
  return (n * (n + 1)) / 2;
}

alert(sumTo(2));
alert(sumTo2(4));
alert(sumTo3(100));
