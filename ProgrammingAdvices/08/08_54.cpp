#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// read two dates, then print vacation days in that period.

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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
  return (Date1.Year < Date2.Year)
             ? true
             : ((Date1.Year == Date2.Year)
                    ? (Date1.Month < Date2.Month
                           ? true
                           : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day
                                                         : false))
                    : false);
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

short VacationDays(stDate Date1, stDate Date2) {
  short N = 0;

  while (IsDate1BeforeDate2(Date1, Date2)) {
    if (IsBusinessDay(Date1)) {
      N++;
    }
    Date1 = IncreaseDateByOneDay(Date1);
  }

  return N;
}

void DateFormat(stDate Date) {
  cout << Date.Year << "-" << Date.Month << "-" << Date.Day;
}

void PrintResults(stDate Date1, stDate Date2) {
  cout << "\nVacation From: " << DayName(DayOrderInWeek(Date1)) << ", ";
  DateFormat(Date1);

  cout << "\nVacation To  : " << DayName(DayOrderInWeek(Date2)) << ", ";
  DateFormat(Date2);

  cout << "\n\nActual Vactaion Days is: " << VacationDays(Date1, Date2);
}

int main() {
  cout << "Vacation Starts:\n";
  stDate Date1 = ReadFullDate();

  cout << "\nVacation Ends:\n";
  stDate Date2 = ReadFullDate();

  PrintResults(Date1, Date2);

  signature();
  return 0;
}
