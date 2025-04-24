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

string StringLetters(string word) {
  bool isFirstLetter = true;

  cout << "\nString after conversion:\n";

  for (short i = 0; i < word.length(); i++) {
    if (word[i] != ' ' && isFirstLetter) {
      word[i] = char(toupper(word[i]));
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
