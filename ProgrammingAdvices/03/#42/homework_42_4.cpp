#include<iostream>
using namespace std;

int main()
{
    int Age;
    cout << "enter your age: ";
        cin >> Age;

    if (Age >= 18 && Age <= 45)
    {
        cout << "passed" << endl;
    }
    else
    {
        cout << "faild" << endl;
    }

    return 0;
}
