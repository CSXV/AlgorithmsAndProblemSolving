#include <iostream>
using namespace std;
// Enter a year and a month, then print its numbers of days, hours, Minutes and
// Seconds, based if it is leap year or not, WITH OPTIMIZATION.

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

// bool checkmonth(short M) {
//   short arr31days[12] = {1, 3, 5, 7, 8, 10, 12};
//
//   for (short i = 0; i <= 12; i++) {
//     if (arr31days[i - 1] == M) {
//       return true;
//     }
//   }
//   return false;
// }
//
// short ReturnDays(short Y, short M) {
//   return (M < 1 || M > 12) ? 0
//                            : ((M == 2) ? (isLeapYear(Y) ? 29 : 28)
//                                        : (checkmonth(M) ? 31 : 30));
// }

short ReturnDays(short Y, short M) {
  if (M < 1 || M > 12) {
    return 0;
  }

  int NumOfDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return (M == 2) ? (isLeapYear(Y) ? 29 : 28) : NumOfDays[M];
}

void PrintMonth(short Y, short M) {
  cout << "\nNumber of Days    in Month [" << M << "] is: " << ReturnDays(Y, M);
}

int main() {
  short Y = ReadNumber("Please enter year: ");
  short M = ReadNumber("Please enter Month: ");

  PrintMonth(Y, M);

  signature();
  return 0;
}
