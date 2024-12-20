#include <iostream>
using namespace std;

int main() {
    int number, i=1;
    cout << "Enter an number: ";
    cin >> number;

    while(number >= i)
    {
        cout << number << endl;
        number--;
    }
    return 0;
}
