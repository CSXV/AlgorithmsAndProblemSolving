#include<iostream>

using namespace std;

int main()
{
    int Mark;
    cout << "enter your mark: ";
        cin >> Mark;

    if (Mark >= 50)
    {
        cout << "passed" << endl;
    }
    else
    {
        cout << "faild" << endl;
    }
    return 0;
}
