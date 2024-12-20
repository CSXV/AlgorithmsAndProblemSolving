#include <iostream>
#include <ostream>
#include <string>
using namespace std;
//The best card info in history.
enum enGender { Male = 1, Female = 2 };

struct OwnerAddress {
  string Home;
  string PoBox;
};

struct Owner {
  string OwnerName;
  string Phone;
  OwnerAddress Address;
  bool Gender;
};

struct Car {
  string Name;
  string Model;
  string Year;
  Owner owner;
};

Car ReadInfo() {
  Car Car1;
  cout << "Please enter your Name: ";
  cin >> Car1.owner.OwnerName;
  cout << "Hey " << Car1.owner.OwnerName << endl;
  cout << "Please enter your car name: ";
  cin >> Car1.Name;
  cout << "Please etner your car model: ";
  cin >> Car1.Model;
  cout << "Please enter your car Year: ";
  cin >> Car1.Year;
  cout << "Please enter your Home Address: ";
  cin >> Car1.owner.Address.Home;
  cout << "Please enter your PoBox: ";
  cin >> Car1.owner.Address.PoBox;
  cout << "Please enter your Phone number: ";
  cin >> Car1.owner.Phone;
  cout << "Please enter you gender\n(1) Male, (2) Female: ";
  cin >> Car1.owner.Gender;

  return Car1;
}

//  string voGender(Car Car1) {
//   if (Car1.owner.Gender == enGender::Male)
//     cout << "Your gender is: Male";
//   else
//     cout << "Your gender is: Female";
// }

//  void voGender(Car Car1) {
//   if (Car1.owner.Gender == enGender::Male)
//     cout << "Your gender is: Male";
//   else
//     cout << "Your gender is: Female";
// };

// enGender voGender(Car Car1) {
//   if (Car1.owner.Gender == 0)
//     return enGender::Male;
//   else
//     return enGender::Female;
// }

void WriteInfo(Car Car1) {
  cout << "\n\n********************************\n";
  cout << "********************************\n";
  cout << "* Hey (" << Car1.owner.OwnerName << ") Have a nice day :)\n";
  cout << "* Your Home Address is: " << Car1.owner.Address.Home << endl;
  cout << "* Your PoBox is: " << Car1.owner.Address.PoBox << endl;
  cout << "* Your Phone number is: " << Car1.owner.Phone << endl;

  if (Car1.owner.Gender == enGender::Male)
    cout << "Your gender is: Male (!@_@)";
  else
    cout << "Your gender is: Female (-_-)";

  // cout << "Your gender is: ";
  // voGender(Car1);

  cout << "\n********************************\n";
  cout << "* Your Car name is: " << Car1.Name << endl;
  cout << "* Your Car Model is: " << Car1.Model << endl;
  cout << "* Your Car Year is: " << Car1.Year << endl;
  cout << "********************************\n";
  cout << "********************************\n";
}

int main() {
  WriteInfo(ReadInfo());

  return 0;
}
