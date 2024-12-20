#include <iostream>
using namespace std;

int main()
{
    string name;
    int age;
    string city;
    string country;
    int MonthlySalary;
    int YearlySalary = MonthlySalary*12;
    char gender;
    bool Ismarried;

    cout << "enter your name: ";
    cin >> name;
    cout << "enter your age: ";
    cin >> age;
    cout << "enter you city: ";
    cin >> city;
    cout << "enter  you country: ";
    cin >> country;
    cout << "enter you monthly salary:";
    cin MonthlySalary;
    cin YearlySalary;
    cout << "enter your gender M for male & F for female";
    cin gender;
    cout << "are you married?";
    cin Ismarried;


    cout << "*********************" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
    cout << "Monthly Salary: " << MonthlySalary << endl;
    cout << "Yearly Salary: " << YearlySalary << endl;
    cout << "Gender: " << gender << endl;
    cout << "Is Married: " << Ismarried << endl;
    cout << "********************" << endl;

return 0;
}
