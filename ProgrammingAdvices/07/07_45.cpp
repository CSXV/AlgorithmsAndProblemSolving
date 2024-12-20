#include <iostream>
#include <string>
using namespace std;
// Read bank client data record, and convert it to one line.

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

stClientData ReadClientData() {
  stClientData Client;

  cout << "Enter Account Number: ";
  getline(cin, Client.AccountNumber);
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

int main() {
  cout << "Please enter client data:\n\n";

  stClientData Client1;
  Client1 = ReadClientData();

  cout << "\n\nClient record for saving is:\n";
  cout << JoinClientData(Client1);

  signature();
  return 0;
}
