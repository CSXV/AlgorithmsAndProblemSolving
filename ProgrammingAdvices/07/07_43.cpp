#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Read string, then two words, replace the first word with the second one, with
// custom replace function.

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

vector<string> SplitString(string S1, string delim) {
  vector<string> vString;
  short pos = 0;
  string sWord; // Define a string variable.

  // Use find() function to get the position of the delimiters.
  while ((pos = S1.find(delim)) != std::string::npos) {
    sWord = S1.substr(0, pos); // Store the word.
    if (sWord != "") {
      vString.push_back(sWord);
    }
    S1.erase(
        0, pos + delim.length()); // Erase() until position & move to next word.
  }
  if (S1 != "") {
    vString.push_back(S1);
  }
  return vString;
}

string JoinString(vector<string> vString, string delim) {
  string S1;
  for (string &s : vString) {
    S1 = S1 + s + delim;
  }
  return S1.substr(0, S1.length() - delim.length());
}

string LowerAllString(string S1) {
  for (short i = 0; i < S1.length(); i++) {
    S1[i] = tolower(S1[i]);
  }
  return S1;
}

string ReplaceWord(string S1, string StR, string Rt, bool match = true) {
  vector<string> vString = SplitString(S1, " ");

  for (string &s : vString) {
    if (match) {
      if (s == StR) {
        s = Rt;
      }
    } else {
      if (LowerAllString(s) == LowerAllString(StR)) {
        s = Rt;
      }
    }
  }
  return JoinString(vString, " ");
}

void PrintResults(string S1, string word, string replace) {
  cout << "\nString after replace (Match Case):\n";
  cout << ReplaceWord(S1, word, replace);

  cout << "\nString after replace (Not Match Case):\n";
  cout << ReplaceWord(S1, word, replace, false);
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  string word = ReadString("Please enter the word to replace it: ");
  string replace = ReadString("Please enter the word to replace with: ");

  PrintResults(S1, word, replace);

  signature();
  return 0;
}
