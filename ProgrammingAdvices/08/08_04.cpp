#include <iostream>
using namespace std;
// Enter a year, then print its numbers of days, hours, Minutes and Seconds,
// based if it is leap year or not.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

short ReadNumber(string message) {
  short S;

  cout << message;
  cin >> S;

  return S;
}

bool isLeapYear(short Y) {
  return ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0);
}

short ReturnDays(short Y) { return isLeapYear(Y) ? 366 : 365; }

short ReturnHours(short Y) { return ReturnDays(Y) * 24; }
int ReturnMinutes(short Y) { return ReturnHours(Y) * 60; }
int ReturnSeconds(short Y) { return ReturnMinutes(Y) * 60; }

void PrintYear(short Y) {
  cout << "\nNumber of Days    in year [" << Y << "] is: " << ReturnDays(Y);
  cout << "\nNumber of Hours   in year [" << Y << "] is: " << ReturnHours(Y);
  cout << "\nNumber of Minutes in year [" << Y << "] is: " << ReturnMinutes(Y);
  cout << "\nNumber of Seconds in year [" << Y << "] is: " << ReturnSeconds(Y);
}

int main() {
  short Y = ReadNumber("Please enter year: ");
  PrintYear(Y);

  signature();
  return 0;
}
