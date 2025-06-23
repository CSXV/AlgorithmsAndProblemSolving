#include <iostream>
#include <ostream>
using namespace std;

// Read three numbers, then print the maximum of the three.

void readnumbers(int &num1, int &num2, int &num3) {
  cout << "Please enter the first number: ";
  cin >> num1;

  cout << "Please enter the second number: ";
  cin >> num2;

  cout << "Please enter the third number: ";
  cin >> num3;
}

int maxofnumbers(int &num1, int &num2, int &num3) {
  if (num1 > num2)
    if (num1 > num3)
      return num1;
    else
      return num3;

  else if (num2 > num3)
    return num2;
  else
    return num3;
}

void printresults(int Max) {
  cout << "\nThe maximum number of the three is: " << Max << endl;
}

int main() {
  int num1, num2, num3;

  readnumbers(num1, num2, num3);
  printresults(maxofnumbers(num1, num2, num3));

  return 0;
}
