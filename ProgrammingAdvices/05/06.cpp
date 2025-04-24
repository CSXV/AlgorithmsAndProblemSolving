#include <iostream>
using namespace std;
// Read an number, and print the sum of the digits of it.

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
  int r = 0, sum = 0;

  while (N > 0) {
    r = N % 10;
    N = N / 10;

    sum = sum + r;
  }

  return sum;
}

int main() {
  cout << "\nSum of digits is: "
       << printdigits(readPnumber("Please enter a positive number: "));

  signature();
  return 0;
}
