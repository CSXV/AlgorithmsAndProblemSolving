#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Read strings in vector, then join them in one string with separators, with
// two solutions.

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

string JoinSting(vector<string> vstring, string delim) {
  string S1;

  for (string &s : vstring) {
    S1 = S1 + s + delim;
  }
  return S1.substr(
      0, S1.length() -
             delim.length()); // To delete the last separator from S1 string.
}

string JoinSting(string arrString[], string delim, short N) {
  string S1 = "";

  for (short i = 0; i < N; i++) {
    S1 = S1 + arrString[i] + delim;
  }
  return S1.substr(
      0, S1.length() -
             delim.length()); // To delete the last separator from S1 string.
}

int main() {
  vector<string> vString = {"mohamad", "fadi", "ali", "maher"};
  string arrString[] = {"mohamad", "fadi", "ali", "maher"};

  cout << "Vector after join:\n";
  cout << JoinSting(vString, " ");

  cout << "\n\nVector after join:\n";
  cout << JoinSting(arrString, " ", 3);

  signature();
  return 0;
}
