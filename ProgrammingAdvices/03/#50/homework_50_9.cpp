#include <iostream>
using namespace std;

// Enter [PIN], if correct: output [balance], if wrong: output [while] for the number of [TIME], then output [if].
int main() {

    int pin, pass=1234, balance=7500, time=3, i=1;
    cout << "Enter the PIN: ";
    cin >> pin;

    while(pin != pass && i < time) {
        cout << "Wrong PIN, Number of tries left: (" << 3-i << ").\nEnter the correct PIN: ";
        i++;
        cin >> pin;

        if(i >= time && pin != pass) {
            cout << "Number of tries excided, Card is locked." << endl;
        }
    }

    if(pin == pass) {
        cout << "You Balance is: " <<"("<<balance<<")"<< endl;
    }

    return 0;
}
