#include <iostream>
using namespace std;

// Sum all the odd numbers from 01 to N.
int main()
{
    int N, c, sum=0; //"c" for: Counter.
    cout << "Enter An Number: " << endl;
        cin >> N;

    for (c=1; c <=N; c++)
    {
        if (c%2!=0)
        {
            sum += c;
        }
    }

    cout << sum << endl;
    return 0;
}
