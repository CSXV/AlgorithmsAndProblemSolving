#include <iostream>
#include <vector>
using namespace std;
// Read strings in vector, then join them in one string with separators.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

string JoinSting(vector<string> vstring, string delim) {
  string S1;

  for (string &s : vstring) {
    S1 = S1 + s + delim;
  }
  // To delete the last separator from S1 string.
  return S1.substr(0, S1.length() - delim.length());
}

int main() {
  vector<string> vString = {"mohamad", "fadi", "ali", "maher"};

  cout << "Vector after join:\n";
  cout << JoinSting(vString, " ");

  signature();
  return 0;
}
