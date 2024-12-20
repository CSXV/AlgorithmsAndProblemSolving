#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// calculate circle area
    short int R;
    float Pi = 3.14159265358979323846;

    cout << "Enter Radius: ";
        cin >> R;
    cout << "Circle area: " << ceil(pow(R, 2)*Pi) << endl;

    return 0;
}
