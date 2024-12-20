#include <iostream>
#include <ostream>
#include <string>
using namespace std;
//Print full name.
struct stInfo {
  string FirstName;
  string LastName;
};

stInfo ReadInfo() {
  stInfo Info; 
  cout << "Please enter your First name: ";
  cin >> Info.FirstName;
  cout << "Please enter you last name: ";
  cin >> Info.LastName;

  return Info;
}

string FullName(stInfo Info, bool reversed) {
  string FullName=" ";
  if(reversed)
  FullName= Info.LastName+ ", " + Info.FirstName;
  else
  FullName= Info.FirstName + " " + Info.LastName;
  return FullName;
}

void PrintName(string FullName) {
  cout << "Your Full Name is: " << FullName << endl;
}

int main() {
  PrintName(FullName(ReadInfo(), false)); 
  return 0;
}
