#include <iostream>
#include <string>
using namespace std;
//
//
struct strInfo
{
    string firstname;
    string lastname;
    int age;
    string phone;
};
//
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
//
void printInfo(strInfo& Info)
{
    cout << "************************\n";
    cout << "First name: " << Info.firstname << endl;
    cout << "Last name: " << Info.lastname << endl;
    cout << "Age: " << Info.age << endl;
    cout << "Phone: " << Info.phone << endl;
    cout << "************************\n";
}
//
void readpersoninfo(strInfo person[100], int& range)
{
    cout << "how many persons? ";
    cin >> range;

    for(int i=0; i<=range-1; i++)
        {
        cout << "enter person's " <<"("<<i+1<<")"<< " info: \n";
        readInfo(person[i]);
        }
}
//
void printpersoninfo(strInfo person[100], int range)
{
    for(int i=0; i <= range-1; i++)
    {
        cout << "person's "<<"("<< i+1 <<")"<< " info: \n\n";
        printInfo(person[i]);
    }
}
//
//
int main()
{
    strInfo person[100];
    int range = 1;

    readpersoninfo(person, range);
    printpersoninfo(person, range);

    return 0;
}
//
