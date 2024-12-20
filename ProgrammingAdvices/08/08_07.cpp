#include <iostream>
using namespace std;
// Enter a year, month and day number, then print the date, day order in week,
// and day name.

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

short DayOrderInMonth(short Y, short M, short D) {
  short a, y, m;

  a = ((14 - M) / 12);
  y = Y - a;
  m = M + 12 * a - 2;

  return (D + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

string DayName(short DayOfWeekOrder) {
  string DayArr[7] = {"Sunday",   "Monday", "Tuesday", "Wedensday",
                      "Thursday", "Firday", "Saturday"};

  return DayArr[DayOfWeekOrder];
}

void PrintMonth(short Y, short M, short D) {
  cout << "\nDate: " << Y << "-" << M << "-" << D;
  cout << "\nDay Order: " << DayOrderInMonth(Y, M, D);
  cout << "\nDay Name: " << DayName(DayOrderInMonth(Y, M, D));
}

int main() {
  short Y = ReadNumber("Please enter a year: ");
  short M = ReadNumber("Please enter a Month: ");
  short D = ReadNumber("Please enter a Day: ");

  PrintMonth(Y, M, D);

  signature();
  return 0;
}
