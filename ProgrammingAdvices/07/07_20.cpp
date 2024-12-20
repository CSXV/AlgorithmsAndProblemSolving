#include <cstdlib>
#include <iostream>
using namespace std;
// Fill a matrix with random numbers from 00 to 100, then check if it is
// palindrome or not.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}
//
// int RandomNumber(int from, int to) {
//   int randNum = rand() % (to - from + 1) + from;
//   return randNum;
// }
//
// void RandomArray(int mat[3][3], short rows, short clos) {
//   for (short i = 0; i < rows; i++) {
//     for (short j = 0; j < clos; j++) {
//       mat[i][j] = RandomNumber(1, 100);
//     }
//   }
// }
//
// void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols) {
//   short Counter = 0;
//   for (short i = 0; i < Rows; i++) {
//     for (short j = 0; j < Cols; j++) {
//       Counter++;
//       arr[i][j] = RandomNumber(1, 100);
//     }
//   }
// }

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
      if (arr[i][j] <= N) {
        N = arr[i][j];
        return N;
      }
    }
  }
  return 0;
}

bool CheckPalindrome(int arr[3][3], short rows, short cols) {
  short N = arr[0][0], C = 0;

  for (short i = 0; i < rows; i++, C++) {
    for (short j = 0; j < cols / 2; j++) {
      if (arr[i][j] != arr[i][cols - 1 - j])
        return false;
    }
  }
  return true;
}

void PrintPalindrome(int arr[3][3], short rows, short cols) {
  if (CheckPalindrome(arr, rows, cols))
    cout << "\nYES, Matrix is palindrome.";
  else
    cout << "\nNO, Matrix is NOT palindrome.";
}

int main() {
  srand((unsigned)time(NULL));
  int arr[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};
  // int arr[3][3];

  // FillMatrixWithRandomNumbers(arr, 3, 3);
  cout << "Matrix 01:\n";
  PrintMatrix(arr, 3, 3);

  PrintPalindrome(arr, 3, 3);

  signature();
  return 0;
}
