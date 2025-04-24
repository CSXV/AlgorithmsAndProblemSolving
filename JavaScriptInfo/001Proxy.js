// Usually, an attempt to read a non-existent property returns undefined.

// Create a proxy that throws an error for an attempt to read of a non-existent property instead.

// That can help to detect programming mistakes early.

// Write a function wrap(target) that takes an object target and return a proxy that adds this functionality aspect.

let user = {
  name: "foo",
};

function wrap(target) {
  return new Proxy(target, {
    get(target, prop, receiver) {
      if (prop in target) {
        return Reflect.get(target, prop, receiver);
      } else {
        return new ReferenceError("Property doesnt exist");
      }
    },
  });
}

user = wrap(user);

alert(user.name);
alert(user.age);
