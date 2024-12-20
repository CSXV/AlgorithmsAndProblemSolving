#include <cmath>
#include <iostream>
using namespace std;
// Read an number, then print its ceiling value without build in function.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

float getfraction(float N) { return N - int(N); }

int ROUND(float N) {
  if (abs(getfraction(N)) > 0) {
    if (N > 0)
      return int(N) + 1;
    else
      return int(N);
  } else {
    return N;
  }
}

int main() {
  float N = ReadNumber("Please enter an number: ");

  cout << "\n>My floor result: ";
  cout << ROUND(N);
  cout << "\nC++ floor result: " << ceil(N) << endl;
  signature();
  return 0;
}
