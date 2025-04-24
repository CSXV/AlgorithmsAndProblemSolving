// Write the function sumSalaries(salaries) that returns the sum of all salaries using Object.values and the for..of loop.

let salaries = {
  foo: 100,
  bar: 300,
  baz: 250,
};

function sumSalaries(salaries) {
  let sum = 0;

  for (const salary of Object.values(salaries)) {
    sum += salary;
  }

  return sum;
}

alert(sumSalaries(salaries));
