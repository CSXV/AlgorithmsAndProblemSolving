#include <iostream>
using namespace std;

// Find factorial of N.
int main()
{
    int N, c, F=1;
    cout << "Enter an Number: ";
        cin >> N;

    for (c=1; c<=N; c++)
    {
        F=F*c;
    }

    cout << F << endl;
    return 0;
}
