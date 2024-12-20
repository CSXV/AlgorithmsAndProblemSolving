#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Find client by account Number, then print it to the screen, then ask the user
// to delete it or not.

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
  bool MarkforDelete = false;
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

string ConvertRecordToLine(stClientData Client, string Seperator = "#//#") {
  string stClientRecord = "";

  stClientRecord += Client.AccountNumber + Seperator;
  stClientRecord += Client.PinCode + Seperator;
  stClientRecord += Client.Name + Seperator;
  stClientRecord += Client.Phone + Seperator;
  stClientRecord += to_string(Client.AccountBalance);

  return stClientRecord;
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

bool FindClientByAccountNumber(string AccNum, vector<stClientData> vClients,
                               stClientData &Client) {

  for (stClientData C : vClients) {
    if (C.AccountNumber == AccNum) {
      Client = C;
      return true;
    }
  }
  return false;
}

bool MarkClientForDeleteByAccountNumber(string AccNum,
                                        vector<stClientData> &vClients) {
  for (stClientData &C : vClients) {
    if (C.AccountNumber == AccNum) {
      C.MarkforDelete = true;
      return true;
    }
  }
  return false;
}

vector<stClientData> SaveClientDataToFile(string ClientsFileName,
                                          vector<stClientData> vClients) {
  fstream MyFile;
  MyFile.open(ClientsFileName, ios::out); // overwrite.

  string DataLine;

  if (MyFile.is_open()) {
    for (stClientData C : vClients) {
      if (C.MarkforDelete == false) {
        // we only write records that are nto marked for delete.
        DataLine = ConvertRecordToLine(C);
        MyFile << DataLine << endl;
      }
    }
    MyFile.close();
  }
  return vClients;
}

void PrintAllClientsData(string AccNum, vector<stClientData> vClients,
                         stClientData Client) {

  if (FindClientByAccountNumber(AccNum, vClients, Client)) {
    PrintData(Client);
  } else {
    cout << "\nClient with account Number (" << AccNum << ") not found!";
  }
}

bool DeleteClientByAccountNumber(string AccNum,
                                 vector<stClientData> &vClients) {
  stClientData Client;
  char Answer = 'n';

  if (FindClientByAccountNumber(AccNum, vClients, Client)) {
    PrintData(Client);

    cout << "\n\nAre you sure you want to delete this client? (Y/N): ";
    cin >> Answer;

    if (toupper(Answer) == 'Y') {
      MarkClientForDeleteByAccountNumber(AccNum, vClients);
      SaveClientDataToFile(ClientsFileName, vClients);

      // Refresh Data.
      vClients = ReadRecord(ClientsFileName);
      cout << "\nClient deleted successfuly.";
      return true;
    }
  }
  return false;
}

int main() {
  string AccNum = ReadString("Please enter account number: ");
  vector<stClientData> vClients = ReadRecord(ClientsFileName);

  DeleteClientByAccountNumber(AccNum, vClients);

  signature();
  return 0;
}
