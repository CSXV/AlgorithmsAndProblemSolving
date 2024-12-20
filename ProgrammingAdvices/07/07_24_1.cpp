#include <cctype>
#include <iostream>
#include <string>
using namespace std;
// Read an string, then upper first letters of each word, then print it.

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

void StringLetters(string word) {
  bool isFirstLetter = true;
  cout << "\nString after conversion:\n";

  for (short i = 0; i < word.length(); i++) {
    if (word[i] != ' ' && isFirstLetter) {
      cout << char(toupper(word[i]));
    } else if (word[i] != isFirstLetter) {
      cout << word[i];
    }
    isFirstLetter = (word[i] == ' ' ? true : false);
  }
}

int main() {
  StringLetters(ReadString("Please enter your string: "));

  signature();
  return 0;
}
