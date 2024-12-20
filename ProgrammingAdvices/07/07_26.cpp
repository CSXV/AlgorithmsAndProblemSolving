#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// Read an string, then print it in all upper case, and all lower case.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

string ReadString(string message) {
  string N;

  cout << message;
  getline(cin, N);

  return N;
}
string UpperString(string S1) {
  cout << "\nString after upper:\n";

  for (short i = 0; i < S1.length(); i++) {
    S1[i] = char(toupper(S1[i]));
  }
  return S1;
}

string LowerString(string S1) {
  cout << "\n\nString after lower:\n";

  for (short i = 0; i < S1.length(); i++) {
    S1[i] = char(tolower(S1[i]));
  }
  return S1;
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  cout << UpperString(S1);
  cout << LowerString(S1);

  signature();
  return 0;
}
