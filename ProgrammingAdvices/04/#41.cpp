#include <iostream>
using namespace std;
// read total hours, then print total hours, total days, total weeks.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

float readPnumber(string message) {
  float number = 0;

  do {
    cout << message;
    cin >> number;
  } while (number <= 0);

  return number;
}

float HoursToDays(float Hours) { return (float)Hours / 24; }

float HourstoWeeks(float Hours) { return (float)Hours / 24 / 7; }

float DaysToWeeks(float Days) { return (float)Days / 7; }

void printResults(float Days, float Hours, float Weeks) {
  cout << "\n************************\n";
  cout << "* Total Hours: " << Hours << endl;
  cout << "* Total Days : " << Days << endl;
  cout << "* Total Weeks: " << Weeks << endl;
  cout << "\n************************\n";
}

int main() {
  float Hours = readPnumber("Please enter number of hours: ");
  float Days = HoursToDays(Hours);
  float Weeks = DaysToWeeks(Days);

  printResults(Days, Hours, Weeks);

  signature();
  return 0;
}
