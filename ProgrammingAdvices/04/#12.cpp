#include <iostream>
#include <ostream>
using namespace std;

// Print the maximum of two numbers.

void readnumbers(int &num1, int &num2) {
  cout << "Please enter the first number: ";
  cin >> num1;

  cout << "Pleae enter the second number: ";
  cin >> num2;
}

int maxofnumbers(int &num1, int &num2) {
  if (num1 > num2)
    return num1;
  else {
    return num2;
  }
}

void printresults(int Max) {
  cout << "\nThe maxinum number of the two is: " << Max << endl;
}

int main() {
  int num1, num2;

  readnumbers(num1, num2);
  printresults(maxofnumbers(num1, num2));

  return 0;
}
