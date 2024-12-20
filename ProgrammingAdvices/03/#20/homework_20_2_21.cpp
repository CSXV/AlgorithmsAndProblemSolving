#include <iostream>
using namespace std;

int main()
{
    // circle area along the circumference
    short int a;
    float Pi = 3.1415926535;

    cout << "Enter circle circumference: " ;
        cin >> a;

    float area = (a*a)/(4*Pi);
    cout << "The circle area: " << area << endl;
    return 0;
}
