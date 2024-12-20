#include <iostream>
using namespace std;

//Calculate N to the power M.
int main()
{
    int N, M, c, p=1;
    cout << "Enter An Number: ";
        cin >> N;
    cout << "Enter a Power: ";
        cin >> M;

    for(c=1; c<=M; c++)
    {
        p=p*N;
    }
    cout << p << endl;
    return 0;
}
