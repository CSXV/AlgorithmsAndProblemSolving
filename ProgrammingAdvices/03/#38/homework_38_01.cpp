#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct StrInfo
{
    string FirstName;
    string LastName;
    int Age;
    string City;
    string Country;
    int MonthlySalary;
    int YearlySalary = MonthlySalary*12;
    char Gender;
    bool Married;
};

void ReadInfo(StrInfo &Info)
{
    cout << "Enter Your first name: ";
        cin >> Info.FirstName;
    cout << "Enter you last name: ";
        cin >> Info.LastName;
    cout << "Enter you Age: ";
        cin >> Info.Age;
    cout << "Enter your city: ";
        cin >> Info.City;
    cout << "Enter your Country: ";
        cin >> Info.Country;
    cout << "Enter you Monthly salary: ";
        cin >> Info.MonthlySalary;
    cout << "Enter you Gender: ";
        cin >> Info.Gender;
    cout << "Are you Married? ";
        cin >> Info.Married;
}

void PrintInfo(StrInfo Info)
{
    cout << "\n******************************\n";
    cout << "First Name: "<< Info.FirstName << endl;
    cout << "Last Name: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "city: " << Info.City << endl;
    cout << "Country: " << Info.Country << endl;
    cout << "Monthly Salary: " << Info.MonthlySalary << endl;
    cout << "Yearly Salary: " << Info.YearlySalary << endl;
    cout << "Gender: " << Info.Gender << endl;
    cout << "Married: " << Info.Married << endl;
    cout << "******************************\n";
}
int main()
{
    StrInfo Person1Info;
    ReadInfo(Person1Info);
    PrintInfo(Person1Info);

    return 0;
}
