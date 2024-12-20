#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
// read date, then increase it by following functions.

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

stDate IncreaseDateByXDays(stDate Date, short X) {
  for (short i = 0; i < X; i++) {
    Date = IncreaseDateByOneDay(Date);
  }

  return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {
  return Date = IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeeks(stDate Date, short X) {
  for (short i = 0; i < X; i++) {
    Date = IncreaseDateByOneWeek(Date);
  }

  return Date;
}

stDate IncreaseDateByOneMonth(stDate Date) {
  if (IsLastMonthInYear(Date.Month)) {
    Date.Month = 1;
    Date.Year++;
  } else {
    Date.Month++;
  }

  // if 31-01-2024, !31-02-2024 must 28-02-2024.
  short DaysInMonth = ReturnDaysOfMonth(Date.Year, Date.Month);
  if (Date.Day > DaysInMonth) {
    Date.Day = DaysInMonth;
  }

  return Date;
}

stDate IncreaseDateByXMonth(stDate Date, short X) {
  for (short i = 0; i < X; i++) {
    Date = IncreaseDateByOneMonth(Date);
  }

  return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {
  Date.Year++;

  return Date;
}

stDate IncreaseDateByXYears(stDate Date, short X) {
  for (short i = 0; i < X; i++) {
    Date = IncreaseDateByOneYear(Date);
  }

  return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, short X) {
  Date.Year += X;

  return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
  Date.Year += 10;

  return Date;
}

stDate IncreaseDateByXDecades(stDate Date, short X) {
  for (short i = 0; i < X; i++) {
    Date = IncreaseDateByOneDecade(Date);
  }

  return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, short X) {
  Date.Year += (10 * X);

  return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {
  Date.Year += 100;

  return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date) {
  Date.Year += 1000;

  return Date;
}

void DateFormat(stDate Date) {
  cout << Date.Year << "-" << Date.Month << "-" << Date.Day;
}

void PrintResults(stDate Date) {
  cout << "\nDate After:\n";

  Date = IncreaseDateByOneDay(Date);
  cout << "\n01 - Adding One Day: ";
  DateFormat(Date);

  Date = IncreaseDateByXDays(Date, 10);
  cout << "\n02 - Adding 10 Days: ";
  DateFormat(Date);

  Date = IncreaseDateByOneWeek(Date);
  cout << "\n03 - Adding One week: ";
  DateFormat(Date);

  Date = IncreaseDateByXWeeks(Date, 10);
  cout << "\n04 - Adding 10 weeks: ";
  DateFormat(Date);

  Date = IncreaseDateByOneMonth(Date);
  cout << "\n05 - Adding one Month: ";
  DateFormat(Date);

  Date = IncreaseDateByXMonth(Date, 5);
  cout << "\n06 - Adding 5 Months: ";
  DateFormat(Date);

  Date = IncreaseDateByOneYear(Date);
  cout << "\n07 - Adding One Year: ";
  DateFormat(Date);

  Date = IncreaseDateByXYears(Date, 10);
  cout << "\n08 - Adding 10 Years: ";
  DateFormat(Date);

  Date = IncreaseDateByXYearsFaster(Date, 10);
  cout << "\n09 - Adding 10 Years (Faster): ";
  DateFormat(Date);

  Date = IncreaseDateByOneDecade(Date);
  cout << "\n10 - Adding One Decade: ";
  DateFormat(Date);

  Date = IncreaseDateByXDecades(Date, 10);
  cout << "\n11 - Adding 10 Decades: ";
  DateFormat(Date);

  Date = IncreaseDateByXDecadesFaster(Date, 10);
  cout << "\n12 - Adding 10 Decades (Faster): ";
  DateFormat(Date);

  Date = IncreaseDateByOneCentury(Date);
  cout << "\n13 - Adding One Century: ";
  DateFormat(Date);

  Date = IncreaseDateByOneMillennium(Date);
  cout << "\n14 - Adding One Millennium: ";
  DateFormat(Date);
}

int main() {
  stDate Date = ReadFullDate();
  PrintResults(Date);

  signature();
  return 0;
}
