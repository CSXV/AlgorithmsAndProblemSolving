#include <iostream>
#include <string>
using namespace std;
// Read an character, then invert it is case and print it.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

char ReadString(string message) {
  char N;

  cout << message;
  cin >> N;

  return N;
}

char CheckCart(char S1) {
  return isupper(S1) ? char(tolower(S1)) : char(toupper(S1));
}

int main() {
  char S1 = ReadString("Please enter your string: ");

  cout << "\nChar after inverting case: ";
  CheckCart(S1);

  signature();
  return 0;
}
