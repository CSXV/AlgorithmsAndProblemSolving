#include <iostream>
#include <string>
using namespace std;
// Read string, then two words, replace the first word with the second one.

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

string ReplaceWord(string S1, string word, string replace) {
  short pos = S1.find(word);
  while (pos != std::string::npos) {
    S1 = S1.replace(pos, word.length(), replace);
    pos = S1.find(word); // Find next.
  }
  return S1;
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  string word = ReadString("Please enter the word to replace it: ");
  string replace = ReadString("Please enter the word to replace with: ");

  cout << "\nString after replace:\n" << ReplaceWord(S1, word, replace);

  signature();
  return 0;
}
