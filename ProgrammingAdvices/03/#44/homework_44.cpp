#include <iostream>
#include <ostream>
#include <string>
using namespace std;

enum countrylist{Jordan=1, UAE=2, SaudiaArabia=3, Seria=4, Oman=5, Egypt=6, Lebanon=7};

int main()
{
    cout << "***************************************\n";
    cout << "Please enter your country number: \n";
    cout << "(1) Jordan\n(2) UAE\n(3) Saudia Arabia\n(4) Seria\n(5) Oman\n(6) Egypt\n(7) Lebanon\n";
    cout << "***************************************\n";
    cout << "Your Choise: ";

    int c;
    countrylist Country;
    cin >> c;

    Country = (countrylist)c;

    if(Country == countrylist::Jordan)
    {
        cout << "You are from jordan" << endl;
    }
    else if(Country == countrylist::UAE)
    {
        cout << "You are from UAE" << endl;
    }
    else if(Country == countrylist::SaudiaArabia)
    {
        cout << "You are from Saudia Arabia" << endl;
    }
    else if(Country == countrylist::Seria)
    {
        cout << "You are from Seria" << endl;
    }
    else if(Country == countrylist::Oman)
    {
        cout << "You are from Oman" << endl;
    }
    else if(Country == countrylist::Egypt)
    {
        cout << "You are from Egypt" << endl;
    }
    else if(Country == countrylist::Lebanon)
    {
        cout << "You are from Lebanon" << endl;
    }
    else
    {
        cout << "you are from other countries" << endl;
    }

    return 0;
}
