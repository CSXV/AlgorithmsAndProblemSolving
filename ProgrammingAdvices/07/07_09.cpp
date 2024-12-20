#include <cstdlib>
#include <iostream>
using namespace std;
// Fill 3x3 arrays with random numbers, from 01 to 10, then print the middle
// row & middle col.

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

void PrintMiddleRow(int arr[3][3], short rows, short col) {
  short MiddleRow = rows / 2;

  for (short i = 0; i < col; i++) {
    printf("%0*d     ", 2, arr[MiddleRow][i]);
  }
  cout << endl;
}

void PrintMiddleCol(int arr[3][3], short rows, short col) {
  short MiddleCol = col / 2;

  for (short i = 0; i < rows; i++) {
    printf("%0*d     ", 2, arr[i][MiddleCol]);
  }
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3];

  FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  cout << "\nMiddle row of matrix 01:\n";
  PrintMiddleRow(arr, 3, 3);

  cout << "\nMiddle col of matrix 01:\n";
  PrintMiddleCol(arr, 3, 3);

  signature();
  return 0;
}
