#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// Read an string, and a character. then count that character in the string with
// Matching case or not.

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

char ReadChart(string message) {
  char S1;

  cout << message;
  cin >> S1;

  return S1;
}

char InvertLetterCase(char C1) {
  return isupper(C1) ? tolower(C1) : toupper(C1);
}

short CountChartMatch(string S1, char C1, bool MatchCase = true) {
  short counter = 0;

  for (short i = 0; i < S1.length(); i++) {
    if (MatchCase) {
      if (S1[i] == C1) {
        counter++;
      }
    } else {
      if (tolower(S1[i]) == tolower(C1)) {
        counter++;
      }
    }
  }
  return counter;
}

void PrintResults(string S1, char C1) {
  cout << "\nLetter \'" << C1 << "\' Count       : " << CountChartMatch(S1, C1);
  cout << "\nLetter \'" << C1 << "\' or \'" << InvertLetterCase(C1)
       << "\' Count: " << CountChartMatch(S1, C1, false);
}

int main() {
  string S1 = ReadString("Please enter an string : ");
  char C1 = ReadChart("Plase enter a character: ");

  PrintResults(S1, C1);

  signature();
  return 0;
}
