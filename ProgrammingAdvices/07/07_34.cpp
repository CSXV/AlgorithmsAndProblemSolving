#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// Read a string, then Print all vowels in that string.

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

void CountVowel(string S1) {
  cout << "\nVowels in string are:\n";

  for (short i = 0; i < S1.length(); i++) {
    if (CheckVowel(S1[i])) {
      cout << S1[i] << "\t";
    }
  }
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  CountVowel(S1);

  signature();
  return 0;
}
