#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;
// Print calendar for year and month.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

short ReadNumber(string message) {
  short S;

  cout << message;
  cin >> S;

  return S;
}

bool isLeapYear(short Y) {
  return ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0);
}

short DayOrderInWeek(short Y, short M, short D) {
  short a, y, m;

  a = ((14 - M) / 12);
  y = Y - a;
  m = M + 12 * a - 2;

  return (D + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

short ReturnDaysOfMonth(short Y, short M) {
  if (M < 1 || M > 12) {
    return 0;
  }

  int NumOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return (M == 2) ? (isLeapYear(Y) ? 29 : 28) : NumOfDays[M];
}

string DayName(short DayOfWeekOrder) {
  string DayArr[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fir", "Sat"};

  return DayArr[DayOfWeekOrder];
}

string MonthShortName(short M) {
  string MonthArr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                         "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  return (MonthArr[M - 1]);
}

// MY SOLUTION :)
// void PrintCalendar(short Y, short M) {
//   short t = DayOrderInWeek(Y, M, 1);
//   string Tabs = "  ";
//   string DayArr[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fir", "Sat"};
//
//   printf("\n_______________%s_______________\n", MonthShortName(M).c_str());
//
//   // Print Days header.
//   for (short i = 0; i < 7; i++) {
//     cout << DayArr[i] + Tabs;
//   }
//   cout << endl;
//
//   // Spaces for empty days.
//   for (short j = 0; j < t; j++) {
//     cout << "   " + Tabs;
//   }
//
//   // Print days number.
//   for (short i = 0; i < ReturnDaysOfMonth(Y, M); i++) {
//     // printf("%4d", i);
//     cout << setw(3) << i + 1 << Tabs;
//
//     if (DayOrderInWeek(Y, M, i - 1) == 4) {
//       cout << endl;
//     }
//   }
//
//   cout << "\n__________________________________";
// }

void PrintMonthCalendar(short Year, short Month) {
  int NumberOfDays;
  // Index of the day from 0 to 6
  int current = DayOrderInWeek(1, Month, Year);
  NumberOfDays = ReturnDaysOfMonth(Year, Month);

  // Print the current month name
  printf("\n_______________ %s_______________\n\n ",
         MonthShortName(Month).c_str());

  // Print the columns
  printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

  // Print appropriate spaces
  int i;
  for (i = 0; i < current; i++)
    printf("     ");
  for (int j = 1; j <= NumberOfDays; j++) {
    printf("%5d", j);
    if (++i == 7) {
      i = 0;
      printf("\n");
    }
  }

  printf("\n_________________________________\n");
}

int main() {
  short Y = ReadNumber("Please enter a year: ");
  short M = ReadNumber("Please enter a Month: ");

  PrintMonthCalendar(Y, M);

  signature();
  return 0;
}
