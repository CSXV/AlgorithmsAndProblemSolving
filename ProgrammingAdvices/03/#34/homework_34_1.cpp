#include <iostream>
#include <cmath>
using namespace std;

// once with procudural
void SumPro()
{
    float No1, No2;
    cout << "please enter Number 1: ";
    cin >> No1;
    cout << "please enter Number 2: ";
    cin >> No2;

    float sum = No1+No2;
    cout << "*******************" << endl;
    cout << sum << endl;
}

// once with function
float SumFunc()
{
    float No1, No2;
    cout << "please enter Number 1: ";
    cin >> No1;
    cout << "please enter Number 2: ";
    cin >> No2;

    float sum = No1+No2;
    return sum;

}
// output
int main()
{
    SumPro();
    cout << "\n*******************\n" << endl;
    cout << SumFunc() << endl;
    return 0;
}
