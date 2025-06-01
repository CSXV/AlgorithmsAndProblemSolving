// Write a function fib(n) that returns the n-th Fibonacci number.

function fib(n) {
  let a = 1,
    b = 1;

  for (let i = 3; i <= n; i++) {
    let c = a + b;
    a = b;
    b = c;
  }

  return b;
}

alert(fib(3));
alert(fib(7));
alert(fib(77));
