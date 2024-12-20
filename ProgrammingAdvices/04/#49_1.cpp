#include <iostream>
using namespace std;
// Read PIN, and if its corrcet, print the Balance.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int CheckPIN() {
  int PIN;
  int Balance = 5151;

  cout << "Please enter the PIN:";
  cin >> PIN;

  if (PIN != 1234) {
    do {
      cout << "Wrong PIN, Try Again: ";
      cin >> PIN;
    } while (PIN != 1234);
  }

  return Balance;
}

void PrintResults(int Balance) {
  cout << "You Balance is: " << Balance << endl;
}

int main() {
  PrintResults(CheckPIN());
  signature();
  return 0;
}
