#include <iostream>
#include <cmath>
using namespace std;

float Duration(short int D, short int H, short int M, short int S)
{
    return  S+(M*60)+(H*pow(60, 2))+(D*pow(60, 2)*24);
}
int main()
{
// calculate task duration in seconds

    short int D, H, M, S;

    cout << "Enter: Days, Hours, Minutes, Seconds: ";
        cin >> D;
        cin >> H;
        cin >> M;
        cin >> S;

    cout << "Task duration in seconds is: " << Duration(D, H, M, S) << endl;
    return 0;
}
