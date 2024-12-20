#include <cstdlib>
#include <iostream>
using namespace std;
// Fill an matrix with random numbers from 00 to 100, then read an number, and
// check if it is in the matrix.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

short ReadPNumber(string message) {
  short N;

  cout << message;
  cin >> N;

  return N;
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

bool CheckNumber(int arr[3][3], short N, short rows, short cols) {
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      if (arr[i][j] == N)
        return true;
    }
  }
  return false;
}

void PrintLook(int arr[3][3], short N, short rows, short cols) {
  if (CheckNumber(arr, N, rows, cols) == true)
    cout << "\nYes, it is there.";
  else
    cout << "\nNo, it is not there.";
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3];

  FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  short N = ReadPNumber("Please enter the number to look for in matrix: ");
  PrintLook(arr, N, 3, 3);

  signature();
  return 0;
}
