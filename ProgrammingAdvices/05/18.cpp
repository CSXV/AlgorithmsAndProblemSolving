
#include <iostream>
#include <string>
using namespace std;
// Read a string, then encrypt it, and dycrpyt it.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

string readletters(string message) {
  string N;
  cout << message;
  cin >> N;
  return N;
}

string EncryptText(short key, string Letter) {
  for (int i = 0; i <= Letter.length(); i++) {
    Letter[i] = char((int)Letter[i] + key);
  }
  return Letter;
}

string DecryptText(short key, string Letter) {
  for (int i = 0; i <= Letter.length(); i++) {
    Letter[i] = char((int)Letter[i] - key);
  }
  return Letter;
}

int main() {
  const short Key = 2; // This is the encrypting key.
  string Letter = readletters("Please enter text to encrypt it: ");
  string TxtAfterEncrypt = EncryptText(Key, Letter);
  string TxtAfterDecrypt = DecryptText(Key, TxtAfterEncrypt);

  cout << "\nText before encryption: " << Letter << endl;
  cout << "\nText After encrytion: " << TxtAfterEncrypt << endl;
  cout << "\nText After Decryption: " << TxtAfterDecrypt << endl;

  signature();
  return 0;
}
