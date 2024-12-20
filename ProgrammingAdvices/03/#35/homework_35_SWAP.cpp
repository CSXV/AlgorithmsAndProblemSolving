#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Swap(int &A,int &B)
{
    int temp;

    temp=A;
    A=B;
    B=temp;

    cout << A << B << endl;
}
int main()
{
     int A, B;
     cout << "enter A: ";
        cin >> A;
    cout << "enter B: ";
        cin >> B;

     cout << "before swap, A=" << A << ", B=" << B << endl;
     Swap(A, B);
     cout << "after swap, A=" << A << ", B=" << B << endl;
    return 0;
}
