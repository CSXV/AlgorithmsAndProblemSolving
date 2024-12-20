#include <iostream>
#include <cmath>
using namespace std;

float FullTime(int seconds)
{
    //int seconds;
    int SecPDay = 24*pow(60, 2);
    int SecPHou = pow(60, 2);
    int SecPMin = 60;
    float Remainder;

    int NumOfDays = seconds/SecPDay;
        Remainder = seconds%SecPDay;

    int NumOfHours = (Remainder/SecPHou);
        Remainder = seconds%SecPHou;

    int NumOfMinutes = (Remainder/SecPMin);
        Remainder = seconds%SecPMin;

    int NumOfSeconds = Remainder;

    return NumOfDays+NumOfHours+NumOfMinutes+NumOfSeconds;
}

int main()
{
// calculate full time with given number of seconds
    int seconds;
    cout << "Enter number of seconds: ";
        cin >> seconds;

    cout << "The number of seconds in full time: " << FullTime(seconds) << endl;
    //cout << "The number of seconds in full time: " << FullTime() << endl;
    // cout << "The number of seconds in full time: " << round(NumOfDays) << ":" << NumOfHours << ":" << NumOfMinutes << ":" << NumOfSeconds << endl;

    return 0;
}
