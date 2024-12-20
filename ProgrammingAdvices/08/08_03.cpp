#include <iostream>
using namespace std;
// Enter an number, then check it is a leap year or not, with optimization.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

int ReadNumber(string message) {
  int S;

  cout << message;
  cin >> S;

  return S;
}

bool LeapYear(short Y) {
  return ((Y % 4 == 0 && Y % 100 != 0) || Y % 400 == 0);
}

int main() {
  short Y = ReadNumber("Please enter an number: ");

  if (LeapYear(Y)) {
    cout << "Yes, Year [" << Y << "] Leap year";
  } else {
    cout << "No, Year [" << Y << "] Not Leap year";
  }

  signature();
  return 0;
}
