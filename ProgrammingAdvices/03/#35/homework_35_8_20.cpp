#include <iostream>
#include <cmath>
using namespace std;

float CircleInsSqu(short int square)
{
    float Pi = 3.1415926535;
    return (Pi*pow(square, 2))/4;
}
int main()
{
// circle area inscribed in a square

    short int square;

    cout << "Enter square: ";
        cin >> square;

    cout << "The circle area: " << CircleInsSqu(square) << endl;
    return 0;
}
