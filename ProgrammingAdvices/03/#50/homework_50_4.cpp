#include <iostream>
using namespace std;

int main() {

    int N, sum=0, i=1;
    cout << "Enter an numebr: ";
        cin >> N;

    while(i <= N) {
        if(i%2==0) {
           sum +=i;
        }
        i++;
    }

    cout << sum << endl;
    return 0;
}
