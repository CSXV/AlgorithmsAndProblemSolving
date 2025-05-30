// sum of two-dim array.

#include <iostream>
#include <vector>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

// without vectors
int _sumOfMatrix(int matrix[3][3], int col, int row) {
  int sum = 0;

  for (short i = 0; i < col; i++) {
    for (short j = 0; j < row; j++) {
      sum += matrix[i][j];
    }
  }

  return sum;
}

int sumOfMatrix(vector<vector<int>> matrix, int col, int row) {
  int sum = 0;

  for (short i = 0; i < col; i++) {
    for (short j = 0; j < row; j++) {
      sum += matrix[i][j];
    }
  }

  return sum;
}

int main() {
  int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  cout << "sum of matrix is: " << sumOfMatrix(matrix, 3, 3) << endl;
  cout << "sum of array is: " << _sumOfMatrix(array, 3, 3) << endl;

  signature();
  return 0;
}
