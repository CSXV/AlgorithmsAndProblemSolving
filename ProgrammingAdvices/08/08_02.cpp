#include <iostream>
using namespace std;
// Enter an number, then check it is a leap year or not.

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
  if (Y % 400 == 0) {
    return true;
  } else if (Y % 100 == 0) {
    return false;
  } else if (Y % 4 == 0) {
    return true;
  } else {
    return false;
  }
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
