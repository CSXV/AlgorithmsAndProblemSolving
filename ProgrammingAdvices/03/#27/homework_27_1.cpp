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
    char gender;
    bool married;
};

int main()
{
    person Malik;
    Malik.address.city = "Amman";
    Malik.address.country = "Jordan";
    Malik.age = 22;
    Malik.gender = 'M';
    Malik.married = 0;
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
    cout << "gender: " << Malik.gender << endl;
    cout << "married: " << Malik.married << endl;
    cout << "*********************" << endl;

    return 0;
}
