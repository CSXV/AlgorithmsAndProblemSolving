#include <cstdlib>
#include <iostream>
using namespace std;
// Hard code an array with (10 10 10 50 50 70 70 70 70 90) elements, then print
// distinct numbers to another array.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

// int RandomNumber(int from, int to) {
//   int randNum = rand() % (to - from + 1) + from;
//   return randNum;
// }

void FillArray(int arr[100], int &arrLength) {
  arrLength = 10;
  arr[0] = 10;
  arr[1] = 10;
  arr[2] = 10;
  arr[3] = 50;
  arr[4] = 50;
  arr[5] = 70;
  arr[6] = 70;
  arr[7] = 70;
  arr[8] = 70;
  arr[9] = 90;
}

void AddArrayElement(int number, int arr[100], int &arrLength) {
  arrLength++;
  arr[arrLength - 1] = number;
}

short findnumberinposition(int number, int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    if (arr[i] == number)
      return i;
  }
  return -1;
}

bool isnumberinarray(int number, int arr[100], int arrLength) {
  return findnumberinposition(number, arr, arrLength) != -1;
}

void CopyArray(int arr[100], int arr2[100], int arrLength, int &arr2Length) {
  for (int i = 0; i < arrLength; i++) {
    if (!isnumberinarray(arr[i], arr2, arrLength)) {
      AddArrayElement(arr[i], arr2, arr2Length);
    }
  }
}

void PrintArray(int arr[10], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  srand((unsigned)time(NULL));

  int arr[1000], arr2[10], arrLength, arr2Length = 0;
  FillArray(arr, arrLength);

  cout << "Array 01 elements: ";
  PrintArray(arr, arrLength);

  CopyArray(arr, arr2, arrLength, arr2Length);

  cout << "\nArray 02 distinct elements: ";
  PrintArray(arr2, arr2Length);

  signature();
  return 0;
}
