#include <fstream>
#include <iostream>
#include <string>
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

stClientData ReadClientData() {
  stClientData Client;

  // Usage of std::ws will extract all the whitespace characters.
  cout << "Enter Account Number: ";
  getline(cin >> ws, Client.AccountNumber);

  cout << "Enter Pin Code: ";
  getline(cin, Client.PinCode);

  cout << "Enter the name: ";
  getline(cin, Client.Name);

  cout << "Enter Phone number: ";
  getline(cin, Client.Phone);

  cout << "Enter account Balance: ";
  cin >> Client.AccountBalance;

  return Client;
}

string JoinClientData(stClientData Client1, string Separator = "#//#") {
  string S1;

  S1 += Client1.AccountNumber + Separator;
  S1 += Client1.PinCode + Separator;
  S1 += Client1.Name + Separator;
  S1 += Client1.Phone + Separator;
  S1 += to_string(Client1.AccountBalance);

  return S1;
}

void AppendRecord(string FileName, string stDataLine) {
  fstream MyFile;

  MyFile.open(FileName, ios::out | ios::app);

  if (MyFile.is_open()) {
    MyFile << stDataLine << endl;
    MyFile.close();
  }
}

void AddNewClient() {
  stClientData Client = ReadClientData();

  AppendRecord(ClientsFileName, JoinClientData(Client));
}

void AddClients() {
  char ques = 'Y';

  do {
    system("cls");
    cout << "Please enter client data:\n\n";

    AddNewClient();
    cout << "\nClient Added Successfully, do you want to add more clients? "
            "(Y/N): ";
    cin >> ques;
  } while (toupper(ques) == 'Y');
}

int main() {
  AddClients();

  signature();
  return 0;
}
