#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// A number with power 2, 3 and 4

    short int A;
    cout << "Enter a number: ";
        cin >> A;

    short int power2 = pow(A, 2);
    short int power3 = pow(A, 3);
    short int power4 = pow(A, 4);

    cout << "A power of 2: " << round(power2) << endl;
    cout << "A power of 3: " << round(power3) << endl;
    cout << "A power of 4: " << round(power4) << endl;

    return 0;
}
