// Add to the prototype of all functions the method defer(ms), that runs the function after ms milliseconds.

function f() {
  alert("Hello!");
}

Function.prototype.defer = function (ms) {
  setTimeout(this, ms);
};

f.defer(2000);
