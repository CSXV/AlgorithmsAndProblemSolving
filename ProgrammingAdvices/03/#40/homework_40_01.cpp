#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void ReadGradesData(float x[3])
{
    cout << "enter number 1: ";
        cin >> x[0];
   cout << "enter number 2: ";
        cin >> x[1];
   cout << "enter number 3: ";
        cin >> x[2];
}

float AVE(float x[3])
{
    return (x[0] + x[1] + x[2]) / 3;
};

int main()
{
    float x[3];

    ReadGradesData(x);

    cout << "***************\n";
    cout << "the average of grades is: " << AVE(x) << endl;
    cout << "***************\n";
    return 0;
}
