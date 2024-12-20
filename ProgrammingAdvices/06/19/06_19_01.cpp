#include <iostream>
using namespace std;
// Print an number, until we reach another on, using Recursion loop.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

void PrintNumber(int N, int M) {
  if (M >= N) {
    cout << M << endl;
    PrintNumber(N, M - 1);
  }
}

int main() {
  PrintNumber(1, 4);

  signature();
  return 0;
}
