#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Input an number, and output the grade.
    int grade;
    cout << "Enter your grade: ";
        cin >> grade;

    if(grade <= 100 && grade >= 90)
    {
        cout << "A" << endl;
    }
    else if(grade <= 89 && grade >= 80)
    {
        cout << "B" << endl;
    }
    else if(grade <= 79 && grade >= 70)
    {
        cout << "C" << endl;
    }
    else if(grade <= 69 && grade >= 60)
    {
        cout << "D" << endl;
    }
    else if(grade <= 59 && grade >= 50)
    {
        cout << "E" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
    return 0;
}
