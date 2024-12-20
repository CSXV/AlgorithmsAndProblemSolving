#include <iostream>
using namespace std;
// Read days, hours, minutes, seconds, then print the total task duration in
// seconds.

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

stTaskDuration ReadTaskDuration() {
  stTaskDuration TaskDuration;
  TaskDuration.Days = readPnumber("Please enter number of Days: ");
  TaskDuration.Hours = readPnumber("Please enter number of Hours: ");
  TaskDuration.Minutes = readPnumber("Please enter number of Minutes: ");
  TaskDuration.Seconds = readPnumber("Please enter number of Seconds: ");

  return TaskDuration;
}

int TaskDurationInSeconds(stTaskDuration TaskDuration) {
  int DurationInSeconds = 0;
  DurationInSeconds = TaskDuration.Days * 24 * 60 * 60;
  DurationInSeconds += TaskDuration.Hours * 60 * 60;
  DurationInSeconds += TaskDuration.Minutes * 60;
  DurationInSeconds += TaskDuration.Seconds;

  return DurationInSeconds;
}

int main() {
  cout << TaskDurationInSeconds(ReadTaskDuration()) << endl;
  signature();
  return 0;
}
