#include <iostream>
#include <string>
using namespace std;
// Read a string, then Print each word in that string alone.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

string ReadString(string meaage) {
  string S1;

  cout << meaage;
  getline(cin, S1);

  return S1;
}

// void PrintString(string S1) {
//   cout << "\nYour string words are:\n";
//
//   for (short i = 0; i < S1.length(); i++) {
//     if (S1[i] != ' ') {
//       cout << S1[i];
//     } else if (S1[i] == ' ') {
//       cout << endl;
//     }
//   }
// }

void PrintString(string S1) {
  cout << "\nYour string words are:\n";

  string delim = " "; // Delimiter.
  short pos = 0;
  string sWord; // Define a string variable.

  // Use find() function to get the position of the delimiters.
  while ((pos = S1.find(delim)) != std::string::npos) {
    sWord = S1.substr(0, pos); // Store the word.
    if (sWord != "") {
      cout << sWord << endl;
    }

    S1.erase(
        0, pos + delim.length()); // Erase() until position & move to next word.
  }

  if (S1 != "") {
    cout << S1 << endl; // Print last word of the string.
  }
}

int main() {
  PrintString(ReadString("Please enter your string: "));

  signature();
  return 0;
}
