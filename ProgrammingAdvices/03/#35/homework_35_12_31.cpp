#include <iostream>
#include <cmath>
using namespace std;

int Power2(short int A)
{
    return pow(A, 2);
}
int Power3(short int A)
{
    return pow(A, 3);
}
int Power4(short int A)
{
    return pow(A, 4);
}
int main()
{
// A number with power 2, 3 and 4

    short int A;
    cout << "Enter a number: ";
        cin >> A;

    cout << "A power of 2: " << Power2(A) << endl;
    cout << "A power of 3: " << Power3(A) << endl;
    cout << "A power of 4: " << Power4(A) << endl;

    return 0;
}
