#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Find client by account Number, then print it to the screen.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

const string ClientsFileName = "Client.txt";

struct stClientData {
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  int AccountBalance;
};

string ReadString(string message) {
  string N;

  cout << message;
  cin >> N;

  return N;
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

vector<stClientData> ReadRecord(string FileName) {
  vector<stClientData> vClients;
  fstream MyFile;

  MyFile.open(FileName, ios::in);

  if (MyFile.is_open()) {
    string Line;
    stClientData Clinet;

    while (getline(MyFile, Line)) {
      Clinet = ExtractRecord(Line);
      vClients.push_back(Clinet);
    }

    MyFile.close();
  }

  return vClients;
}

void PrintData(stClientData Client) {
  cout << "\nThe following are the client details:\n";

  cout << "\nAccount number : " << Client.AccountNumber;
  cout << "\nPin Code       : " << Client.PinCode;
  cout << "\nClient Name    : " << Client.Name;
  cout << "\nPhone Number   : " << Client.Phone;
  cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccNum, stClientData &Client) {
  vector<stClientData> vClients = ReadRecord(ClientsFileName);

  for (stClientData C : vClients) {
    if (C.AccountNumber == AccNum) {
      Client = C;

      return true;
    }
  }

  return false;
}

void PrintAllClientsData(string AccNum, stClientData Client) {

  if (FindClientByAccountNumber(AccNum, Client)) {
    PrintData(Client);
  } else {
    cout << "\nClient with account Number (" << AccNum << ") not found!";
  }
}

int main() {
  stClientData Client;
  string AccNum = ReadString("Please enter account number: ");

  PrintAllClientsData(AccNum, Client);

  signature();
  return 0;
}
