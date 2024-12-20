#include <iostream>
using namespace std;

int main()
{
// calculate full time with given number of seconds
    int seconds;
    int SecPDay = 24*60*60;
    int SecPHou = 60*60;
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

    cout << "The number of seconds in full time: " << NumOfDays << ":" << NumOfHours << ":" << NumOfMinutes << ":" << NumOfSeconds << endl;

    return 0;
}
