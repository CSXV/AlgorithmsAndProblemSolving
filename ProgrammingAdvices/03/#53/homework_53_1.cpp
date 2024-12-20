#include <iostream>
#include <ostream>
#include <string>
using namespace std;

// Calculate the sum of 5 numbers that are smaller than 50.
int main() {
    int N, sum=0;

    for(int i=1; i<=5; i++) {
        cout << "Enter an number: ";
            cin >> N;
        //
        if(N > 50) {
            cout << "the number is >50" << endl;
            continue;
            }
        //
        sum += N;
        }

        cout << sum << endl;
    return 0;
}
