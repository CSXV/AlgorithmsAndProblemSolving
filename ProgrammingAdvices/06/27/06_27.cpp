#include <iostream>
using namespace std;
// Print 10x10 multiplication table, using two Dimensional array.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int main() {
  int y[10][10];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      y[i][j] = (i + 1) * (j + 1);
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%0*d ", 2, y[i][j]);
    }
    cout << endl;
  }

  signature();
  return 0;
}
