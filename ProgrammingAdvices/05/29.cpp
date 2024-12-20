#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then print an array of random numbers from 01 to 100, then
// copy only prime numbers to another array.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

enum enprimeodd { prime = 1, odd = 2 };

enprimeodd checkprime(int number) {
  int m = round(number / 2);
  for (int c = 2; c <= m; c++) {
    if (number % c == 0) {
      return enprimeodd::odd;
    }
  }
  return enprimeodd::prime;
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

void CopyPrimeArray(int arrSource[100], int arrDestination[100], int arrLength,
                    int &arr2Length) {
  int c = 0;
  for (int i = 0; i < arrLength; i++) {
    if (CheckPrime(arrSource[i]) == enPrimeOdd::Prime) {
      arrDestination[c] = arrSource[i];
      c++;
    }
  }
  arr2Length = --c;
}

void PrintArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  srand((unsigned)time(NULL));
  int arr[100], arr2[100], arrLength, arr2Length = 0;

  FillArray(arr, arrLength);
  CopyPrimeArray(arr, arr2, arrLength, arr2Length);

  cout << "Array 01 elements: ";
  PrintArray(arr, arrLength);

  cout << "\nPrime numbers in array are: ";
  PrintArray(arr2, arr2Length);

  signature();
  return 0;
}
