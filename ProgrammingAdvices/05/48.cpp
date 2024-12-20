#include <cmath>
#include <iostream>
using namespace std;
// Read an number, then print its floor value without build in function.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

int ROUND(float N) {
  if (N > 0)
    return int(N);
  else
    return int(N) - 1;
}

int main() {
  float N = ReadNumber("Please enter an number: ");

  cout << "\n>My floor result: ";
  cout << ROUND(N);
  cout << "\nC++ floor result: " << floor(N) << endl;
  signature();
  return 0;
}
