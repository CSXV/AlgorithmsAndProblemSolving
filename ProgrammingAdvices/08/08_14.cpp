#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// read day, month and year number, then compare if they are equal.

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

bool CompareDates(stDate Date01, stDate Date02) {
  return (Date01.Year == Date02.Year)
             ? ((Date01.Month != Date02.Month)
                    ? ((Date01.Day == Date02.Day) ? true : false)
                    : false)
             : false;
}

int main() {
  stDate Date01 = ReadFullDate();
  cout << endl;
  stDate Date02 = ReadFullDate();

  if (CompareDates(Date01, Date02)) {
    cout << "\nYES, Date 01 is equal to Date 02";
  } else {
    cout << "\nNO, Date 01 does not equal Date 02";
  };

  signature();
  return 0;
}
