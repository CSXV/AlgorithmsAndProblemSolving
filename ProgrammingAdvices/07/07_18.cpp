#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
// Fill two matrix with random numbers from 00 to 100, then print intersected
// numbers in two of them.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
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
      arr[i][j] = RandomNumber(1, 100);
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

int CheckNumbers(int arr[3][3], short N, short rows, short cols) {
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      if (arr[i][j] == N)
        return true;
    }
  }
  return false;
}

void PrintIntersect(int arr[3][3], int arr2[3][3], short rows, short cols) {
  short N = 0;

  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      N = arr[i][j];
      if (CheckNumbers(arr, N, rows, cols))
        cout << setw(2) << N << "\t";
    }
  }
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3] = {{77, 5, 12}, {22, 20, 1}, {1, 0, 9}};
  int arr2[3][3] = {{5, 80, 90}, {22, 77, 1}, {10, 8, 33}};
  // int arr[3][3], arr2[3][3];

  // FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  // FillMatrixWithRandomNumbers(arr2, 3, 3);
  cout << "Matrix 02:\n";
  PrintMatrix(arr2, 3, 3);

  PrintIntersect(arr, arr2, 3, 3);

  signature();
  return 0;
}
