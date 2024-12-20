#include <iostream>
using namespace std;

int main()
{
    int Num1, Num2;
    int OperationType;

    cout << "Enter the first number: ";
        cin >> Num1;
    cout << "Enter the second number: ";
        cin >> Num2;
    cout << "Enter the Operation type:\n -(1) Sum\n -(2) Sub\n -(3) Mult\n -(4) Divid\n\n-Input: ";
        cin >> OperationType;

    switch (OperationType)
    {
    case 1:
        {int Sum = Num1+Num2;
        cout << Sum << endl;
        break;}
    case 2:
        {int Sub = Num1-Num2;
        cout << Sub << endl;
        break;}
   case 3:
        {int Mult = Num1*Num2;
        cout << Mult << endl;
        break;}
    case 4:
        {int Div = Num1/Num2;
        cout << Div << endl;
        break;}
    default:
        cout << "Error In Calculation" << endl;
    }
    return 0;
}
