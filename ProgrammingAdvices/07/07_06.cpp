#include <iomanip>
#include <iostream>
using namespace std;
// Fill a 3x3 array with orderd numbers, from 01 to 09.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸"
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

void OrderArray(int mat[3][3], short rows, short clos) {
  short b = 1;
  for (short i = 0; i < rows; i++) {
    for (short j = 0; j < clos; j++, b++) {
      mat[i][j] = b;
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

int main() {
  int mat[3][3];

  OrderArray(mat, 3, 3);
  cout << "The following is a 3x3 ordered matrix:\n";
  PrintArray(mat, 3, 3);

  signature();
  return 0;
}
