#include <iostream>
using namespace std;

int main()
{
    cout << "Enter your age: ";
    int myage;
    cin >> myage;
    int newage = myage+5;

    cout << "after 5 years you will be " << newage << " years old" << endl;
    return 0;
}
