#include <cstdlib>
#include <iostream>
using namespace std;
// Fill an array with max size of 100 with random numbers from 01 to 100, then
// copy it to another array using AddArrayElement function.

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

void AddArrayElement(int number, int arr[100], int &arrLength) {
  arrLength++;
  arr[arrLength - 1] = number;
}

void CopyArray(int arr[100], int arr2[100], int arrLength, int arr2Length) {
  for (int i = 0; i < arrLength; i++) {
    AddArrayElement(arr[i], arr2, arr2Length);
  }
}

void PrintArray(int arr[100], int arrLength) {
  cout << "\nArray elements: ";
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  srand((unsigned)time(NULL));

  int arr[100], arr2[100], arrLength = 0, arr2Length = 0;
  FillArray(arr, arrLength);
  CopyArray(arr, arr2, arrLength, arr2Length);

  cout << "Array 01 elements: ";
  PrintArray(arr, arrLength);

  cout << "\nArray 02 elements: ";
  PrintArray(arr2, arrLength);

  signature();
  return 0;
}
