#include <iostream>
#include <string>
using namespace std;
// Read an string, then print the first letters of it.

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
  bool isFirstLetter = true; // we assumet the S1[0] is capital.
  cout << "First letter of this string is:\n";

  for (short i = 0; i < word.length(); i++) {
    // char variable, just to debug easelly.
    char C = word[i];

    if (C != ' ' && isFirstLetter) {
      cout << C << endl;
    }
    // is the cart that i am in is space?
    // if YES, (isFirstLetter) = true.
    // if NO, then (isFirstLetter) return false.
    isFirstLetter = (C == ' ' ? true : false);
  }
}

// MY SOLUTION :)
// void StringLetters(string word) {
//   cout << "First letter of this sting is:\n";
//   cout << word[0] << endl;
//
//   for (short i = 0; i < word.length(); i++) {
//     if (word[i] == ' ') {
//       cout << word[i + 1] << endl;
//     }
//   }
// }

int main() {
  StringLetters(ReadString("Please enter your string: "));

  signature();
  return 0;
}
