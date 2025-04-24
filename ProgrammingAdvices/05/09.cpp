#include <iostream>
using namespace std;
// Read an number, then print the Frequency of all its digits.

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

int countdifitreq(short D, int N) {
  int r = 0, f = 0;

  while (N > 0) {
    r = N % 10;
    N = N / 10;

    if (r == D) {
      f++;
    }
  }

  return f;
}

void printDigitFreq(int N) {
  cout << endl;

  for (int i = 0; i < 10; i++) { // OR (i <= 09), We have digits from 01-09.
    short D = 0;
    D = countdifitreq(i, N);

    if (D > 0) { // To not print digits that have 00 Frequency.
      cout << "Digit " << i << " Frequency is: " << D << " Time(s).\n";
    }
  }
}

int main() {
  int N = readPnumber("Please enter an number: ");
  printDigitFreq(N);

  signature();
  return 0;
}
