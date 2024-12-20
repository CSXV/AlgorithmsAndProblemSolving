#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// circle area described around an arbitrary triangle
    short int a, b, c;
    float Pi = 3.14159265358979323846;
    cout << "Enter A, B, C: ";
        cin >> a;
        cin >> b;
        cin >> c;

    float p = (a+b+c)/2;

    //float up = a*b*c;
    //float bottom = (4*sqrt(p*(p-a)*(p-b)*(p-c)));
    //float full = up/bottom;
    //float ohh = Pi*pow(full, 2);

    float ohh = Pi*pow(((a*b*c)/(4*sqrt(p*(p-a)*(p-b)*(p-c)))), 2);
    cout << "Cricle area: " << round(ohh) << endl;

    return 0;
}
