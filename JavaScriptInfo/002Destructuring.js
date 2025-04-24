let salaries = {
  foo: 100,
  bar: 300,
  baz: 250,
};

function topSalary(salaries) {
  let maxSalary = 0;
  let maxName = null;

  for (const [key, value] of Object.entries(salaries)) {
    if (value >= maxSalary) {
      maxSalary = value;
      maxName = key;
    }
  }

  return maxName;
}

alert(topSalary(salaries));
