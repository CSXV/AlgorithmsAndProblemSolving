#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// circle area inscribed in a square

    short int square;
    float Pi = 3.1415926535;

    cout << "Enter square: ";
        cin >> square;

    float area = (Pi*pow(square, 2))/4;

    cout << "The circle area: " << ceil(area) << endl;
    return 0;
}
