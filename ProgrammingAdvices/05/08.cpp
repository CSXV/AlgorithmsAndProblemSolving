#include <iostream>
using namespace std;
// Read two numbers, then print the frequency of the second numberin the first
// one.

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

int countdifitreq(short digit, int N) {
  int freq = 0, r = 0;

  while (N > 0) {
    r = N % 10;
    N = N / 10;

    if (digit == r) {
      freq++;
    }
  }

  return freq;
}

int main() {
  int N = readPnumber("Please enter an number: ");
  short digit = readPnumber("Please enter one digit to check: ");

  cout << "\nDigit " << digit << " frequency is: " << countdifitreq(digit, N);

  signature();
  return 0;
}
