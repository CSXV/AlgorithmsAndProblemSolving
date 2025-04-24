#include <cmath>
#include <iostream>
using namespace std;
// Print Prime number in an Number.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

enum enPrime { Prime = 1, NotPrime = 2 };

int readnumber(string message) {
  int number;

  cout << message;
  cin >> number;

  return number;
}

enPrime CheckPrime(int N) {
  int M = round(N / 2);

  for (int c = 2; c <= M; c++) {
    if (N % c == 0)
      return enPrime::NotPrime;
  }

  return enPrime::Prime;
}

void PrintResults(int N) {
  cout << "\n"
       << "Prime numbers from " << 1 << " to " << N << " are: " << endl;

  for (int i = 1; i <= N; i++) {
    if (CheckPrime(i) == enPrime::Prime) {
      cout << i << endl;
    }
  }
}

int main() {
  PrintResults(readnumber("Please enter an number: "));

  signature();
  return 0;
}
