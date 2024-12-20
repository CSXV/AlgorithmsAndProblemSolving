#include <iostream>
#include <cmath>
using namespace std;

float NoPowNo(short int No, short int M)
{
    return pow(No, M);
}
int main()
{
// Number to the power of another number
    int No, M;

    cout << "Enter The Number, To the power of M: ";
        cin >> No;
        cin >> M;

    cout << "The Number to the power of M is: " << NoPowNo(No, M) << endl;

    return 0;
}
