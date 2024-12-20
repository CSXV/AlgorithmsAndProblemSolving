#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Read a string, then split each word in vector.

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

vector<string> splitString(string S1, string delim) {
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

void PrintResults(vector<string> vString, string S1) {
  cout << "Tokens: " << vString.size() << endl;

  for (string &s : vString) {
    cout << s << endl;
  }
}

int main() {
  vector<string> vString;
  string S1 = ReadString("Please enter your string: ");
  string delim = ReadString("Please enter the delim  : ");

  vString = splitString(S1, delim);
  PrintResults(vString, S1);

  signature();
  return 0;
}
