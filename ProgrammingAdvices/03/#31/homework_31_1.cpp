#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Enter a name
    string Name;
    cout << "please enter you name: ";
    getline(cin, Name);
    // Enter an age
    string Age;
    cout << "please enter you age: ";
    getline(cin, Age);
    // Enter an number
    string number;
    cout << "please enter number: ";
    getline(cin, number);
    // convert
    int newage = stoi(Age);
    int newnumber = stoi(number);
    string sum = Age+number;
    int newsum = newage*newnumber;
    // console out
    cout << "the length of your name is: " << Name.length() << endl;
    cout << "Characters at 0, 2, 4, 7 are: " << Name[0] << Name[2] << Name[4] << Name[7] << endl;
    cout << "Concatenating Age & Number: " << sum << endl;
    cout << Age << "*" << number << "= " << newsum << endl;

    return 0;
}
