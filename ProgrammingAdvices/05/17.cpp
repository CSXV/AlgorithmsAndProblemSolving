#include <iostream>
using namespace std;
// Read a three letters password, then guest by brut force.

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

bool printpattern(string n) {
  string word = "";
  int c = 0;

  for (int i = 65; i <= 90; i++) {
    for (int j = 65; j <= 90; j++) {
      for (int k = 65; k <= 90; k++) {
        c++;

        word = word + char(i);
        word = word + char(j);
        word = word + char(k);

        cout << "trial [" << c << "] " << word << endl;

        if (word == n) {
          cout << "\nThe password is " << word;
          cout << "\nFound after " << c << " trial(s).\n";
          return true;
        }
        word = "";
      }
    }
    cout << "\n**********\n";
  }
  return false;
}

int main() {
  printpattern(readletters("Please enter a three CAPTIAL Letters password: "));
  signature();
  return 0;
}
