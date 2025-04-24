#include <iostream>
using namespace std;
// Read an number, then print pattern of characters from it.

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
  for (char i = 64; i <= 64 + N; i++) {
    for (int j = 65; j <= i; j++) {
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
