#include <iostream>
using namespace std;
// Check if an number is zero, otherwise check if it is positive or Negative
// using ternary operator.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

short ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

int main() {
  short number = ReadNumber("Please enter a mark: ");
  string results;

  results = (number == 0) ? "Zero" : ((number > 0) ? "Positive" : "Negative");
  cout << results << endl;

  signature();
  return 0;
}
