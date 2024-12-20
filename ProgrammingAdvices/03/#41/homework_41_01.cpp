#include <iostream>
#include <string>
using namespace std;

struct strInfo
{
    string firstname;
    string lastname;
    int age;
    string phone;
};
void readInfo(strInfo& Info)
{
    cout << "enter first name: ";
        cin >> Info.firstname;
    cout << "enter last name: ";
        cin >> Info.lastname;
    cout << "enter age: ";
        cin >> Info.age;
    cout << "enter phone number: ";
        cin >> Info.phone;
}
void printInfo(strInfo& Info)
{
    cout << "************************\n";
    cout << "First name: " << Info.firstname << endl;
    cout << "Last name: " << Info.lastname << endl;
    cout << "Age: " << Info.age << endl;
    cout << "Phone: " << Info.phone << endl;
    cout << "************************\n";
}
void readpersoninfo(strInfo person[2])
{
    readInfo(person[0]);
    readInfo(person[1]);
}
void printpersoninfo(strInfo person[2])
{
    printInfo(person[0]);
    printInfo(person[1]);
}
int main()
{
    strInfo person[2];
    readpersoninfo(person);
    printpersoninfo(person);
    return 0;
}
