#include <iostream>
#include <string>
using namespace std;

int main()
{
    int Day;
    cout << "Enter Day Number: ";
        cin >> Day;

    switch (Day)
    {
    case 1:
        cout << "Sunday";
        break;
    case 2:
        cout << "Monday";
        break;
    case 3:
        cout << "Tuesday";
        break;
    case 4:
        cout << "Wednesday";
        break;
    case 5:
        cout << "Thursday";
        break;
    case 6:
        cout << "Friday";
        break;
    case 7:
        cout << "Saturday";
        break;
    default:
        cout << "Wrong Day number";
    }
    return 0;
}
