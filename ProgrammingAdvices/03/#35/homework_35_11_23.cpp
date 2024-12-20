#include <iostream>
#include <cmath>
using namespace std;

float CircleDescArbiTri(float a, float b, float c)
{
    float Pi = 3.14159265358979323846;
    float p = (a+b+c)/2;
    return Pi*pow(((a*b*c)/(4*sqrt(p*(p-a)*(p-b)*(p-c)))), 2);

}
int main()
{
// circle area described around an arbitrary triangle
    short int a, b, c;
    cout << "Enter A, B, C: ";
        cin >> a;
        cin >> b;
        cin >> c;

    cout << "Cricle area: " << CircleDescArbiTri(a, b ,c) << endl;

    return 0;
}
