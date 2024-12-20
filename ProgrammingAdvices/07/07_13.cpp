#include <cstdlib>
#include <iostream>
using namespace std;
// check if the matrix is identity or not.

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

bool CheckIdentity(int arr[3][3], short rows, short cols) {
  // Check diagonal elements = 01, and rest of elements = 00.
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < cols; j++) {
      // Check for giaonals elements.
      if (i == j && arr[i][j] != 1)
        return false;
      // Check for the rest of elements.
      else if (i != j && arr[i][j] != 0)
        return false;
    }
  }
  return true;
}

void PrintIdentity(int arr[3][3], int rows, int cols) {
  if (CheckIdentity(arr, rows, cols))
    cout << "\n\nYES, Matrix is identity.";
  else
    cout << "\n\nNO, matrix is NOT identity.";
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  PrintIdentity(arr, 3, 3);

  signature();
  return 0;
}
