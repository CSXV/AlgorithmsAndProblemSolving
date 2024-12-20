#include <iostream>
#include <cmath>
using namespace std;

int main()
{
// calculate task duration in seconds

    short int D, H, M, S;

    cout << "Enter: Days, Hours, Minutes, Seconds: ";
        cin >> D;
        cin >> H;
        cin >> M;
        cin >> S;

    float total = S+(M*60)+(H*pow(60, 2))+(D*pow(60, 2)*24);

    cout << "Task duration in seconds is: " << round(total) << endl;
    return 0;
}
