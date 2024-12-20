#include <iostream>
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

    float total = S+(M*60)+(H*60*60)+(D*60*60*24);

    cout << "Task duration in seconds is: " << total << endl;
    return 0;
}
