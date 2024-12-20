#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// read day, month and year number, then add number of days to it, then print
// that date.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

struct stDate {
  short Day;
  short Month;
  short Year;
};

short ReadNumber(string message) {
  short S;

  cout << message;
  cin >> S;

  return S;
}

stDate ReadFullDate() {
  stDate Date;

  Date.Day = ReadNumber("Please enter a Day  : ");
  Date.Month = ReadNumber("Please enter a Month: ");
  Date.Year = ReadNumber("Please enter a year : ");

  return Date;
}

bool isLeapYear(short Y) {
  return ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0);
}

short ReturnDaysOfMonth(short Y, short M) {
  if (M < 1 || M > 12) {
    return 0;
  }

  int NumOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return (M == 2) ? (isLeapYear(Y) ? 29 : 28) : NumOfDays[M];
}

short NumberOfDaysFromTheBeginningOfTheYear(short Y, short M, short D) {
  short counter = 0;

  for (short i = 1; i <= M - 1; i++) {
    counter += ReturnDaysOfMonth(Y, i);
  }

  counter += D;

  return counter;
}

stDate AddingDaysToDate(stDate Date, short A) {
  short Day = A + NumberOfDaysFromTheBeginningOfTheYear(Date.Year, Date.Month,
                                                        Date.Day);
  short Month = 0;
  // Zeroing month, to start from the beginning of the year.
  Date.Month = 1;

  while (true) {
    Month = ReturnDaysOfMonth(Date.Year, Date.Month);

    if (Day > Month) {
      Day -= Month;
      Date.Month++;

      if (Date.Month > 12) {
        Date.Month = 1;
        Date.Year++;
      }
    } else {
      Date.Day = Day;
      break;
    }
  }

  return Date;
}

void PrintResults(stDate Date, short A) {
  cout << "\nDate after adding [" << A << "] days is: " << Date.Day << "-"
       << Date.Month << "-" << Date.Year;
}

int main() {
  stDate Date = ReadFullDate();
  short A = ReadNumber("How many days to add: ");

  Date = AddingDaysToDate(Date, A);
  PrintResults(Date, A);

  signature();
  return 0;
}
