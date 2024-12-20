#include <iostream>
#include <cmath>
using namespace std;

float CircleArea(short int R)
{
    float Pi = 3.14159265358979323846;
    return (pow(R, 2)*Pi);
}
int main()
{
// calculate circle area
    short int R;

    cout << "Enter Radius: ";
        cin >> R;
    cout << "Circle area: " << CircleArea(R) << endl;

    return 0;
}
