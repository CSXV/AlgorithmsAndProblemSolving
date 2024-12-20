#include <cmath>
#include <iostream>
using namespace std;
// Read an number, then print its square root value without build in function.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

float ROUND(float N) { return pow(N, 0.5); }

int main() {
  float N = ReadNumber("Please enter an number: ");

  cout << "\n>My sqrt result: ";
  cout << ROUND(N);
  cout << "\nC++ sqrt result: " << sqrt(N) << endl;
  signature();
  return 0;
}
