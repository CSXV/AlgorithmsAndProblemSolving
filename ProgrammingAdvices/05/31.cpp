#include <cstdlib>
#include <iostream>
using namespace std;
// Read an number, then print an array with ordered numbers from 01 to N, then
// print it after shuffle.

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
    arr[i] = i + 1;
  }
}

void SuffleArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    Swap(arr[RandomNumber(1, arrLength) - 1],
         arr[RandomNumber(1, arrLength) - 1]);
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

  cout << "\nArray elements before shuffle: ";
  PrintArray(arr, arrLength);

  SuffleArray(arr, arrLength);

  cout << "\nArray elements after shuffle: ";
  PrintArray(arr, arrLength);

  signature();
  return 0;
}
