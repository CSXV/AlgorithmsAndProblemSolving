#include <cstdlib>
#include <iostream>
using namespace std;
// Fill an matrix with random numbers from 00 to 10, then check if it is sparce
// matrix.

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

int CountNumberInMatrix(int arr[3][3], short N, short rows, short cols) {
  short Count = 0;

  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      if (arr[i][j] == N)
        Count++;
    }
  }
  return Count;
}

bool CheckSparce(int arr[3][3], short rows, short cols) {
  short MatrixSize = rows * cols;
  return (CountNumberInMatrix(arr, 0, 3, 3) >= (MatrixSize / 2));
}

void PrintSparce(int arr[3][3], int rows, int cols) {
  if (CheckSparce(arr, rows, cols) == true)
    cout << "\n\nYes, the matrix is Sparce.";
  else
    cout << "\n\nNo, the matrix is not Sparce.";
}

int main() {
  srand((unsigned)time(NULL));
  // int arr[3][3] = {{0, 0, 0}, {0, 0, 0}, {12, 3, 4}};
  int arr[3][3];

  FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  PrintSparce(arr, 3, 3);

  signature();
  return 0;
}
