#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then print an array of random numbers from 01 to 100, then
// copy it to another array.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

void FillArray(int arr[100], int &arrLength) {
  cout << "Enter number of elements: ";
  cin >> arrLength;
  for (int i = 0; i < arrLength; i++) {
    arr[i] = RandomNumber(1, 100);
  }
}

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arrDestination[i] = arrSource[i];
  }
}

void PrintArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  srand((unsigned)time(NULL));

  int arr[100], arr2[100], arrLength;
  FillArray(arr, arrLength);
  CopyArray(arr, arr2, arrLength);

  cout << "Array 01 elements: ";
  PrintArray(arr, arrLength);

  cout << "\nArray 02 elements: ";
  PrintArray(arr2, arrLength);

  signature();
  return 0;
}
