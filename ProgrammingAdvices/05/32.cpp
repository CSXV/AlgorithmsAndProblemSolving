#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then print arrays of it, then print the array in reversed
// order.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int ReadPNumber(string message) {
  int N;
  do {
    cout << message;
    cin >> N;
  } while (N <= 0);
  return N;
}

void Swap(int &A, int &B) {
  int Temp;
  Temp = A;
  A = B;
  B = Temp;
}

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

void FillArray(int arr[100], int &arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arr[i] = RandomNumber(1, 100);
  }
}

// void ReversedArray(int arr[100], int arrLength) {
//   for (int i = 1; i < arrLength; i++) {
//     int b = 0;
//     for (int j = i; j < arrLength; j++, b++) {
//       Swap(arr[b], arr[b + 1]);
//     }
//   }
// }

void ReversedArray(int arr[100], int arr2[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arr2[i] = arr[arrLength - 1 - i];
  }
}

void PrintArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  srand((unsigned)time(NULL));
  int arr[100], arr2[100];
  int arrLength = ReadPNumber("Please enter a possitive number: ");

  FillArray(arr, arrLength);

  cout << "\nArray 01 elements: ";
  PrintArray(arr, arrLength);

  ReversedArray(arr, arr2, arrLength);

  cout << "\nArray 02 elements, after copying array 01 in reversed order: ";
  PrintArray(arr2, arrLength);

  signature();
  return 0;
}
