#include <iostream>
#include <string>
using namespace std;
// Read an number, then print a Month.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

enum enMonths {
  January = 1,
  February = 2,
  March = 3,
  April = 4,
  May = 5,
  June = 6,
  July = 7,
  August = 8,
  September = 9,
  October = 10,
  November = 11,
  December = 12,
};

int ReadNumberInRage(string message, int from, int to) {
  int number = 0;

  do {
    cout << message << endl;
    cin >> number;
  } while (number < from || number > to);

  return number;
}

enMonths ReadDay() {
  return (enMonths)ReadNumberInRage(
      "Please enter day number in rage (01-12): ", 1, 12);
}

string GetMonth(enMonths Day) {
  switch (Day) {
  case enMonths::January:
    return "January";
  case enMonths::February:
    return "February";
  case enMonths::March:
    return "March";
  case enMonths::April:
    return "April";
  case enMonths::May:
    return "May";
  case enMonths::June:
    return "June";
  case enMonths::July:
    return "July";
  case enMonths::August:
    return "August";
  case enMonths::September:
    return "September";
  case enMonths::October:
    return "October";
  case enMonths::November:
    return "November";
  case enMonths::December:
    return "December";
  default:
    return "Not a month.";
  }
}

int main() {
  cout << GetMonth(ReadDay());

  signature();
  return 0;
}
