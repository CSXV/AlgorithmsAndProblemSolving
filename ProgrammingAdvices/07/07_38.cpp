#include <iostream>
#include <string>
using namespace std;
// Read a string, then trim from left, right, and all.

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

string trimleft(string S1) {
  for (short i = 0; i < S1.length(); i++) {
    if (S1[i] != ' ') {
      // This will return from the first letter of the word to the end.
      return S1.substr(i, S1.length() - i);
    }
  }
  return "";
}

string trimright(string S1) {
  for (short i = S1.length() - 1; i >= 0; i--) {
    if (S1[i] != ' ') {
      // This will return from the last letter of the word to the beginning.
      return S1.substr(0, i + 1);
    }
  }
  return "";
}

string trimall(string S1) { return trimleft(trimright(S1)); }

void PrintResults(string S1) {
  cout << "\nTrim left : " << trimleft(S1);
  cout << "\nTrim right: " << trimright(S1);
  cout << "\nTrim all  : " << trimall(S1);
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  PrintResults(S1);

  signature();
  return 0;
}
