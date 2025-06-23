#include <iostream>
using namespace std;

// Read two numbers then print them and the swap of.

void readnumbers(int &num1, int &num2) {
  cout << "Please enter the first number: ";
  cin >> num1;

  cout << "Please enter the second number: ";
  cin >> num2;
}

void swapnumbers(int &a, int &b) {
  int temp;

  temp = a;
  a = b;
  b = temp;
}

void printresults(int num1, int num2) {
  cout << "Number 01 is: " << num1 << endl;
  cout << "Number 02 is: " << num2 << endl;
}

int main() {
  int num1, num2;

  readnumbers(num1, num2);
  printresults(num1, num2);

  swap(num1, num2);
  printresults(num1, num2);

  return 0;
}
