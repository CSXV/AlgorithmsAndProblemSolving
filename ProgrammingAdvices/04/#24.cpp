#include <iostream>
using namespace std;

// Validate age between 18 and 45.

int readage() {
  int age;

  cout << "Please enter you age: ";
  cin >> age;

  return age;
}

bool validateage(int number, int from, int to) {
  return (number >= from && number <= to);
}

void printresults(int age) {
  if (validateage(age, 18, 45))
    cout << age << " is valid age.\n";
  else
    cout << age << " is invalid age.\n";
}

int main() {
  printresults(readage());

  return 0;
}
