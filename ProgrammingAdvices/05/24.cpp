#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then print a random numbers from 01 to 100, then print the
// maximum of them.

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
  cout << "Enter nuber of elements: ";
  cin >> arrLength;
  for (int i = 0; i < arrLength; i++) {
    arr[i] = RandomNumber(1, 100);
  }
}

void PrintArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
}

int CheckMax(int arr[100], int arrLength) {
  int max = arr[0];
  for (int i = 0; i < arrLength; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int main() {
  srand((unsigned)time(NULL));
  int arr[100], arrLength;
  FillArray(arr, arrLength);

  cout << "Array elements: ";
  PrintArray(arr, arrLength);
  cout << "\nMax Number is: ";
  cout << CheckMax(arr, arrLength);

  signature();
  return 0;
}
