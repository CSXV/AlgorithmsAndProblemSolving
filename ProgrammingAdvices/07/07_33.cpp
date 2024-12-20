#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// Read a string, then count number of vowels in it, and print it.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

string ReadString(string meaage) {
  string S1;

  cout << meaage;
  getline(cin, S1);

  return S1;
}

bool CheckVowel(char C1) {
  C1 = tolower(C1);
  return (C1 == 'a' || C1 == 'e' || C1 == 'i' || C1 == 'o' || C1 == 'u');
}

short CountVowel(string S1) {
  short counter = 0;

  for (short i = 0; i < S1.length(); i++) {
    if (CheckVowel(S1[i]))
      counter++;
  }

  return counter;
}

void PrintResults(string S1) {
  cout << "\nNumber of vowels is: " << CountVowel(S1);
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  PrintResults(S1);

  signature();
  return 0;
}
