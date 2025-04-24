#include <iostream>
using namespace std;
// Read an number, and print if it is palindrome number or not.

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

int reversedDigits(int N) {
  int r = 0, N2 = 0;

  while (N > 0) {
    r = N % 10;
    N = N / 10;

    N2 = N2 * 10 + r;
  }

  return N2;
}

bool IsPalindromeNumber(int N) { return N == reversedDigits(N); }

int main() {
  if (IsPalindromeNumber(readPnumber("Please enter a positive number: "))) {
    cout << "\nYes, it is a palindrome number." << endl;
  } else {
    cout << "\nNo, it is not a palindrome number." << endl;
  }

  signature();
  return 0;
}
