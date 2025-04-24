#include <iostream>
#include <string>
using namespace std;
// Read a string, then Print the count of words in it.

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

short CountWords(string S1) {
  string delim = " "; // Delimiter.
  short pos = 0;
  short counter = 0;
  string sWord; // Define a string variable.

  // Use find() function to get the position of the delimiters.
  while ((pos = S1.find(delim)) != std::string::npos) {
    sWord = S1.substr(0, pos); // Store the word.

    if (sWord != "") {
      counter++;
    }
    // Erase() until position & move to next word.
    S1.erase(0, pos + delim.length());
  }

  if (S1 != "") {
    counter++;
  }

  return counter;
}

void PrintResults(string message, string S1) {
  cout << message;
  cout << CountWords(S1);
}

int main() {
  string S1 = ReadString("Please enter your string: ");

  CountWords(S1);
  PrintResults("the number of words in your string is: ", S1);

  signature();
  return 0;
}
