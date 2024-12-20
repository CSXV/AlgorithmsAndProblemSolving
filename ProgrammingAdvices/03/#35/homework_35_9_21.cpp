#include <iostream>
#include <cmath>
using namespace std;

float CircleAlongCircum(short int a)
{
    float Pi = 3.1415926535;
    return pow(a, 2)/(4*Pi);
}
int main()
{
    // circle area along the circumference
    short int a;

    cout << "Enter circle circumference: " ;
        cin >> a;

    cout << "The circle area: " << CircleAlongCircum(a) << endl;
    return 0;
}
