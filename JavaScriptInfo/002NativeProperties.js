// Add to the prototype of all functions the method defer(ms), that returns a wrapper, delaying the call by ms milliseconds.

function f(a, b) {
  alert(a + b);
}

Function.prototype.defer = function (ms) {
  let f = this;
  return function (...args) {
    setTimeout(() => f.apply(this, args), ms);
  };
};

f.defer(2000)(1, 2);
