#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// calculate full time with given number of seconds
    int seconds;
    int SecPDay = 24*pow(60, 2);
    int SecPHou = pow(60, 2);
    int SecPMin = 60;
    float Remainder;

    cout << "Enter number of seconds: ";
        cin >> seconds;

    int NumOfDays = seconds/SecPDay;
        Remainder = seconds%SecPDay;

    int NumOfHours = (Remainder/SecPHou);
        Remainder = seconds%SecPHou;

    int NumOfMinutes = (Remainder/SecPMin);
        Remainder = seconds%SecPMin;

    int NumOfSeconds = Remainder;

    cout << "The number of seconds in full time: " << round(NumOfDays) << ":" << NumOfHours << ":" << NumOfMinutes << ":" << NumOfSeconds << endl;

    return 0;
}
