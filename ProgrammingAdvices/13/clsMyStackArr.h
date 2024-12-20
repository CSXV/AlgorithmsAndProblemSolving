#pragma once
#include "clsMyQueueArr.h"

template <class T> class clsMyStackArr : public clsQueueArr<T> {
public:
  void push(T value) { clsQueueArr<T>::_Arr.InsertAtBeginnig(value); }

  T Top() { return clsQueueArr<T>::front(); }

  T Bottom() { return clsQueueArr<T>::back(); }
};
