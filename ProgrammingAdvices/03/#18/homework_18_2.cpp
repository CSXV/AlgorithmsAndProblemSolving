#include <iostream>
using namespace std;

int main()
{
    int NO1 =20, NO2 =30, NO3=10;

    cout << "Enter the 1st number: ";
    cin >> NO1;
    cout << "Enter the 2nd number: ";
    cin >> NO2;
    cout << "Enter the 3rd number: ";
    cin >> NO3;

    int sum = NO1+NO2+NO3;

    cout << NO1 << "+\n" << NO2 << "+\n" << NO3 << endl;
    cout << "________________\n";
    cout << "Total = " << sum << endl;
    return 0;
}
