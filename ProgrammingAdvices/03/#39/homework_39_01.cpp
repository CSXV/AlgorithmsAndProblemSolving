#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    float x[3];
    cout << "Please enter grade 1: ";
        cin >> x[0];
    cout << "Please enter grade 2: ";
        cin >> x[1];
    cout << "Please enter grade 3: ";
        cin >> x[2];

    float avg = (x[0]+x[1]+x[2]) / 3;

    cout << "\n**********************\n";
    cout << "The avarage of grades is: " << avg << endl;

    return 0;
}
