#include<iostream>

using namespace std;

int main()
{
    int Average[2];
    cout << "enter mark 01: ";
        cin >> Average[0];
    cout << "enter mark 02: ";
        cin >> Average[1];
    cout << "enter mark 03: ";
        cin >> Average[2];

    int Ave = (Average[0]+Average[1]+Average[2])/3;

    if (Ave >= 50)
    {
        cout << "passed" << endl;
    }
    else
    {
        cout << "faild" << endl;
    }
    return 0;
}
