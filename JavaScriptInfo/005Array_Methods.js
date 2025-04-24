// We have an array of strings arr. We’d like to have a sorted copy of it, but keep arr unmodified.

function copySorted(arr) {
  return arr.slice().sort();
}

let arr = ["HTML", "JavaScript", "CSS"];

let sorted = copySorted(arr);

alert(arr);
alert(sorted);
