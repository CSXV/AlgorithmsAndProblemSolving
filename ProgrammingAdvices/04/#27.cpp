#include <iostream>
using namespace std;

// Print loop from an number to another number, with three Solutions.

int ReadAnNumber(string message) {
  int numberToRead;

  cout << message;
  cin >> numberToRead;

  return numberToRead;
}

void forloop(int N, int L) {
  cout << "Range printed using FOR statement:\n";

  for (int c = N; c >= L; c--) {
    cout << c << endl;
  }
}

void whileloop(int N, int L) {
  int n = N + 1;
  cout << "Range printed using WHILE statement:\n";

  while (L < n) {
    n--;
    cout << n << endl;
  }
}

void dowhileloop(int N, int L) {
  int n = N + 1;
  cout << "Range printed using DO WHILE statement:\n";

  do {
    n--;
    cout << n << endl;
  } while (L < n);
}

int main() {
  int max = ReadAnNumber("Enter the max: ");
  int min = ReadAnNumber("Enter the min: ");

  forloop(max, min);
  whileloop(max, min);
  dowhileloop(max, min);

  return 0;
}
