#include <iostream>
using namespace std;
// Print from A to Z.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

void printresults() {
  for (int i = 65; i <= 90; i++) {
    cout << char(i) << endl;
  }
}

int main() {
  printresults();
  signature();
  return 0;
}
