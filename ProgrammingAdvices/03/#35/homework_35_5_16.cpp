#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// rectangle area:

float RectangleArea(int A,int B)
{
    return A*sqrt(pow(B, 2)-pow(A, 2));
}

int main()
{
    int A, B;
    cout << "Enter A: ";
        cin >> A;
    cout << "Enter B: ";
        cin >> B;
    //
    cout << RectangleArea(A, B) << endl;
    //
    return 0;
}
