#include <iostream>
using namespace std;
// Enter a year and a month, then print its numbers of days, hours, Minutes and
// Seconds, based if it is leap year or not.

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

short ReturnDays(short Y, short M) {
  short arr31days[12] = {1, 3, 5, 7, 8, 10, 12};

  if (M < 1 || M > 12) {
    return 0;
  } else if (M == 2) {
    return isLeapYear(Y) ? 29 : 28;
  }
  for (short i = 0; i <= 12; i++) {
    if (arr31days[i - 1] == M) {
      return 31;
    }
  }
  return 30;
}

short ReturnHours(short Y, short M) { return ReturnDays(Y, M) * 24; }
int ReturnMinutes(short Y, short M) { return ReturnHours(Y, M) * 60; }
int ReturnSeconds(short Y, short M) { return ReturnMinutes(Y, M) * 60; }

void PrintMonth(short Y, short M) {
  cout << "\nNumber of Days    in Month [" << M << "] is: " << ReturnDays(Y, M);
  cout << "\nNumber of Hours   in Month [" << M
       << "] is: " << ReturnHours(Y, M);
  cout << "\nNumber of Minutes in Month [" << M
       << "] is: " << ReturnMinutes(Y, M);
  cout << "\nNumber of Seconds in Month [" << M
       << "] is: " << ReturnSeconds(Y, M);
}

int main() {
  short Y = ReadNumber("Please enter year: ");
  short M = ReadNumber("Please enter Month: ");

  PrintMonth(Y, M);

  signature();
  return 0;
}
