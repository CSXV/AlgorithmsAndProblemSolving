#include <iostream>
using namespace std;

int main()
{
// calculate the monthly installemt amount based on the lona amount and number of months

    short int amount, months;

    cout << "Enter total amount: ";
        cin >> amount;
    cout << "Enter total months: ";
        cin >> months;

    short int installment = amount/months;
    cout << "The installment amount: " << installment << endl;
    return 0;
}
