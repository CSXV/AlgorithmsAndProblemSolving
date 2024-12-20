#include <iostream>
using namespace std;
// Read an number, and print all Perfect numbers to it.

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

bool isperfectnumber(int number) {
  int sum = 0;
  for (int i = 1; i < number; i++) {
    if (number % i == 0)
      sum += i;
  }
  return number == sum;
}

void Printresults(int number) {
  for (int i = 1; i <= number; i++) {
    if (isperfectnumber(i)) {
      cout << i << endl;
    }
  }
}

int main() {
  Printresults(readPnumber("Please enter a positive number: "));
  signature();
  return 0;
}
