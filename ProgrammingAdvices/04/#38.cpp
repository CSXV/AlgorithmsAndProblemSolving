#include <cmath>
#include <iostream>
using namespace std;
// Read an number, and print if its prime or not.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

enum primeornot { prime = 1, notprime = 2 };

float readnumber(string message) {
  int number;
  cout << message;
  cin >> number;
  return number;
}

primeornot checknumber(int number) {
  int M = round(number / 2);

  for (int C = 2; C <= M; C++) {
    if (number % C == 0)
      return primeornot::notprime;
  }
  return primeornot::prime;
}

void printresult(int number) {
  switch (checknumber(number)) {
  case primeornot::prime:
    cout << "The number is prime.";
    break;
  case primeornot::notprime:
    cout << "The numbe is not prime.";
    break;
  }
}

int main() {
  printresult(readnumber("Please enter an number: "));
  signature();
  return 0;
}
