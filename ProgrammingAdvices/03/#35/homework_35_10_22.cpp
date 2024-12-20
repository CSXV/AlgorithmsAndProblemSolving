#include <iostream>
#include <cmath>
using namespace std;

float CirlcleInscIsoTri(float a, float b)
{
    float Pi = 3.1415926535;
    return (Pi*pow(b, 2)/4)*((2*a-b)/(2*a+b));

}
int main()
{
// circle area inscribed in an isosceles triangle
    float a;
    float b; // The base

    cout << "Enter A: ";
        cin >> a;
    cout << "Enter B: ";
        cin >> b;

    cout << "Circle Area: " << CirlcleInscIsoTri(a, b) << endl;
    return 0;
}
