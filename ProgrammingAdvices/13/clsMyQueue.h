#pragma once
#include "clsDblLinkedList.h"
#include <iostream>
using namespace std;

template <class T> class clsMyQueue {
protected:
  clsDblLinkedList<T> _MyList;

public:
  void push(T Item) { _MyList.InsertAtEnd(Item); }

  void pop() { _MyList.DeleteFirstNode(); }

  void Print() { _MyList.PrintList(); }

  int Size() { return _MyList.Size(); }

  bool IsEmpty() { return _MyList.IsEmpty(); }

  int front() { return _MyList.GetItem(0); }

  int back() { return _MyList.GetItem(Size() - 1); }

  T GetItem(int Index) { return _MyList.GetItem(Index); }

  void Reverse() { _MyList.Reverse(); }

  void UpdateItem(int Index, T NewValue) {
    _MyList.UpdateItem(Index, NewValue);
  }

  void InsertAfter(int Index, T Value) { _MyList.InsertAfter(Index, Value); }

  void InsertAtFront(T value) { _MyList.InsertAtBeginning(value); }

  void InsertAtBack(T value) { _MyList.InsertAtEnd(value); }

  void Clear() { _MyList.Clear(); }
};
