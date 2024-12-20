#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// Read a character, then check if it is a vowel one or not.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

char ReadChart(string message) {
  char S1;

  cout << message;
  cin >> S1;

  return S1;
}

bool CheckVowel(char C1) {
  C1 = tolower(C1);
  return (C1 == 'a' || C1 == 'e' || C1 == 'i' || C1 == 'o' || C1 == 'u');
}

void PrintResults(char C1) {
  if (CheckVowel(C1)) {
    cout << "\nYes letter \'" << C1 << "\' is vowel.";
  } else {
    cout << "\nNo letter \'" << C1 << "\' is not vowel.";
  }
}

int main() {
  PrintResults(ReadChart("Plase enter a character: "));

  signature();
  return 0;
}
