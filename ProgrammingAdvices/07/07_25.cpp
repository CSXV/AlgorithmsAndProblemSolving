#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// Read an string, then lower first letters of each word, then print it.

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

string StringLetters(string word) {
  cout << "\nString after conversion:\n";
  bool isFirstLetter = true;

  for (short i = 0; i < word.length(); i++) {
    if (word[i] != ' ' && isFirstLetter) {
      word[i] = char(tolower(word[i]));
    }

    isFirstLetter = (word[i] == ' ' ? true : false);
  }

  return word;
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  StringLetters(S1);
  cout << S1 << endl;

  signature();
  return 0;
}
