#include <iostream>
using namespace std;

// Calculating the factorial of a positive number.

int ReadNumber(string message) {
  int a;

  do {
    cout << message;
    cin >> a;
  } while (a < 0);

  return a;
}

int Factorial(int N) {
  int sum = 1;

  for (int c = 1; c <= N; c++) {
    sum = sum * c;
  }

  return sum;
}

int main() {
  cout << "Print the factorial of an number (N!).\n";

  cout << Factorial(ReadNumber("Please enter a positive one: ")) << endl;

  return 0;
}
