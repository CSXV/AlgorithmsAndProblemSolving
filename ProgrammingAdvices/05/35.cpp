#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then fill an array with random numbers from 01 to 100 with
// it, then read another one to search it in the array, then print its index and
// position if its found, otherwise return -1.

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
  int Random = rand() % (to - from + 1) + from;
  return Random;
}

void FillArray(int arr[100], int &arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arr[i] = RandomNumber(1, 100);
  }
}

short SearchForNumber(int arr[100], int S, int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    if (arr[i] == S)
      return i;
  }
  return -1;
}

void PrintArray(int arr[100], int arrLength) {
  cout << "\nArray 01 elements: ";
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
}

bool IsNumberFound(int arr[100], int S, int arrLength) {
  return SearchForNumber(arr, S, arrLength) != -1;
}

int main() {
  srand((unsigned)time(NULL));

  int arr[100];
  int arrLength = ReadPNumber("Please enter a possitive number: ");

  FillArray(arr, arrLength);
  PrintArray(arr, arrLength);

  int S = ReadPNumber("\nPlease enter an number to search for: ");
  cout << "\nThe number you are looking for is: " << S << endl;

  if (!IsNumberFound(arr, S, arrLength)) {
    cout << "No, The number is not found :(\n";
  } else {
    cout << "Yes, the number is found :)";
  }

  signature();
  return 0;
}
