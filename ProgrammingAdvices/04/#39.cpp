#include <iostream>
using namespace std;
// Read total bill and total cash paid, then print the remainder.

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

float calcRemainder(int totalbill, int cashpaid) {
  return cashpaid - totalbill;
}

void printresults(float totalbill, float cashpaid) {
  cout << "\n\n*************************\n";
  cout << "* The total bill: " << totalbill << endl;
  cout << "* The cash paid : " << cashpaid << endl;
  cout << "*************************\n";
  cout << "* The Remainder : " << calcRemainder(totalbill, cashpaid) << endl;
  cout << "*************************\n";
}

int main() {
  float totalbill = readnumber("Please enter the total bill: ");
  float cashpaid = readnumber("Please enter Cash Paid: ");

  printresults(totalbill, cashpaid);

  signature();
  return 0;
}
