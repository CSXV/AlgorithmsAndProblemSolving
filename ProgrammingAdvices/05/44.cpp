#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then fill an array with random numbers from -100 to 100, then
// print possitive numbers in it.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int ReadPNumber(string message) {
  int N;
  do {
    cout << message;
    cin >> N;
  } while (N <= 0);
  return N;
}

int checknumber(int arr[100], int arrLength) {
  int counter = 0;
  for (int i = 0; i < arrLength; i++) {
    if (arr[i] >= 0)
      counter++;
  }
  return counter;
}

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

void FillArray(int arr[100], int &arrLength) {
  for (int i = 0; i < arrLength; i++) {
    arr[i] = RandomNumber(-100, 100);
  }
}

void PrintArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  srand((unsigned)time(NULL));
  int arr[100];
  int arrLength = ReadPNumber("Please enter a possitive number: ");

  FillArray(arr, arrLength);

  cout << "Array 01 elements:\n";
  PrintArray(arr, arrLength);

  cout << "\nPositive numbers count is: ";
  cout << checknumber(arr, arrLength);

  signature();
  return 0;
}
