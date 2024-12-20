#include <iostream>
#include <cmath>
using namespace std;

float CricleThDia(short int diameter)
{
    float Pi = 3.1415926535;
    return (Pi*pow(diameter, 2))/4;
}
int main()
{
    // circle area through diameter
    short int diameter;

    cout << "Enter the diameter: ";
        cin >> diameter;

    cout << "The circle area: " << CricleThDia(diameter) << endl;
    return 0;
}
