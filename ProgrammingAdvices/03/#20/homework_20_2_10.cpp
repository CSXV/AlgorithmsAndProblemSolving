#include <iostream>
using namespace std;

int main()
{
    short int mark1, mark2, mark3;

    cout << "Enter the first mark: " << endl;
    cin >> mark1;
    cout << "Enter the second mark: " << endl;
    cin >> mark2;
    cout << "Enter the third mark: " << endl;
    cin >> mark3;
    int sum = mark1+mark2+mark3;
    cout << "The avarage of three marks is: " << sum/3 << endl;
    return 0;
}
