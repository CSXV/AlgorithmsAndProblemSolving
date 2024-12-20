#include <iostream>
using namespace std;

int main()
{
    // circle area through diameter
    short int diameter;
    float Pi = 3.1415926535;

    cout << "Enter the diameter: ";
        cin >> diameter;

    float up = Pi*diameter*diameter;

    cout << "The circle area: " << up/4 << endl;
    return 0;
}
