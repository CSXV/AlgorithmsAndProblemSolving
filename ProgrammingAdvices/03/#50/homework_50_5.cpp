#include <iostream>
using namespace std;

int main() {

    int N, c=1, F=1;
    cout << "Enter an number: ";
    cin >> N;

    while(N <= 0) {
        cout << "Please enter a positive number: ";
        cin >> N;
    }
    while(c <= N) {
        F = F*c;
        c++;
        }

    cout << F << endl;
    return 0;
}
