#include <iostream>
using namespace std;
// Read an number, then print pattern of it is digits.

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

void printpattern(int N) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      cout << i;
    }

    cout << "\n";
  }
}

int main() {
  printpattern(readPnumber("Please enter an number: "));

  signature();
  return 0;
}
