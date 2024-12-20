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

char InvertLetterCase(char char1) {
  return isupper(char1) ? tolower(char1) : toupper(char1);
}

string InvertAllStringLettersCase(string S1) {
  cout << "\nString after Inverting All Letters Case:\n";

  for (short i = 0; i < S1.length(); i++) {
    S1[i] = InvertLetterCase(S1[i]);
  }
  return S1;
}

int main() {
  string S1 = ReadString("Please Enter Your String: ");

  S1 = InvertAllStringLettersCase(S1);
  cout << S1 << endl;

  signature();
  return 0;
}
