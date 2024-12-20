#include <iostream>
using namespace std;
// Simple Calculator :)

void segnature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

enum enOperation { Add = '+', Subtract = '-', Mulitply = '*', Divid = '/' };

float readnumber(string message) {
  float number = 0;
  cout << message;
  cin >> number;
  return number;
}

enOperation readoperatrion() {
  char OT = '+';
  cout << "Please choose an operation: (+), (-), (*), (/): ";
  cin >> OT;
  return (enOperation)OT;
}

float CalOperation(float number1, float number2, enOperation operation) {
  if (operation == '+')
    return number1 + number2;
  else if (operation == '-')
    return number1 - number2;
  else if (operation == '*')
    return number1 * number2;
  else if (operation == '/')
    return number1 / number2;
  else
    return 0;
}

void printresults(float results) {
  cout << "The results are: " << results << endl;
}

int main() {
  float number1 = readnumber("Please enter the first number: ");
  float number2 = readnumber("Please enter the second number: ");
  enOperation operation = readoperatrion();
  cout << endl
       << "Results: " << CalOperation(number1, number2, operation) << endl;

  segnature();
  return 0;
}
