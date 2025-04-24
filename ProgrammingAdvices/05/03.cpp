#include <iostream>
using namespace std;
// Read an number, and print if it is perfect or not.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int readnumber(string message) {
  int number;

  do {
    cout << message;
    cin >> number;
  } while (number <= 0);

  return number;
}

bool checkperfect(int N) {
  int sum = 0;

  for (int i = 1; i < N; i++) {
    if (N % i == 0) {
      sum += i;
    }
  }

  return N == sum; // Is N == Sum? if yes return true, if no return false.
}

void PrintResults(int N) {
  if (checkperfect(N))
    cout << N << " is Perfect Number." << endl;
  else
    cout << N << " is not Perfect Number." << endl;
}

int main() {
  PrintResults(readnumber("Please enter an number: "));

  signature();
  return 0;
}
