#include <iostream>
using namespace std;

float RecArea(short int a, short int b)
{
    return a*b;
}
int main()
{
    // rectangle area
    short int a, b;
    cout << "Enter the hight: ";
    cin >> a;
    cout << "Enter the width: ";
    cin >> b;
    cout << "The rectange area: " << RecArea(a, b) << endl;
    return 0;
}
