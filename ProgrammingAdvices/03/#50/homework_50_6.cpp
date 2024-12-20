#include <iostream>
using namespace std;

int main() {

    int M, N, i=1, p=1;
    cout << "Enter an numebr: ";
        cin >> N;
    cout << "Enter a power: ";
        cin >> M;

    while(i <= M) {
        p = p*N;
        i++;
    }
    cout << p << endl;
    return 0;
}
