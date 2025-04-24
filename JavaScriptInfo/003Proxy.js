// Create a function makeObservable(target) that “makes the object observable” by returning a proxy.

let handlers = Symbol("handlers");

function makeObservable(target) {
  target[handlers] = [];

  target.observe = function (handler) {
    this[handlers].push(handler);
  };

  return new Proxy(target, {
    set(target, prop, val, receiver) {
      let success = Reflect.set(...arguments);

      if (success) {
        target[handlers].forEach((handler) => handler(prop, val));
      }

      return success;
    },
  });
}

let user = {};
user = makeObservable(user);

user.observe((key, value) => {
  alert(`SET ${key}=${value}`);
});

user.name = "foo";
