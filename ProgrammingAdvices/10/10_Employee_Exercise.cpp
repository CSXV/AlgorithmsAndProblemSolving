#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

class clsEmployee {
private:
  string _FirstName;
  string _LastName;
  string _Email;
  string _Phone;
  string _Title;
  short _ID;
  string _Department;
  short _Salary;

public:
  clsEmployee(short id, string firstname, string lastname, string email,
              string phone, string title, short salary, string department) {
    _ID = id;
    _FirstName = firstname;
    _LastName = lastname;
    _Email = email;
    _Phone = phone;
    _Title = title;
    _Salary = salary;
    _Department = department;
  }
  // Read Only property.
  int ID() { return _ID; }

  void SetFirstName(string firstname) { _FirstName = firstname; }
  string FirstName() { return _FirstName; }

  void SetLastName(string lastname) { _LastName = lastname; }
  string LastName() { return _LastName; }

  string FullName() { return _FirstName + " " + _LastName; }

  void SetEmail(string email) { _Email = email; }
  string Email() { return _Email; }

  void SetPhone(string phone) { _Phone = phone; }
  string Phone() { return _Phone; }

  void SetSalar(short salary) { _Salary = salary; }
  short Salary() { return _Salary; }

  void SetDepartment(string department) { _Department = department; }
  string department() { return _Department; }

  void SetTitle(string title) { _Title = title; }
  string Title() { return _Title; }

  void PrintResluts() {
    cout << "\nInfo:\n";
    cout << "___________________\n";
    cout << "ID        : " << _ID << endl;
    cout << "First Name: " << _FirstName << endl;
    cout << "Last Name : " << _LastName << endl;
    cout << "Full Name : " << FullName() << endl;
    cout << "E-Mail    : " << _Email << endl;
    cout << "Phone     : " << _Phone << endl;
    cout << "Title     : " << _Title << endl;
    cout << "Salary    : " << _Salary << endl;
    cout << "department: " << _Department << endl;
    cout << "___________________\n";
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

int main() {
  clsEmployee person1(10, "Boo", "Foo", "BooFoo@gmail.com", "0777998866",
                      "Programmer", 5000, "IT");
  person1.PrintResluts();

  person1.SendEmail("Hi", "How are you?");
  person1.SendSMS("How are you?");

  signature();
  return 0;
}
