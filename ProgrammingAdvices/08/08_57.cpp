#include <iostream>
using namespace std;
// read date and number, then print vacation date.

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

enCompare PrintResults(stDate Date, stDate Date2) {
  if (IsDate1BeforeDate2(Date, Date2)) {
    return enCompare::Before;
  }
  if (IsDate1EqualDate2(Date, Date2)) {
    return enCompare::Equal;
  }
  return enCompare::After;
}

int main() {
  stDate Date = ReadFullDate();
  stDate Date2 = ReadFullDate();

  cout << "\nCompare results: " << PrintResults(Date, Date2);

  signature();
  return 0;
}
