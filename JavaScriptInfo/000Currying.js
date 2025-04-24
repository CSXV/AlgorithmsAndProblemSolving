// 001
function curry(f) {
  return function curried(...args) {
    if (args.length >= f.length) {
      return f.apply(this, args);
    } else {
      return function (...args2) {
        return curried.apply(this, args.concat(args2));
      };
    }
  };
}

// 002
function log(date, importance, message) {
  alert(
    `[${date.getHours()}:${date.getMinutes()}] [${importance}] [${message}]`,
  );
}

// 003
log = curry(log);

// 004
let logNow = log(new Date());
let debugNow = logNow("DEBUG");

// 005
debugNow("message here");

// 006
