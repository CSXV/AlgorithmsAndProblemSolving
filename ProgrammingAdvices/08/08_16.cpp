#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// read day, month and year number, then add one day to it.

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

bool IsLastDayInMonth(stDate Date) {
  return Date.Day == ReturnDaysOfMonth(Date.Year, Date.Month);
}

bool IsLastMonthInYear(short Month) { return Month == 12; }

stDate IncreaseDateByOneDay(stDate Date) {
  if (IsLastDayInMonth(Date)) {
    if (IsLastMonthInYear(Date.Month)) {
      Date.Month = 1;
      Date.Day = 1;
      Date.Year++;
    } else {
      Date.Day = 1;
      Date.Month++;
    }
  } else {
    Date.Day++;
  }
  return Date;
}

int main() {
  stDate Date = ReadFullDate();

  Date = IncreaseDateByOneDay(Date);
  cout << "Date after adding one day is: " << Date.Day << "-" << Date.Month
       << "-" << Date.Year;

  signature();
  return 0;
}
