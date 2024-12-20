#include <iostream>
using namespace std;

int main()
{
    short int A=1, B=0;
    cout << ((5>6&&7==7)||(A||B)) << endl;
    cout << !((5>6&&7==7)||(A||B)) << endl;
    cout << !((5>6&&7==7)||!(A||B)) << endl;
    cout << !((5>6&&7==7)&&!(A||B)) << endl;
    cout << (((5>6&&7<=8)||(8>A&&4<=3))&&A) << endl;
    cout << (((5>6&&!(7<=8))||(8>A||4<=3))||A) << endl;
   //
    return 0;
}
