#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then print two arrays with random number in it from 01 to
// 100, then sum their elements in a third array.

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

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

void FillArray(int arr[100], int &arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arr[i] = RandomNumber(1, 100);
  }
}

void SumArray(int arr[100], int arr2[100], int arr3[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arr3[i] = arr[i] + arr2[i];
  }
}

void PrintArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  srand((unsigned)time(NULL));
  int arr[100], arr2[100], arr3[100];
  int arrLength = ReadPNumber("Please enter a possitive number: ");

  FillArray(arr, arrLength);
  FillArray(arr2, arrLength);

  SumArray(arr, arr2, arr3, arrLength);

  cout << "Array 01 elements:\n";
  PrintArray(arr, arrLength);

  cout << "\nArray 02 elements:\n";
  PrintArray(arr2, arrLength);

  cout << "\nThe sum of array 01 and 02 elements:\n";
  PrintArray(arr3, arrLength);

  signature();
  return 0;
}
