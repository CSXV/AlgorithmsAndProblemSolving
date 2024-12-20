#include <cstdlib>
#include <iostream>
using namespace std;
// check if the matrix is scalar or not.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸"
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

void PrintMatrix(int arr[3][3], short Rows, short Cols) {
  for (short i = 0; i < Rows; i++) {
    for (short j = 0; j < Cols; j++) {
      printf("%0*d     ", 1, arr[i][j]);
    }
    cout << "\n";
  }
}

bool CheckScalar(int arr[3][3], short rows, short cols) {
  int FirstDiagElement = arr[0][0];

  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      if (i == j && arr[i][j] != FirstDiagElement)
        return false;
      else if (i != j && arr[i][j] != 0)
        return false;
    }
  }

  return true;
}

void PrintResults(int arr[3][3], int rows, int cols) {
  if (CheckScalar(arr, rows, cols))
    cout << "\n\nYES, Matrix is Scalar.";
  else
    cout << "\n\nNO, Matrix is NOT Scalar.";
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};

  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  PrintResults(arr, 3, 3);

  signature();
  return 0;
}
