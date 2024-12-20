#include <iostream>
using namespace std;
// Read loan Amount and Number of months, then print how much to pay in monthly
// basis to full settle the loan.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

float ReadNumber(string message) {
  float Number;
  do {
    cout << message;
    cin >> Number;
  } while (Number <= 0);

  return Number;
}

float CalcMonths(float LoanAmount, float Months) { return LoanAmount / Months; }

void PrintResults(float LoanAmount, float Months) {
  cout << "\n************************************************";
  cout << "\nThe remaining months to settle the loan is: "
       << CalcMonths(LoanAmount, Months) << endl;
  cout << "\n************************************************\n";
}

int main() {
  float LoanAmount = ReadNumber("Please enter loan Amount: ");
  float Months =
      ReadNumber("Please enter how many months you need to settle the loan: ");
  PrintResults(LoanAmount, Months);
  signature();
  return 0;
}
