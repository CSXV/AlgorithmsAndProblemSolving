#include <iostream>
using namespace std;

void Two(short int num1, short int num2)
{
    //short int num1, num2;
    cout << "two numbers: " << endl << num1 << endl << num2 << endl;
}
//
void Sswap(short int num1, short int num2)
{
    //short int num1, num2;
    cout << "swap of two numbers: " << endl << num2 << endl << num1 << endl;
}
//
int main()
{
    short int num1, num2;

    cout << "enter number 1: ";
        cin >> num1;
    cout << "enter number 2: ";
        cin >> num2;

    Two(num1, num2);
    Sswap(num1, num2);

    return 0;
}
