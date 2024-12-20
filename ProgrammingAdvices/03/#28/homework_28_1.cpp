#include <iostream>
using namespace std;

struct pAddress
{
    string city;
    string country;
};

struct pSalary
{
    int monthly;
    int yearly;
};

struct person
{
    pAddress address;
    pSalary salary;
    string name;
    int age;
};
enum gender {Male, Female};
enum status {single, Married};
enum color {Green, Black, Red};

int main()
{
    person Malik;
    gender MyGender;
    status MyStatus;
    color MyColor;

    Malik.address.city = "Amman";
    Malik.address.country = "Jordan";
    Malik.age = 22;
    MyGender = gender::Male;
    MyStatus = status::single;
    MyColor = color::Black;
    Malik.name = "Malik Al-Sharif";
    Malik.salary.monthly = 500;
    Malik.salary.yearly = Malik.salary.monthly*12;

    cout << "*********************" << endl;
    cout << "Name: " << Malik.name << endl;
    cout << "Age: " << Malik.age << endl;
    cout << "city: " << Malik.address.city << endl;
    cout << "country: " << Malik.address.country << endl;
    cout << "monthly salary: " << Malik.salary.monthly << endl;
    cout << "yearly salary: " << Malik.salary.yearly << endl;
    cout << "gender: " << MyGender << endl;
    cout << "married: " << MyStatus << endl;
    cout << "My Favorate colour is: " << MyColor << endl;

    cout << "*********************" << endl;

    return 0;
}
