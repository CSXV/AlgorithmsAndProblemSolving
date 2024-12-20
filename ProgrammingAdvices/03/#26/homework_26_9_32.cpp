#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// Number to the power of another number
    int No, M;

    cout << "Enter The Number, To the power of M: ";
        cin >> No;
        cin >> M;

    cout << "The Number to the power of M is: " << round(pow(No, M)) << endl;

    return 0;
}
