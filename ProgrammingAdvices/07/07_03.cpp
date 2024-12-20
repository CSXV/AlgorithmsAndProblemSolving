#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
// Fill a 3x3 array with random numbers, from 01 to 100, then sum each row in
// separate array and then print the results.

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

void PrintArray(int mat[3][3], short rows, short clos) {
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < clos; j++) {
      cout << setw(3) << mat[i][j] << "    ";
    }
    cout << "\n";
  }
}

int RowSum(int mat[3][3], short rows, short cols) {
  int sum = 0;
  for (short j = 0; j < cols; j++) {
    sum += mat[rows][j];
  }
  return sum;
}

void SumMatrixRowsInArray(int mat[3][3], int ArrSum[3], short rows,
                          short clos) {
  for (short i = 0; i < rows; i++) {
    ArrSum[i] = RowSum(mat, i, clos);
  }
}

void PrintRowsSumArray(int ArrSum[3], short rows) {
  for (short i = 0; i < rows; i++) {
    cout << "Row " << (i + 1) << " Sum = " << ArrSum[i] << endl;
  }
}

int main() {
  srand((unsigned)time(NULL));
  int mat[3][3];
  int ArrSum[3];

  RandomArray(mat, 3, 3);
  cout << "The following is a 3x3 random matrix:\n";
  PrintArray(mat, 3, 3);

  SumMatrixRowsInArray(mat, ArrSum, 3, 3);
  cout << "The Sum of each row in the matrix in an array:\n";
  PrintRowsSumArray(ArrSum, 3);

  signature();
  return 0;
}
