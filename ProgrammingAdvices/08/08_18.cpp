#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// Read birth date, then print your age in days.

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

short DifferenceInDaysFromTwoDates(stDate Date1, stDate Date2,
                                   bool IncludeEndDay = false) {
  int Days = 0;

  while (CompareDates(Date1, Date2)) {
    Days++;
    Date1 = IncreaseDateByOneDay(Date1);
  }

  return IncludeEndDay ? ++Days : Days;
}

int main() {
  cout << "Please enter you birth\n";
  stDate Date1 = ReadFullDate();
  stDate Date2 = GetSystemDate();

  cout << "\nYour age is: " << DifferenceInDaysFromTwoDates(Date1, Date2, true)
       << " Days(s).";

  signature();
  return 0;
}
