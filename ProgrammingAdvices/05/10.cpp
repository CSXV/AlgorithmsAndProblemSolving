#include <iostream>
using namespace std;
// Read an number, and print the digits of it.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int readPnumber(string message) {
  int number;
  do {
    cout << message;
    cin >> number;
  } while (number < 0);
  return number;
}

int printdigits(int N) {
  int r = 0, N2 = 0;

  while (N > 0) {
    r = N % 10;
    N = N / 10;
    N2 = N2 * 10 + r;
  }
  return N2;
}

void digitreversed(int N) {
  int r2 = 0;

  while (N > 0) {
    r2 = N % 10;
    N = N / 10;
    cout << r2 << endl;
  }
}

int main() {
  digitreversed(printdigits(readPnumber("Please enter a positive number: ")));
  signature();
  return 0;
}
