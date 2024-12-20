#include <iostream>
using namespace std;

int main()
{
    short int A=1, B=0;
    cout << (12>=12) << endl;
    cout << (12>7) << endl;
    cout << (8<6) << endl;
    cout << (8==8) << endl;
    cout << (12<=12) << endl;
    cout << (7==5) << endl;
    //
    cout << !(12>=12) << endl;
    cout << !(12>7) << endl;
    cout << !(8<6) << endl;
    cout << !(8==8) << endl;
    cout << !(12<=12) << endl;
    cout << !(7==5) << endl;
    //
    cout << (A&&A) << endl;
    cout << (A&&B) << endl;
    cout << (B||A) << endl;
    cout << (B||B) << endl;
    cout << !(B) << endl;
    cout << !(A||B) << endl;
    //
    cout << ((7==7)&&(7<5)) << endl;
    cout << ((7==7)&&(7>5)) << endl;
    cout << ((7==7)||(7<5)) << endl;
    cout << ((7<7)||(7>5)) << endl;
    cout << (!(7==7)||(7>5)) << endl;
    cout << ((7==7)&&!(7<5)) << endl;
    //
    return 0;
}
