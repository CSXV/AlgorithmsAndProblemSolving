#include <iostream>
#include <ostream>
using namespace std;
//Read age until 18 or 45.
int readage() {
  int age;
  cout << "Please enter you age between 18 and 45: ";
  cin >> age;
  return age;
}

bool validateage(int number, int from, int to) {
  return (number >= from && number <= to);
}

int readuntilage(int from, int to) {
  int age = 0;
  do {
    (age = readage());
  } while (!validateage(age, from, to));
  return age;
}

void printresults(int age) { cout << "You age is: " << age << endl; }

int main() {
  printresults(readuntilage(18, 45));
  return 0;
}
