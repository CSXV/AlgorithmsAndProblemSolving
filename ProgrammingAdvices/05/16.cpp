#include <iostream>
using namespace std;
// Print words from AAA to ZZZ.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

void printpattern() {
  cout << "\n";
  string word = "";

  for (int i = 65; i <= 90; i++) {
    for (int j = 65; j <= 90; j++) {
      for (int k = 65; k <= 90; k++) {
        word = word + char(i);
        word = word + char(j);
        word = word + char(k);

        cout << word << endl;
        word = "";
      }
    }

    cout << "\n**********\n";
  }
}

int main() {
  printpattern();

  signature();
  return 0;
}
