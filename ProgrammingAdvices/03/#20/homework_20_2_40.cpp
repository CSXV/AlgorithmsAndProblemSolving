#include <iostream>
using namespace std;

int main()
{
// calculate a bill with tax and service fee
    short int Bvalue;

    cout << "Enter Bill Value: ";
        cin >> Bvalue;
    float totalbill = Bvalue*1.10;
    float totalbill2 = totalbill*1.16;
    cout << "The total bill is: " << totalbill2 << endl;
    return 0;
}
