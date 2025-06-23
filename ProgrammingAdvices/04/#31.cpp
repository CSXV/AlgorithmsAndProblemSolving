#include <cmath>
#include <iostream>
#include <ostream>
using namespace std;

// Calculate the 02, 03, 04 power of an number.

int readnumber() {
  int a;

  cout << "Print an number to the power of 02, 03 & 04.\n";
  cout << "Please enter an number: ";
  cin >> a;

  return a;
}

int powerof2(int N) { return pow(N, 2); }

int powerof3(int N) { return pow(N, 3); }

int powerof4(int N) { return pow(N, 4); }

void signature() {
  cout << "\n*************\nNEVER SETTLE.\n*************\n" << endl;
}

void printresults(int N) {
  cout << "\nThe power 02 of (" << N << ") is: " << powerof2(N) << "." << endl;
  cout << "The power 03 of (" << N << ") is: " << powerof3(N) << "." << endl;
  cout << "The power 04 of (" << N << ") is: " << powerof4(N) << "." << endl;
}

int main() {
  int N = readnumber();

  printresults(N);
  signature();

  return 0;
}
