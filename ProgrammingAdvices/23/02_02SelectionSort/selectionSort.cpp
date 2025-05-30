// selection sort

#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

void selectionSort(int (&arr)[7], int length) {
  int minIndex = 0, swap = 0;

  for (short i = 0; i < length; i++) {
    minIndex = i;

    for (short j = i; j < length; j++) {
      if (arr[j] <= arr[minIndex])
        minIndex = j;
    }

    swap = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = swap;
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

  selectionSort(arr, length);
  PrintArray(arr, length, "selection sort an array:\n");

  signature();
  return 0;
}
