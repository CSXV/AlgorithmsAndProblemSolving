#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

class clsPerson {
private:
  short _ID;
  string _FirstName;
  string _LastName;
  string _Email;
  string _Phone;

public:
  clsPerson(short id, string firstname, string lastname, string email,
            string phone) {
    _ID = id;
    _FirstName = firstname;
    _LastName = lastname;
    _Email = email;
    _Phone = phone;
  }
  // Read Only property.
  int ID() { return _ID; }

  void SetFirstName(string firstname) { _FirstName = firstname; }
  string FirstName() { return _FirstName; }

  void SetLastName(string lastname) { _LastName = lastname; }
  string LastName() { return _LastName; }

  string FullName() { return _FirstName + " " + _LastName; }

  void PrintResluts() {
    cout << "\nInfo:\n";
    cout << "___________________\n";
    cout << "ID        : " << _ID << endl;
    cout << "First Name: " << _FirstName << endl;
    cout << "Last Name : " << _LastName << endl;
    cout << "Full Name : " << FullName() << endl;
    cout << "E-Mail    : " << _Email << endl;
    cout << "Phone     : " << _Phone << endl;
  }

  void SendEmail(string subject, string body) {
    cout << "\nThe following message sent successfully to email: " << _Email;
    cout << "\nSubject: " << subject;
    cout << "\nBody: " << body << endl;
  }

  void SendSMS(string S) {
    cout << "\nThe following SMS setn successfully to phone: " << _Phone;
    cout << "\n" << S << endl;
  }
};

class clsEmployee : public clsPerson {
private:
  string _Title;
  string _Department;
  short _Salary;

public:
  clsEmployee(short id, string firstname, string lastname, string email,
              string phone, string title, short salary, string department)
      : clsPerson(id, firstname, lastname, email, phone) {
    _Title = title;
    _Department = department;
    _Salary = salary;
  }

  void SetSalary(short salary) { _Salary = salary; }
  short Salary() { return _Salary; }

  void SetDepartment(string department) { _Department = department; }
  string department() { return _Department; }

  void SetTitle(string title) { _Title = title; }
  string Title() { return _Title; }

  void PrintResluts() {
    clsPerson::PrintResluts();

    cout << "Title     : " << _Title << endl;
    cout << "Salary    : " << _Salary << endl;
    cout << "Department: " << _Department << endl;
  }
};

class clsDeveloper : public clsEmployee {
private:
  string _MainProgrammingLanguage;

public:
  clsDeveloper(short id, string firstname, string lastname, string email,
               string phone, string title, short salary, string department,
               string mainprogramminglanguage)
      : clsEmployee(id, firstname, lastname, email, phone, title, salary,
                    department) {
    _MainProgrammingLanguage = mainprogramminglanguage;
  }

  void SetPRogrammingLanguage(string mainprogramminglanguage) {
    _MainProgrammingLanguage = mainprogramminglanguage;
  }
  string MainProgrammingLanguage() { return _MainProgrammingLanguage; }

  void PrintResluts() {
    clsPerson::PrintResluts();
    cout << "Main PL   : " << _MainProgrammingLanguage << endl;
    cout << "___________________\n";
  }
};

int main() {
  clsDeveloper developer1(10, "Boo", "Foo", "BooFoo@gmail.com", "0777998866",
                          "CEO", 5000, "SCX", "C++");
  developer1.PrintResluts();

  signature();
  return 0;
}
