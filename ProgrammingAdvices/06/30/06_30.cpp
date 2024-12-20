#include <iostream>
#include <vector>
using namespace std;
// Read as many Employees as the user want< each time an employee enterd add it
// to a vector, and then ask if the user want to add more until saied no, the
// print all vector elemnts.

void signature() {
  cout << "\n\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

struct stEmployee {
  string FirstName;
  string LastName;
  float salary;
};
int readnumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

string readString(string message) {
  string S;
  cout << message;
  cin >> S;
  return S;
}

void Fillvector(vector<stEmployee> &vEmployees) {
  stEmployee TempEmployee;
  char q = 'y';

  while (q == 'y' || q == 'Y') {
    TempEmployee.FirstName = readString("Please enter the first name: ");
    TempEmployee.LastName = readString("Please enter the last name : ");
    TempEmployee.salary = readnumber("Please enter the salary    : ");
    vEmployees.push_back(TempEmployee);

    cout << "\nDo you want to add more employees? (y/n): ";
    cin >> q;
    cout << endl;
  }
}

void PrintVector(vector<stEmployee> &vEmployees) {
  cout << "\nEmployees vector:\n";

  for (stEmployee &Employee : vEmployees) {
    cout << "First Name: " << Employee.FirstName << endl;
    cout << "Last Name : " << Employee.LastName << endl;
    cout << "Salary    : " << Employee.salary << endl;
    cout << endl;
  }
}

int main() {
  vector<stEmployee> vEmployees;

  Fillvector(vEmployees);
  PrintVector(vEmployees);

  signature();
  return 0;
}
