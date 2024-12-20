#include <iostream>
using namespace std;

int main()
{
// calculate the number of months to fully settle a loan
    short int Loan, MonthPay;

    cout << "Enter Loan Amount: ";
        cin >> Loan;
    cout << "Enter Monthly Payment: ";
        cin >> MonthPay;

    float Settle = Loan/MonthPay;
    cout << "The number of Months to fully settle the loan is: " << Settle << endl;
    return 0;
}
