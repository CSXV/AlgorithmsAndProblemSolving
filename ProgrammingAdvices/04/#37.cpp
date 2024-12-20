#include <iostream>
using namespace std;
// Sum numbers until the read of -99.

void segnature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

float readnumber(string message) {
  int number = 0;
  cout << message;
  cin >> number;
  return number;
}

float sumnumber() {
  int Number = 0, Sum = 0, C = 1;
  do {
    Number = readnumber("Please Enter an number (" + to_string(C) + "): ");
    if (Number == -99) {
      break;
    }
    Sum += Number;
    C++;
  } while (Number != -99);
  return Sum;
}

int main() {
  cout << endl << "Results: " << sumnumber() << endl;
  segnature();
  return 0;
}
