let user = {
  foo: 100,
  bar: 300,
  baz: 250,
};

let { name, years: age, isAdmin = false } = user;

alert(name);
alert(age);
alert(isAdmin);
