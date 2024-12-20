#include <iostream>
#include <string>
using namespace std;

int main()
{
    int age;
    bool DL;
    cout << "enter you age: ";
        cin >> age;
    cout << "Do you have a driver license? ";
        cin >> DL;

    if (age < 18 && DL == false)
    {
        cout << "You were rejected" << endl;
    }
    else
    {
        cout << "you were hired" << endl;
    }

    return 0;
}
