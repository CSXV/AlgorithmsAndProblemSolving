#include <iostream>
using namespace std;
// Read an number, and print it in reverse.

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

int main() {
  cout << "\nReverse is: "
       << printdigits(readPnumber("Please enter a positive number: "));
  signature();
  return 0;
}
