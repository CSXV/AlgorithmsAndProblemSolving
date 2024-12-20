#include <iostream>
#include <string>
using namespace std;

int main()
{
    int TotalSalary;
    cout << "Enter your salary: ";
        cin >> TotalSalary;

    if(TotalSalary >= 1000000)
    {
        cout << "Percentage Is: 01%" << endl;
    }
    else if(TotalSalary <= 1000000 && TotalSalary >= 500000)
    {
        cout << "Percentage Is: 02%" << endl;
    }
    else if(TotalSalary <= 500000 && TotalSalary >= 100000)
    {
        cout << "Percentage Is: 03%" << endl;
    }
    else if(TotalSalary <= 100000 && TotalSalary >= 50000)
    {
        cout << "Percentage Is: 05%" << endl;
    }
    else
    {
        cout << "Percentage Is: 00%" << endl;
    }
    return 0;
}
