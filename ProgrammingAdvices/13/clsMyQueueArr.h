#pragma once
#include "clsDynamicArray.h"
#include <iostream>
using namespace std;

template <class T> class clsQueueArr {
protected:
  clsDynamicArray<T> _Arr;

public:
  void push(T value) { _Arr.InsertAtEnd(value); }

  void Print() { _Arr.PrintList(); }

  void pop() { _Arr.DeleteFirstItem(); }

  int Size() { return _Arr.Size(); }

  void Clear() { _Arr.Clear(); }

  T front() { return _Arr.GetItem(0); }

  T back() { return _Arr.GetItem(Size() - 1); }

  void reverse() { _Arr.Reverse(); }

  T GetItem(int index) { return _Arr.GetItem(index); }

  void Reverse() { _Arr.Reverse(); }

  void UpdateArr(int index, T value) { _Arr.SetItem(index, value); }

  void InsertAfter(int index, T value) { _Arr.InsertAfter(index, value); }

  void InsertAtFront(T value) { _Arr.InsertAtBeginnig(value); }

  void InsertAtBack(T value) { _Arr.InsertAtEnd(value); }
};
