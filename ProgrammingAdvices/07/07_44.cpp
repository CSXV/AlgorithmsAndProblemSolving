#include <iostream>
using namespace std;
// Read string, then remove all punctuations from it.

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

string RemovePunctuationsFromString(string S1) {
  string S2 = "";

  for (short i = 0; i < S1.length(); i++) {
    if (!ispunct(S1[i])) {
      S2 += S1[i];
    }
  }

  return S2;
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  cout << "\npunctuations Removed:\n" << RemovePunctuationsFromString(S1);

  signature();
  return 0;
}
