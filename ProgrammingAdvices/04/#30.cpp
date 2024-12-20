#include <iostream>
#include <ostream>
using namespace std;
// Calculating the factorial of a positive number.

int readnumber(string message) {
  int a;

  cout << "Print the factorial of an number (N!).\n";
  // cout << "Please enter a positive one: "

  do {
    cout << message << endl;
    cin >> a;
  } while (a < 0);

  return a;
}

int factorial(int N) {
  int sum = 1;
  for (int c = 1; c <= N; c++) {
    sum = sum * c;
  }
  return sum;
}

int main() {
  cout << factorial(readnumber("Please enter a positive one: ")) << endl;
  return 0;
}
