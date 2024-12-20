#pragma once

#include <iostream>
using namespace std;

template <class T> class clsDynamicArray {
protected:
  int _Size = 0;
  T *_TempArray;

public:
  T *OriginalArray;

  clsDynamicArray(int Size = 0) {
    if (Size < 0)
      Size = 0;

    _Size = Size;

    OriginalArray = new T[_Size];
  }

  ~clsDynamicArray() { delete[] OriginalArray; }

  bool SetItem(int index, T Value) {
    if (index >= _Size || _Size < 0) {
      return false;
    }

    OriginalArray[index] = Value;
    return true;
  }

  int Size() { return _Size; }

  bool IsEmpty() { return (_Size == 0 ? true : false); }

  void PrintList() {

    for (int i = 0; i <= _Size - 1; i++) {
      cout << OriginalArray[i] << " ";
    }

    cout << "\n";
  }

  void Resize(int NewSize) {

    if (NewSize < 0) {
      NewSize = 0;
    };

    _TempArray = new T[NewSize];

    // limit the original size to the new size if it is less.
    if (NewSize < _Size)
      _Size = NewSize;

    // copy all data from original array until the size
    for (int i = 0; i < _Size; i++) {
      _TempArray[i] = OriginalArray[i];
    }

    _Size = NewSize;

    delete[] OriginalArray;
    OriginalArray = _TempArray;
  }

  T GetItem(int index) { return OriginalArray[index]; }

  void Reverse() {
    _TempArray = new T[_Size];

    for (short i = _Size - 1, j = 0; i >= 0; i--, j++) {
      _TempArray[j] = OriginalArray[i];
    }

    delete[] OriginalArray;
    OriginalArray = _TempArray;
  }

  void Clear() {
    _Size = 0;
    _TempArray = new T[0];

    delete[] OriginalArray;
    OriginalArray = _TempArray;
  }

  bool DeleteItemAt(int index) {
    if (index >= _Size || index < 0) {
      return false;
    }

    _Size--;
    _TempArray = new T[_Size];

    for (short i = 0; i < index; i++) {
      _TempArray[i] = OriginalArray[i];
    }

    for (short i = index + 1; i < _Size + 1; i++) {
      _TempArray[i - 1] = OriginalArray[i];
    }

    delete[] OriginalArray;
    OriginalArray = _TempArray;

    return true;
  }

  void DeleteFirstItem() { DeleteItemAt(0); }

  void DeleteLastItem() { DeleteItemAt(_Size - 1); }

  int Find(int value) {
    for (short i = 0; i < _Size; i++) {
      if (OriginalArray[i] == value) {
        return i;
      }
    }

    return -1;
  }

  bool DeleteItem(int value) {
    short index = Find(value);

    if (index == -1) {
      return false;
    }

    DeleteItemAt(index);
    return true;
  }

  bool InsertAt(int index, T value) {
    if (index < 0 || index > _Size) {
      return false;
    }

    _Size++;
    _TempArray = new T[_Size];

    for (short i = 0; i < index; i++) {
      _TempArray[i] = OriginalArray[i];
    }

    _TempArray[index] = value;

    for (short i = index; i < _Size - 1; i++) {
      _TempArray[i + 1] = OriginalArray[i];
    }

    delete[] OriginalArray;
    OriginalArray = _TempArray;

    return true;
  }

  void InsertAtBeginnig(T value) { InsertAt(0, value); }

  bool InsertBefore(int index, T value) {
    if (index < 1)
      return InsertAt(0, value);
    else
      return InsertAt(index - 1, value);
  }

  bool InsertAfter(int index, T value) {
    if (index >= _Size)
      return InsertAt(_Size - 1, value);
    else
      return InsertAt(index + 1, value);
  }

  void InsertAtEnd(T value) { InsertAt(_Size, value); }
};
