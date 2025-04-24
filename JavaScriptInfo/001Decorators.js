function cachingDecorator(func, hash) {
  let cache = new Map();

  return function () {
    let key = hash(arguments);

    if (cache.has(key)) return cache.get(key);

    // CALL FORWARDING
    let results = func.apply(this, arguments);

    cache.set(key, results);

    return results;
  };
}

function hash(args) {
  // METHOD BORROWING
  return [].join.call(args);
}

let worker = {
  slow(min, max) {
    alert(`calling ${min} + ${max}:`);
    return min + max;
  },
};

worker.slow = cachingDecorator(worker.slow, hash);

alert(worker.slow(3, 5));
// THIS WILL BE CACHED
alert(worker.slow(3, 5));
