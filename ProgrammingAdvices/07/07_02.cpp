#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
// Fill a 3x3 array with random numbers, from 01 to 100, then print each row
// sum.

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

void SumOfRows(int mat[3][3], short rows, short clos) {
  for (short i = 0; i < rows; i++) {
    cout << "Row " << (i + 1) << " Sum = " << RowSum(mat, i, clos) << endl;
  }
}

int main() {
  srand((unsigned)time(NULL));
  int mat[3][3];

  RandomArray(mat, 3, 3);
  cout << "The following is a 3x3 random matrix:\n";
  PrintArray(mat, 3, 3);

  cout << "The sum of each row in the matrix:\n";
  SumOfRows(mat, 3, 3);

  signature();
  return 0;
}
