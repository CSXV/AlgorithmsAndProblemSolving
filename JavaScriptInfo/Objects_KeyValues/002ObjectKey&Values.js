// Write a function count(obj) that returns the number of properties in the object:

let user = {
  name: "foo",
  age: 20,
};

function count(obj) {
  return Object.keys(obj).length;
}

alert(count(user));
