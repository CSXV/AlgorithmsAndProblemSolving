#include <iostream>
using namespace std;
// read two Periods with two dates in it, then print if they overlap or not.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

enum enCompare { Before = -1, Equal = 0, After = 1 };

struct stDate {
  short Day;
  short Month;
  short Year;
};

struct stPeriod {
  stDate Start;
  stDate End;
};

short ReadNumber(string message, short N, short D) {
  short S;

  do {
    cout << message;
    cin >> S;
  } while (S < N || S > D);

  return S;
}

stDate ReadFullDate() {
  stDate Date;

  Date.Day = ReadNumber("Please enter a Day  : ", 1, 31);
  Date.Month = ReadNumber("Please enter a Month: ", 1, 12);
  Date.Year = ReadNumber("Please enter a year : ", 1900, 3000);

  return Date;
}

stPeriod ReadPeroid() {
  stPeriod Period;

  cout << "Enter Start Date:\n\n";
  Period.Start = ReadFullDate();
  cout << "\nEnter End Date:\n";
  Period.End = ReadFullDate();

  return Period;
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

bool IsDate1EqualDate2(stDate Date, stDate Date2) {
  return (Date.Year == Date2.Year)
             ? ((Date.Month == Date2.Month)
                    ? ((Date.Day == Date2.Day) ? true : false)
                    : false)
             : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
  return (!IsDate1BeforeDate2(Date1, Date2) &&
          !IsDate1EqualDate2(Date1, Date2));
}

enCompare CompareDates(stDate Date, stDate Date2) {
  if (IsDate1BeforeDate2(Date, Date2)) {
    return enCompare::Before;
  }
  if (IsDate1EqualDate2(Date, Date2)) {
    return enCompare::Equal;
  }
  return enCompare::After;
}

// bool ComparePeroids(stPeriod Period1, stPeriod Period2) {
//   while (Period1.Start.Day != Period1.End.Day) {
//     if (IsDate1EqualDate2(Period1.Start, Period2.Start)) {
//       return true;
//     }
//     Period1.Start = IncreaseDateByOneDay(Period1.Start);
//   }
//
//   return false;
// }

bool ComparePeroids(stPeriod Period1, stPeriod Period2) {
  if (CompareDates(Period2.End, Period1.Start) == enCompare::Before ||
      CompareDates(Period1.End, Period2.Start) == enCompare::After)
    return false;
  else
    return true;
}

int main() {
  cout << "Enter Period 01:\n";
  cout << "----------------\n";
  stPeriod Period1 = ReadPeroid();

  cout << "\n\nEnter Period 02:\n";
  cout << "----------------\n";
  stPeriod Period2 = ReadPeroid();

  if (ComparePeroids(Period1, Period2)) {
    cout << "\nYES, Periods overlap.";
  } else {
    cout << "\nNO, Periods does not overlap.";
  }

  signature();
  return 0;
}
