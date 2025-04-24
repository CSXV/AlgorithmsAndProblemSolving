class MyError extends Error {
  constructor(message) {
    super(message);
    this.name = this.constructor.name;
  }
}

class validationError extends MyError {}

class PropertyRequiredError extends validationError {
  constructor(property) {
    super("No property: " + property);
    this.property = property;
  }
}

function ReadUser(json) {
  let user = JSON.parse(json);

  if (!user.age) {
    throw new PropertyRequiredError("age");
  }

  if (!user.name) {
    throw new PropertyRequiredError("name");
  }

  return user;
}

try {
  ReadUser(`{"age": 25}`);
  // ReadUser(`{"name": "foo"}`);
} catch (error) {
  if (error instanceof validationError)
    alert(`invalid data: ${error.message}\n\n${error.name}\n\n${error.stack}`);
  if (error instanceof SyntaxError)
    alert(
      `JSON syntax error: ${error.message}\n\n${error.name}\n\n${error.stack}`,
    );
}
