#include <cmath>
#include <iostream>
using namespace std;
// Read number of seconds, then print it in DD:HH:MM:SS format.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

struct stTaskDuration {
  int Days, Hours, Minutes, Seconds;
};

int readPnumber(string message) {
  float number = 0;
  do {
    cout << message;
    cin >> number;
  } while (number <= 0);
  return number;
}

stTaskDuration SecondsToDuration(int TotalSeconds) {
  stTaskDuration TaskDuration;

  const int SecondsPerDay = 24 * 60 * 60;
  const int SecondsPerHour = 60 * 60;
  const int SecondsPerMinute = 60;

  int remainder = 0;

  TaskDuration.Days = floor(TotalSeconds / SecondsPerDay);
  remainder = TotalSeconds % SecondsPerDay;

  TaskDuration.Hours = floor(remainder / SecondsPerHour);
  remainder = remainder % SecondsPerHour;

  TaskDuration.Minutes = floor(remainder / SecondsPerMinute);
  remainder = remainder % SecondsPerMinute;

  TaskDuration.Seconds = remainder;

  return TaskDuration;
}

void PrintResults(stTaskDuration TaskDuration) {
  cout << endl
       << "************\n"
       << TaskDuration.Days << ":" << TaskDuration.Hours << ":"
       << TaskDuration.Minutes << ":" << TaskDuration.Seconds
       << "\n************\n";
}

int main() {
  int TotalSeconds = readPnumber("Please enter number of seconds: ");
  PrintResults(SecondsToDuration(TotalSeconds));
  signature();
  return 0;
}
