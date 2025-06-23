#include <iostream>
#include <string>
using namespace std;
// Read an number, then print a day.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

enum enDays {
  Sunday = 1,
  Monday = 2,
  Tuesday = 3,
  Wednesday = 4,
  Thursday = 5,
  Friday = 6,
  Saturday = 7
};

int ReadNumberInRage(string message, int from, int to) {
  int number = 0;

  do {
    cout << message << endl;
    cin >> number;
  } while (number < from || number > to);

  return number;
}

enDays ReadDay() {
  return (enDays)ReadNumberInRage(
      "Please enter day number in rage (01-07): ", 1, 7);
}

string GetDayOfWeek(enDays Day) {
  switch (Day) {
  case enDays::Sunday:
    return "Sunday";
  case enDays::Monday:
    return "Monday";
  case enDays::Tuesday:
    return "Tuesday";
  case enDays::Wednesday:
    return "Wednesday";
  case enDays::Thursday:
    return "Thursday";
  case enDays::Friday:
    return "Friday";
  case enDays::Saturday:
    return "Saturday";
  default:
    return "Not a day.";
  }
}

int main() {
  cout << GetDayOfWeek(ReadDay()) << endl;

  signature();
  return 0;
}
