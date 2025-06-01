// In some programming languages, we can access array elements using negative indexes, counted from the end.

let array = [1, 2, 3];

array = new Proxy(array, {
  get(target, prop, receiver) {
    if (prop < 0) {
      prop = +prop + target.length;
    }

    return Reflect.get(target, prop, receiver);
  },
});

alert(array[-1]);
alert(array[-2]);
