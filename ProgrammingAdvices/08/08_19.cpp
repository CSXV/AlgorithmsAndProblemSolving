#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// read day, month and year number for two Dates, then print the difference of
// them with nigative support.

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

stDate GetSystemDate() {
  stDate Date;

  time_t TIME = time(0);
  tm *GMT = localtime(&TIME);

  Date.Year = GMT->tm_year + 1900;
  Date.Month = GMT->tm_mon + 1;
  Date.Day = GMT->tm_mday;

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

bool CompareDates(stDate Date01, stDate Date02) {
  return (Date01.Year < Date02.Year)
             ? true
             : ((Date01.Year == Date02.Year)
                    ? (Date01.Month < Date02.Month
                           ? true
                           : (Date01.Month == Date02.Month
                                  ? Date01.Day < Date02.Day
                                  : false))
                    : false);
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

void SwapDates(stDate &Date1, stDate &Date2) {
  stDate TempDate;

  TempDate.Year = Date1.Year;
  TempDate.Month = Date1.Month;
  TempDate.Day = Date1.Day;

  Date1.Month = Date2.Month;
  Date1.Year = Date2.Year;
  Date1.Day = Date2.Day;

  Date2.Year = TempDate.Year;
  Date2.Month = TempDate.Month;
  Date2.Day = TempDate.Day;
}

short DifferenceInDaysFromTwoDates(stDate Date1, stDate Date2,
                                   bool IncludeEndDay = false) {
  int Days = 0;
  short SwapFlagValue = 1;

  if (!CompareDates(Date1, Date2)) {
    SwapDates(Date1, Date2);
    SwapFlagValue = -1;
  }

  while (CompareDates(Date1, Date2)) {
    Days++;
    Date1 = IncreaseDateByOneDay(Date1);
  }

  return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
}

int main() {
  cout << "Please enter you birth\n";
  stDate Date1 = ReadFullDate();
  stDate Date2 = ReadFullDate();

  cout << "\nDifference is: " << DifferenceInDaysFromTwoDates(Date1, Date2)
       << " Day(s).";
  cout << "\nWith last day: "
       << DifferenceInDaysFromTwoDates(Date1, Date2, true) << " Day(s).";

  signature();
  return 0;
}
