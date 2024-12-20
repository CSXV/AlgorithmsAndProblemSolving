#include <iostream>
using namespace std;

int main()
{
// circle area inscribed in an isosceles triangle
    float Pi = 3.1415926535;
    float a;
    float b; // The base

    cout << "Enter A: ";
        cin >> a;
    cout << "Enter B: ";
        cin >> b;

    float area = (Pi*b*b/4)*((2*a-b)/(2*a+b));

    cout << "Circle Area: " << area << endl;
    return 0;
}
