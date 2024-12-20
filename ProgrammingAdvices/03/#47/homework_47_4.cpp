#include <iostream>
using namespace std;

// Sum for all the even numbers form 01 to N.
int main()
{
    int N, C, sum=0;
    cout << "Enter An Number: ";
        cin >> N;

    for (C=1; C<=N; C++)
    {
        if(C%2==0)
        {
            sum +=C;
        }
    }
    cout << "The sum for all even numbers is: " << sum << endl;
    return 0;
}
