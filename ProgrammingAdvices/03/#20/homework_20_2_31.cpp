#include <iostream>
using namespace std;

int main()
{
// A number with power 2, 3 and 4

    short int A;
    cout << "Enter a number: ";
        cin >> A;

    short int power2 = A*A;
    short int power3 = power2*A;
    short int power4 = power3*A;

    cout << "A power of 2: " << power2 << endl;
    cout << "A power of 3: " << power3 << endl;
    cout << "A power of 4: " << power4 << endl;

    return 0;
}
