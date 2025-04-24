#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Read Line of data record, then convert it to struct.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

struct stClientData {
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  int AccountBalance;
};

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

stClientData ExtractRecord(string Record, string Separator = "#//#") {
  stClientData Client;
  vector<string> vString;

  vString = splitString(Record, Separator);

  Client.AccountNumber = vString[0];
  Client.PinCode = vString[1];
  Client.Name = vString[2];
  Client.Phone = vString[3];
  Client.AccountBalance = stod(vString[4]);

  return Client;
}

void PrintRecord(stClientData Client) {
  cout << "\nAccount Number : " << Client.AccountNumber;
  cout << "\nPin Code       : " << Client.PinCode;
  cout << "\nClient name    : " << Client.Name;
  cout << "\nPhone number   : " << Client.Phone;
  cout << "\nAccount Balance: " << Client.AccountBalance;
}

int main() {
  string Record = "A150#//#1234#//#Malik al sharif#//#07999#//#5270.0000";
  cout << "Line record:\n" << Record;

  stClientData Client1 = ExtractRecord(Record);

  cout << "\n\nClient record after extracting from line:";
  PrintRecord(Client1);

  signature();
  return 0;
}
