#include <iostream>
#include <ostream>
using namespace std;

// Read an number and then print the grade letter for it.

void segnature() {
  cout << "\n*************\nNEVER SETTLE.\n*************\n" << endl;
}

int readrange(int from, int to) {
  int grade;

  do {
    cout << "\nPlease enter a grade between 00 and 100: ";
    cin >> grade;
  } while (grade < from || grade > 100);

  return grade;
}

char getgradeletter(int grade) {
  if (grade >= 90)
    return 'A';
  else if (grade >= 80)
    return 'B';
  else if (grade >= 70)
    return 'C';
  else if (grade >= 60)
    return 'D';
  else if (grade >= 50)
    return 'E';
  else
    return 'F';
}

int main() {
  cout << endl
       << "Your results is: " << getgradeletter(readrange(0, 100)) << endl;

  segnature();
  return 0;
}
