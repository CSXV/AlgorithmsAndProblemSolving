#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string Nname(string names)
{
    return names;
}
int main()
{
    string names;
    cout << "Enter your name: ";
        cin >> names;
    cout << "*************" << endl;
    cout << Nname(names) << endl;
    return 0;
}
