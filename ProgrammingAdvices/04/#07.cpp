#include <iostream>
using namespace std;

// Print half an number.

int ReadNumber() {
  int Number;

  cout << "Please enter an number: ";
  cin >> Number;

  return Number;
}

float HalfNumber(int Number) { return (float)Number / 2; }

void PrintNumber(int Number) {
  string Result =
      "Half of " + to_string(Number) + " is " + to_string(HalfNumber(Number));

  cout << endl << Result << endl;
}

int main() {
  PrintNumber(ReadNumber());

  return 0;
}
