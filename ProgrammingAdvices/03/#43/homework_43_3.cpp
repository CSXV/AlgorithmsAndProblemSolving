#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int Num1, Num2;
    string OperationType;

    cout << "Enter the first number: ";
        cin >> Num1;
    cout << "Enter the second number: ";
        cin >> Num2;
    cout << "Enter the Operation type: ";
        cin >> OperationType;

    if(OperationType == "+")
    {
        int Sum = Num1+Num2;
        cout << Sum << endl;
    }
    else if(OperationType == "-")
    {
        int Subt = Num1-Num2;
        cout << Subt << endl;
    }
   else if(OperationType == "*")
    {
        int Mult = Num1*Num2;
        cout << Mult << endl;
    }
    else if(OperationType == "/")
    {
        int Devi = Num1/Num2;
        cout << Devi << endl;
    }
    else
    {
        cout << "Error In Calculation" << endl;
    }
    return 0;
}
