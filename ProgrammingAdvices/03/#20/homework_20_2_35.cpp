#include <iostream>
using namespace std;

int main()
{
    short int Pennies;
    short int Nickels;
    short int Dimes;
    short int Quarters;
    short int Dollars;

    cout << "Enter: Pennys, Nickels, Dimes, Quarters & Dollares: ";
        cin >> Pennies;
        cin >> Nickels;
        cin >> Dimes;
        cin >> Quarters;
        cin >> Dollars;

    float TotalPennies = Pennies+(Nickels*5)+(Dimes*10)+(Quarters*25)+(Dollars*100);
    float TotalDollars = TotalPennies/100;

    cout << "The total Pennies: " << TotalPennies << endl;
    cout << "The total Dollars: " << TotalDollars << endl;
    return 0;
}
