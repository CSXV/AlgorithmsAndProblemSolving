#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    short int A, B;
    cout << "Enter A: ";
        cin >> A;
    cout << "Enter B: ";
        cin >> B;
    cout << "The rectangle area: " << A*sqrt(pow(B, 2)-pow(A, 2)) << endl;
   //
    return 0;
}
