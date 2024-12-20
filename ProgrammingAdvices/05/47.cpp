#include <cmath>
#include <iostream>
using namespace std;
// Read an number, then print its round value without build in function.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

float getfrationpart(float N) { return N - int(N); }

int ROUND(float N) {
  int intpart;
  intpart = int(N);

  float practionpart = getfrationpart(N);

  if (abs(practionpart) >= 0.5) {
    if (N > 0) {
      return ++intpart;
    } else {
      return --intpart;
    }
  } else {
    return intpart;
  }
}

int main() {
  float N = ReadNumber("Please enter an number: ");

  cout << "\n>My round result: ";
  cout << ROUND(N);
  cout << "\nC++ round result: " << round(N) << endl;
  signature();
  return 0;
}
