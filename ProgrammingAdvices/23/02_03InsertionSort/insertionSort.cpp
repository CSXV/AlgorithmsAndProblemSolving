// insertion sort

#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

// my solution :) (o_0)
void insertionSort(int (&arr)[7], int length) {
  int key = 0, pos = 0;

  for (short i = 0; i < length; i++) {
    key = arr[i];

    for (short j = i; j > 0; j--) {
      if (key < arr[j - 1]) {
        arr[j] = arr[j - 1];
      } else {
        pos = j;
        break;
      }
    }

    arr[pos] = key;
  }

  int swap = arr[1];
  arr[1] = arr[0];
  arr[0] = swap;
}

void _insertionSort(int (&arr)[7], int length) {
  int key = 0, j = 0;

  for (short i = 0; i < length; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j -= 1;
    }

    arr[j + 1] = key;
  }
}

void PrintArray(int arr[], int length, string message) {
  cout << message;

  for (short i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int length = size(arr);

  PrintArray(arr, length, "original array:\n");

  insertionSort(arr, length);
  PrintArray(arr, length, "selection sort an array:\n");

  signature();
  return 0;
}
