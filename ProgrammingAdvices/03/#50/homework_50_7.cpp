#include <iostream>
using namespace std;

//Enter numbers until -99, then sum the inputs.
int main() {
    int N, sum=0;

    while(N != -99) {
    cout << "Enter an Number: ";
        cin >> N;
    sum =sum+N;
    }

    sum= sum+99;
    cout << sum << endl;

    return 0;
}
