#include <iostream>
using namespace std;
// Read an number, then print pattern of characters from it in reversed order.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int readPnumber(string message) {
  int number;

  do {
    cout << message;
    cin >> number;
  } while (number < 0);

  return number;
}

// First Solution.
void printpattern(int N) {
  for (char i = N + 64; i >= 65; i--) {
    for (int j = 65; j <= i; j++) {
      cout << i;
    }

    cout << "\n";
  }
}

// Second Solution.
// void printpattern(int N) {
//   for (int i = N; i > 0; i--) {
//     for (int j = 1; j <= i; j++) {
//       cout << char(i + 64) << "";
//     }
//     cout << endl;
//   }
// }

int main() {
  printpattern(readPnumber("Please enter an number: "));

  signature();
  return 0;
}
