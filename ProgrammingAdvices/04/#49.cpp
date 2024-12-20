#include <iostream>
using namespace std;
// Read PIN, and if its corrcet, print the Balance.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

string ReadPIN() {
  string PIN;
  cout << "Please enter PIN:";
  cin >> PIN;
  return PIN;
}

bool login() {
  string PIN;
  do {
    PIN = ReadPIN();
    if (PIN == "1234") {
      return 1; // This will exit the function and return 1.
    } else {
      cout << "\nWrong PIN:";
      system("color 4F"); // Turn the screen background Red.
    }
  } while (PIN != "1234");
  return 0;
}

int main() {
  if (login()) {
    system("color 2F"); // Turn the screen background Green.
    cout << "\nYour account balance is: " << 7500 << '\n';
  }
  signature();
  return 0;
}
