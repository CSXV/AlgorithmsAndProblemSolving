#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // circle area through diameter
    short int diameter;
    float Pi = 3.1415926535;

    cout << "Enter the diameter: ";
        cin >> diameter;

    float up = (Pi*pow(diameter, 2))/4;

    cout << "The circle area: " << ceil(up) << endl;
    return 0;
}
