#include <iostream>
#include <string>
using namespace std;
// Read an string, and a character. then count that character in the string.

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

short CountChart(string S1, char C1) {
  short counter = 0;

  for (short i = 0; i < S1.length(); i++) {
    if (S1[i] == C1) {
      counter++;
    }
  }
  return counter;
}

void PrintResults(string S1, char C1) {
  cout << "\nLetter \'" << C1 << "\' Count: " << CountChart(S1, C1);
}

int main() {
  string S1 = ReadString("Please enter an string : ");
  char C1 = ReadChart("Plase enter a character: ");

  PrintResults(S1, C1);

  signature();
  return 0;
}
