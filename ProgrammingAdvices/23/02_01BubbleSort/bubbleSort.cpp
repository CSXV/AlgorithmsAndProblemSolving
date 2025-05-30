// bubble sort

#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

void bubbleSort(int (&arr)[7], int length) {
  int swap = 0;

  for (short i = length; i > 0; i--) {
    for (short j = 0; j < i; j++) {
      if (arr[j + 1] < arr[j]) {
        swap = arr[j];

        arr[j] = arr[j + 1];
        arr[j + 1] = swap;
      }
    }
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

  bubbleSort(arr, length);
  PrintArray(arr, length, "bubble sort an array:\n");

  signature();
  return 0;
}
