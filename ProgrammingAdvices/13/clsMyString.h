#pragma once
#include "clsMySTackArr.h"
#include <iostream>
using namespace std;

class clsMyString {
protected:
  clsMyStackArr<string> _Stack, _UnDoHistory;

public:
  string value;

  clsMyString() { _Stack.push(""); }

  void Value(string Value) {
    _Stack.push(Value);

    value = Value;
  }

  string Value() { return _Stack.Top(); }

  void Undo() {
    if (_Stack.Size() == 0) {
      return;
    }

    _UnDoHistory.push(_Stack.Top());
    _Stack.pop();

    value = _Stack.Top();
  }

  void Redo() {
    if (_Stack.Size() == 0) {
      return;
    }

    _Stack.push(_UnDoHistory.Top());
    _UnDoHistory.pop();

    value = _Stack.Top();
  }
};
