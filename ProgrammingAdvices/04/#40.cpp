#include <iostream>
using namespace std;
// Calculate the sales tax and services fees for a bill.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

float readnumber(string message) {
  float number;
  cout << message;
  cin >> number;
  return number;
}

float CalcServices(float bill) { return bill * 0.10; }

float CalcTax(float bill) { return bill * 0.16; }

float Totalbill(float bill) { return bill * 1.10 * 1.16; }

void printresults(float bill) {
  cout << "\n***********************\n";
  cout << "The Services fee: " << CalcServices(bill) << endl;
  cout << "The Sales Tax   : " << CalcTax(bill) << endl;
  cout << "***********************\n";
  cout << "The Total bill  : " << Totalbill(bill) << endl;
  cout << "***********************\n";
}

int main() {
  float bill = readnumber("Please enter the total bill: ");
  printresults(bill);
  signature();
  return 0;
}
