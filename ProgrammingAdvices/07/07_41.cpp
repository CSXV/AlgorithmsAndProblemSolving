#include <iostream>
#include <vector>
using namespace std;
// Read string, then print it is words in reverse order.

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

vector<string> SplitString(string S1, string Delim) {
  vector<string> vString;
  short pos = 0;
  string sWord; // define a string variable

  // use find() function to get the
  while ((pos = S1.find(Delim)) != std::string::npos) {
    // position of the delimiters
    sWord = S1.substr(0, pos); // store the word

    if (sWord != "") {
      vString.push_back(sWord);
    } /* erase() until positon and move to next word. */

    S1.erase(0, pos + Delim.length());
  }

  if (S1 != "") {
    vString.push_back(S1); // it adds last word of the string.
  }

  return vString;
}

string ReverseWordsInString(string S1) {
  vector<string> vString;
  string S2 = "";

  vString = SplitString(S1, " ");
  vector<string>::iterator iter = vString.end(); // declare iterator

  while (iter != vString.begin()) {
    --iter;
    S2 += *iter + " ";
  }

  S2 = S2.substr(0, S2.length() - 1); // remove last space.
  return S2;
}

int main() {
  string S1 = ReadString("Please enter your string: ");
  cout << "\nString after reversing words:\n" << ReverseWordsInString(S1);

  signature();
  return 0;
}
