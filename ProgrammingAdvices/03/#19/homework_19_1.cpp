#include <iostream>
using namespace std;

int main()
{
    string name;
    short int age;
    string city;
    string country;
    short int MonthlySalary;
    char gender;
    bool Ismarried;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter you city: ";
    cin >> city;
    cout << "Enter you country: ";
    cin >> country;
    cout << "Enter you monthly salary: ";
    cin >> MonthlySalary;
    cout << "Enter your gender, (M=male|F=female): ";
    cin >> gender;
    cout << "Are you married?, (Trure|False): ";
    cin >> Ismarried;

    int YearlySalary = (12*MonthlySalary);


    cout << "************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
    cout << "Monthly Salary: " << MonthlySalary << endl;
    cout << "Yearly Salary: " << YearlySalary << endl;
    cout << "Gender: " << gender << endl;
    cout << "Is Married: " << Ismarried << endl;
    cout << "***********************" << endl;

return 0;
}
