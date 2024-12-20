#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// read date, then decrease it by following functions.

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

short DayOrderInWeek(stDate Date) {
  short a, y, m;

  a = ((14 - Date.Month) / 12);
  y = Date.Year - a;
  m = Date.Month + 12 * a - 2;

  return (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

short NumberOfDaysFromTheBeginningOfTheYear(short Y, short M, short D) {
  short counter = 0;

  for (short i = 1; i <= M - 1; i++) {
    counter += ReturnDaysOfMonth(Y, i);
  }

  counter += D;

  return counter;
}

string DayName(short DayOfWeekOrder) {
  string DayArr[7] = {"Sunday",   "Monday", "Tuesday", "Wedensday",
                      "Thursday", "Firday", "Saturday"};

  return DayArr[DayOfWeekOrder];
}

bool IsEndOfWeek(stDate Date) { return DayOrderInWeek(Date) == 6; }

bool IsWeekEnd(stDate Date) {
  short DayIndex = DayOrderInWeek(Date);
  return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date) { return !IsWeekEnd(Date); }

short DaysUntilTheEndOfWeek(stDate Date) { return 6 - DayOrderInWeek(Date); }

short DaysUntilTheEndOfMonth(stDate Date) {
  return ReturnDaysOfMonth(Date.Year, Date.Month) - Date.Day;
}

short DaysUntilTheEndOfYear(stDate Date) {
  short DD = 0;
  short D =
      NumberOfDaysFromTheBeginningOfTheYear(Date.Year, Date.Month, Date.Day);

  Date.Month = 1;

  do {
    DD += ReturnDaysOfMonth(Date.Year, Date.Month);
    Date.Month++;
  } while (Date.Month != 13);

  return DD - D;
}

void DateFormat(stDate Date) {
  cout << Date.Year << "-" << Date.Month << "-" << Date.Day;
}

void PrintResults(stDate Date) {
  cout << "\nToday is: ";
  cout << DayName(DayOrderInWeek(Date)) << ", ";
  DateFormat(Date);

  cout << "\n\nIs it end of week?";
  if (IsEndOfWeek(Date))
    cout << "\nYES, end of week.";
  else
    cout << "\nNO, Not end of week.";

  cout << "\n\nIs it Weekend?";
  if (IsWeekEnd(Date))
    cout << "\nYES, it is a week end.";
  else
    cout << "\nNO, it is not a week end.";

  cout << "\n\nIs it Business Day?";
  if (IsBusinessDay(Date))
    cout << "\nYES, it is a Business Day.";
  else
    cout << "\nNO, it is not a Business Day.";

  cout << "\n\nDays until end of week: " << DaysUntilTheEndOfWeek(Date)
       << " Day(s).";
  cout << "\nDays until end of Month: " << DaysUntilTheEndOfMonth(Date)
       << " Day(s).";
  cout << "\nDays until end of Year: " << DaysUntilTheEndOfYear(Date)
       << " Day(s).";
}

int main() {
  stDate Date = GetSystemDate();
  PrintResults(Date);

  signature();
  return 0;
}
