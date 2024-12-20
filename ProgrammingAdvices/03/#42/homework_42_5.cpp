#include<iostream>
using namespace std;

int main()
{
    int PIN=1234;
    int PINe;
    int Balance = 7500;
    cout << "enter your PIN: ";
        cin >> PINe;

    if(PINe == PIN)
    {
        cout << "Your Balance: " << Balance << endl;
    }
    else
    {
        cout << "you entered wrong PIN" << endl;
    }
    return 0;
}
