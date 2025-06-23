#include <iostream>
using namespace std;
// Read loan Amount and monthly payment, then print how many months remaining to
// fully settle the loan.

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

float CalcMonths(float LoanAmount, float MonthlyPayment) {
  return LoanAmount / MonthlyPayment;
}

void PrintResults(float LoanAmount, float MonthlyPayment) {
  cout << "\n************************************************";
  cout << "\nThe remaining months to settle the loan is: "
       << CalcMonths(LoanAmount, MonthlyPayment) << endl;
  cout << "\n************************************************\n";
}

int main() {
  float LoanAmount = ReadNumber("Please enter loan Amount: ");
  float MonthlyPayment = ReadNumber("Please enter Monthy Payment: ");

  PrintResults(LoanAmount, MonthlyPayment);

  signature();
  return 0;
}
