#include <cstdlib>
#include <iostream>
using namespace std;
// Fill an matrix with random numbers from 00 to 10, then count an number in it.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸"
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

short ReadNumber(string message) {
  short N = 0;

  cout << message;
  cin >> N;

  return N;
}

int RandomNumber(short from, short to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

void RandomArray(int arr[3][3], short rows, short clos) {
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < clos; j++) {
      arr[i][j] = RandomNumber(1, 100);
    }
  }
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
  short Counter = 0;
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
      Counter++;
      arr[i][j] = RandomNumber(1, 10);
    }
  }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
      printf("%0*d     ", 2, arr[i][j]);
    }
    cout << "\n";
  }
}

short CountNumber(int arr[3][3], int N, short rows, short cols) {
  short Count = 0;

  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      if (arr[i][j] == N)
        Count++;
    }
  }
  return Count;
}

void PrintResults(int arr[3][3], int N, short rows, short cols) {
  // printf("Number %0*d count in matrix is: %0*d.", 2, N, 2,
  // CountNumber(arr, N, 3, 3));
  cout << "Number (" << N << ") Count in matrix is: ("
       << CountNumber(arr, N, 3, 3) << ")." << endl;
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3], N = 0;

  FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  N = ReadNumber("Please enter an number to count it in matrix: ");
  PrintResults(arr, N, 3, 3);

  signature();
  return 0;
}
