#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

class clsPerson {
private:
  string _FirstName;
  string _LastName;
  string _Email;
  string _Phone;
  short _ID;

public:
  clsPerson(short id, string firstname, string lastname, string email,
            string phone) {
    _ID = id;
    _FirstName = firstname;
    _LastName = lastname;
    _Email = email;
    _Phone = phone;
  }

  short ID() { return _ID; }

  void SetFirstName(string firstname) { _FirstName = firstname; }
  string FirstName() { return _FirstName; }

  void SetLastName(string lastname) { _LastName = lastname; }
  string LastName() { return _LastName; }

  string FullName() { return _FirstName + " " + _LastName; }

  void SetEmail(string email) { _Email = email; }
  string Email() { return _Email; }

  void SetPhone(string phone) { _Phone = phone; }
  string Phone() { return _Phone; }

  void PrintResluts() {
    cout << "\nInfo:\n";
    cout << "___________________\n";
    cout << "ID        : " << _ID << endl;
    cout << "First Name: " << _FirstName << endl;
    cout << "Last Name : " << _LastName << endl;
    cout << "Full Name : " << FullName() << endl;
    cout << "E-Mail    : " << _Email << endl;
    cout << "Phone     : " << _Phone << endl;
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
  clsPerson person1(10, "Boo", "Foo", "BooFoo@gmail.com", "0777998866");
  person1.PrintResluts();

  person1.SendEmail("Hi", "How are you?");
  person1.SendSMS("How are you?");

  signature();
  return 0;
}
