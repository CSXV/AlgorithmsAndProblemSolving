let user = {
  name: "foo",
  age: 20,
  _password: "***",
};

user = new Proxy(user, {
  get(target, prop) {
    if (prop.startsWith("_")) {
      throw new Error("Access is deinied");
    }

    let value = target[prop];
    return typeof value === "function" ? value.bind(target) : value;
  },

  set(target, prop, val) {
    if (prop.startsWith("_")) {
      throw new Error("Access is deinied");
    } else {
      target[prop] = val;
      return true;
    }
  },

  deleteProperty(target, prop) {
    if (prop.startsWith("_")) {
      throw new Error("Access is deinied");
    } else {
      delete target[prop];
      return true;
    }
  },

  ownKeys(target) {
    return Object.keys(target).filter((key) => !key.startsWith("_"));
  },
});

// no read
try {
  alert(user._password);
} catch (e) {
  alert(e.message);
}

// no write
try {
  user._password = "foo";
} catch (e) {
  alert(e.message);
}

// no delete
try {
  delete user._password;
} catch (e) {
  alert(e.message);
}
