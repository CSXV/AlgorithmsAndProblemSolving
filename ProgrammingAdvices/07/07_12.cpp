#include <cstdlib>
#include <iostream>
using namespace std;
// Fill two 3x3 arrays with random numbers, from 01 to 10, then print the sum of
// them, then check if they are typical or not.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸"
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

int RandomNumber(int from, int to) {
  int randNum = rand() % (to - from + 1) + from;
  return randNum;
}

void RandomArray(int mat[3][3], short rows, short clos) {
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < clos; j++) {
      mat[i][j] = RandomNumber(1, 100);
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

bool TypicalMatrix(int arr[3][3], int arr2[3][3], short rows, short cols) {
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      if (arr[i][j] != arr2[i][j])
        return false;
    }
  }
  return true;
}

void PrintEqual(int arr[3][3], int arr2[3][3], int rows, int cols) {
  if (TypicalMatrix(arr, arr2, rows, cols) == true)
    cout << "\n\nYes, both matrices are Typical.";
  else
    cout << "\n\nNO, matrices are NOT Typical.";
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3], arr2[3][3];

  FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  FillMatrixWithRandomNumbers(arr2, 3, 3);
  cout << "\nMatrix 02:\n";
  PrintMatrix(arr2, 3, 3);

  PrintEqual(arr, arr2, 3, 3);

  signature();
  return 0;
}