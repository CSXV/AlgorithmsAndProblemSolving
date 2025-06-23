#include <iostream>
using namespace std;
// Read PIN, and if its corrcet, print the Balance, if entered 3 times worng,
// print lock card.

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
  int counter = 3;

  do {
    counter--;
    PIN = ReadPIN();

    if (PIN == "1234") {
      return 1; // This will exit the function and return 1.
    } else {
      system("color 4F"); // Turn the screen background Red.
      cout << "\nWrong PIN, You have " << counter << " More tries." << endl;
    }
  } while (counter >= 1 && PIN != "1234");

  return 0; // When you reach here, this means login faild.
}

int main() {
  if (login()) {
    system("color 2F"); // Turn the screen background Green.
    cout << "\nYour account balance is: " << 7500 << '\n';
  } else {
    cout << "\nYour card is blocked, call the bank for help.";
  }

  signature();
  return 0;
}
