#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// read date and number, then print vacation date.

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

stDate VacationDays(stDate DateFrom, short VacationDays) {
  short WeekEndCounter = 0;

  // in case the data  is weekend keep adding one day util you reach business
  // day we get rid of all weekends before the first business day
  while (IsWeekEnd(DateFrom)) {
    DateFrom = IncreaseDateByOneDay(DateFrom);
  }

  // here we increase the vacation dates to add all weekends to it.

  for (short i = 1; i <= VacationDays + WeekEndCounter; i++) {

    if (IsWeekEnd(DateFrom))
      WeekEndCounter++;

    DateFrom = IncreaseDateByOneDay(DateFrom);
  }

  // in case the return date is week end keep adding one day util you reach
  // business day
  while (IsWeekEnd(DateFrom)) {
    DateFrom = IncreaseDateByOneDay(DateFrom);
  }

  return DateFrom;
}

// stDate VacationDays(stDate Date, short N) {
//   while (N != 0) {
//     if (IsBusinessDay(Date)) {
//       N--;
//     }
//     Date = IncreaseDateByOneDay(Date);
//   }
//
//   return Date;
// }

void DateFormat(stDate Date) {
  cout << Date.Year << "-" << Date.Month << "-" << Date.Day;
}

int main() {
  cout << "Vacation Starts:\n";

  stDate Date = ReadFullDate();
  short N = ReadNumber("\nPlease enter vacation days: ");

  Date = VacationDays(Date, N);

  cout << "\n\nReturn Date: " << DayName(DayOrderInWeek(Date)) << ", ";
  DateFormat(Date);

  signature();
  return 0;
}
