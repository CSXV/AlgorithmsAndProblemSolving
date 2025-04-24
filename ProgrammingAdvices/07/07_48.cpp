#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Read bank client data record, then convert it to one line, then save it in a
// file.

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

void SeparatLine() {
  cout << "\n__________________________________________________________________"
          "_______________________________\n";
}

void PrintData(stClientData Client, string Sprt) {
  cout << Sprt << setw(15) << left << Client.AccountNumber;
  cout << Sprt << setw(10) << left << Client.PinCode;
  cout << Sprt << setw(40) << left << Client.Name;
  cout << Sprt << setw(12) << left << Client.Phone;
  cout << Sprt << setw(12) << left << Client.AccountBalance;
}

void PrintHeader(vector<stClientData> vClients, string Sprt) {
  cout << "\t\t\t\tClient list(" << vClients.size() << ") Clints(s).";
  SeparatLine();

  cout << Sprt << left << setw(15) << "Account Number";
  cout << Sprt << left << setw(10) << "Pin Code";
  cout << Sprt << left << setw(40) << "Client Name";
  cout << Sprt << left << setw(12) << "Phone";
  cout << Sprt << left << setw(12) << "Balance";

  SeparatLine();
}

void PrintAllClientsData(vector<stClientData> vClients, string Sprt) {
  PrintHeader(vClients, Sprt);

  for (stClientData Client : vClients) {
    PrintData(Client, Sprt);
    cout << endl;
  }

  SeparatLine();
}

int main() {
  string Sprt = "| ";
  vector<stClientData> vClient = ReadRecord(ClientsFileName);
  PrintAllClientsData(vClient, Sprt);

  signature();
  return 0;
}
