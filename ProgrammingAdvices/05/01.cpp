#include <iostream>
using namespace std;
// Print Multiplication table from to 01 to 10.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

void PrintTableHeader() {
  cout << "\n\n\t\t\t Multiplication table from 01 to 10\n\n"
       << endl; // The header.
  cout << "\t";
  for (int i = 1; i <= 10; i++) {
    cout << i << "\t"; // Print numbers in rows.
  }
  cout << "\n__________________________________________________________________"
          "__________________\n";
}

string ColumSperator(int i) {
  if (i < 10)
    return "   |";
  else
    return "  |"; // Because the number will take two spaces.
}

void PrintMultiplicationTable() {
  PrintTableHeader();

  for (int i = 1; i <= 10; i++) { // FOR loop for Rows.
    cout << " " << i << ColumSperator(i) << "\t";
    for (int j = 1; j <= 10; j++) {
      cout << i * j << "\t"; // FOR Loop for coulums.
    }
    cout << endl;
  }
}

int main() {
  PrintMultiplicationTable();
  signature();
  return 0;
}
