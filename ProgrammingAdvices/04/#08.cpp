#include <iostream>
using namespace std;

// Check if mark is >= 50 and <= 100.

enum enPassFail { Pass = 1, Fail = 2 };

int ReadMark() {
  int mark;

  cout << "Please enter a mark: ";
  cin >> mark;

  return mark;
}
enPassFail CheckMark(int mark) {
  if (mark >= 50)
    return enPassFail::Pass;
  else
    return enPassFail::Fail;
}

void printResults(int mark) {
  if (CheckMark(mark) == enPassFail::Pass)
    cout << "\nYou Passed :)";
  else
    cout << "\nYou Failed :(";
}

int main() {
  printResults(ReadMark());

  return 0;
}
