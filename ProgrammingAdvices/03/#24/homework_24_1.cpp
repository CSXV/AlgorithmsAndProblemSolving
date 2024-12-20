#include <iostream>
using namespace std;

int main()
{
    short int A, B;

    cout << "Enter the first number A: ";
        cin >> A;
    cout << "Enter the second number B: ";
        cin >> B;

    cout << (A==B) << endl;
    cout << (A!=B) << endl;
    cout << (A>=B) << endl;
    cout << (A<=B) << endl;
    cout << (A<B) << endl;
    cout << (A>B) << endl;

    return 0;
}
