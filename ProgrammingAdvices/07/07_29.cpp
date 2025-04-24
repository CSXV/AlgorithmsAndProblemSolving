#include <iostream>
#include <string>
using namespace std;
// Read an string, then invert all letters in it, then print it.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

string ReadString(string message) {
  string S1;

  cout << message;
  getline(cin, S1);

  return S1;
}

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) {
  if (WhatToCount == enWhatToCount::All) {
    return S1.length();
  }

  short Counter = 0;

  for (short i = 0; i < S1.length(); i++) {
    if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
      Counter++;

    if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
      Counter++;
  }

  return Counter;
}

short CountCapitalLetters(string S1) {
  short Counter = 0;

  for (short i = 0; i < S1.length(); i++) {
    if (isupper(S1[i]))
      Counter++;
  }

  return Counter;
}

short CountSmallLetters(string S1) {
  short Counter = 0;

  for (short i = 0; i < S1.length(); i++) {
    if (islower(S1[i]))
      Counter++;
  }

  return Counter;
}

int main() {
  string S1 = ReadString("Please enter an string: ");

  cout << "\nString Length = " << S1.length();
  cout << "\nCapital Letters Count= " << CountCapitalLetters(S1);
  cout << "\nSmall Letters Count= " << CountSmallLetters(S1);

  cout << "\n\nMETHOD 02";
  cout << "\nString Length = " << CountLetters(S1);
  cout << "\nCapital Letters Count= "
       << CountLetters(S1, enWhatToCount::CapitalLetters);
  cout << "\nSmall Letters Count= "
       << CountLetters(S1, enWhatToCount::SmallLetters);

  signature();
  return 0;
}
