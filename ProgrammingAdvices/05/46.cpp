#include <cmath>
#include <iostream>
using namespace std;
// Read an number, then print its absolut value without build in function.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

// int ABS(int N) {
//   int c = 0;
//   for (int i = 0; i > N; i--) {
//     c++;
//   }
//   return c;
// }

int ABS(int N) {
  if (N > 0)
    return N;
  else
    return N * -1;
}

int main() {
  int N = ReadNumber("Please enter an number: ");

  cout << "\n*My ABS result: ";
  cout << ABS(N);
  cout << "\nC++ ABS result: " << abs(N) << endl;
  signature();
  return 0;
}
