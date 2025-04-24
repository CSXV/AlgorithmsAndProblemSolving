// Write a function printNumbers(from, to) that outputs a number every second, starting from from and ending with to.

function My_printNumbers(from, to) {
  for (let i = from; i <= to; i++) {
    setTimeout(() => {
      alert(i);
    }, 1000);
  }
}

function printNumbers(from, to) {
  let current = from;

  let TimerID = setInterval(function () {
    alert(current);

    if (current == to) {
      clearInterval(TimerID);
    }

    current++;
  }, 1000);
}

function printNumbers2(from, to) {
  let current = from;

  setTimeout(function go() {
    alert(current);

    if (current < to) {
      setTimeout(go, 1000);
    }

    current++;
  }, 1000);
}

// My_printNumbers(1, 10);
// printNumbers(1, 10);
printNumbers2(1, 10);
