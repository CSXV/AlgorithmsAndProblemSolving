#include <iostream>
#include <string>
using namespace std;
// Read an string, then invert all letters in it, then print it.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

struct stStringCount {
  short length = 0;
  short Capital = 0;
  short Small = 0;
};

string ReadString(string message) {
  string S1;

  cout << message;
  getline(cin, S1);

  return S1;
}

stStringCount CountLetters(string S1, stStringCount &String1) {
  String1.length = S1.length();

  for (short i = 0; i < S1.length(); i++) {
    if (isupper(S1[i])) {
      String1.Capital++;
    } else if (islower(S1[i])) {
      String1.Small++;
    }
  }

  return String1;
}

void PrintCount(string S1, stStringCount String1) {
  cout << "\nString length  : " << String1.length;
  cout << "\nCapital letters: " << String1.Capital;
  cout << "\nSmall letters  : " << String1.Small;
}

int main() {
  stStringCount String1;
  string S1 = ReadString("Please Enter Your String: ");

  CountLetters(S1, String1);
  PrintCount(S1, String1);

  signature();
  return 0;
}
