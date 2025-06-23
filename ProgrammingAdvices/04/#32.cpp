#include <iostream>
using namespace std;

// Calculate N power to an number.

int readnumber() {
  int a;

  cout << "Print an number to the power of another number.\n";
  cout << "Please enter an Number: ";
  cin >> a;

  return a;
}

int readpower() {
  int b;

  cout << "Please enter the Power: ";
  cin >> b;

  return b;
}

int powerofN(int N, int P) {
  if (P == 0) {
    return 1; // Any number to the power of 00 is 01;
  }

  int M = 1;
  for (int i = 1; i <= P; i++) {
    M = M * N;
  }

  return M;
}

void printresults(int N, int P) {
  cout << "\nThe power (" << P << ") of (" << N << ") is: " << powerofN(N, P)
       << "." << endl;
}

void segnature() {
  cout << "\n*************\nNEVER SETTLE.\n*************\n" << endl;
}

int main() {
  int N = readnumber();
  int P = readpower();

  printresults(N, P);
  segnature();

  return 0;
}
