#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
// read day, month and year number, then print the total days from the beginning
// of the year to that day, then take that total and convert it to date.

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

short NumberOfDaysFromTheBeginningOfTheYear(short Y, short M, short D) {
  short counter = 0;

  for (short i = 1; i <= M - 1; i++) {
    counter += ReturnDaysOfMonth(Y, i);
  }

  counter += D;

  return counter;
}

stDate ConvertNumberOfYearToDate(short Y, short N) {
  stDate Date;
  short D = N;
  short M = 0;

  Date.Year = Y;
  Date.Month = 1;

  while (true) {
    M = ReturnDaysOfMonth(Y, Date.Month);

    if (D > M) {
      D -= M;
      Date.Month++;
    } else {
      Date.Day = D;
      break;
    }
  }

  return Date;
}

// string ConvertNumberOfYearToDate(short Y, short N) {
//   string Date = "";
//   short M = 1, D = 0;
//
//   for (short i = 1; i <= M; i++) {
//     if (D <= N) {
//       D += ReturnDaysOfMonth(Y, i);
//       M++;
//     }
//   }
//
//   Date = to_string(Y) + "-" + to_string(M - 1) + "-" +
//          to_string(ReturnDaysOfMonth(Y, M - 1) - (D - N));
//
//   return Date;
// }

void PrintResults(short Y, short M, short D, short N, stDate Date) {
  cout << "Number of days from the beginning of the year is: " << N;

  cout << "\nDate for [" << N << "] is: " << Date.Day << "-" << Date.Month
       << "-" << Date.Year;
}

int main() {
  short D = ReadNumber("Please enter a Day: ");
  short M = ReadNumber("Please enter a Month: ");
  short Y = ReadNumber("Please enter a year: ");

  short N = NumberOfDaysFromTheBeginningOfTheYear(Y, M, D);
  stDate Date = ConvertNumberOfYearToDate(Y, N);

  PrintResults(Y, M, D, N, Date);

  signature();
  return 0;
}
