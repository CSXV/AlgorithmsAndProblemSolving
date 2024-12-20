#include <iostream>
#include <ostream>
using namespace std;
// Print loop from 01 to an number, with three Solutions.
int readnumber() {
  int a;
  cout << "Please enter an number: ";
  cin >> a;
  return a;
}

void forloop(int N) {
  cout << "Range printed using for statement:\n";
  for (int L = 1; L <= N; L++) {
    cout << L << endl;
  }
}

void whileloop(int N) {
  int L = 0;
  cout << "Range printed using while statement:\n";
  while (L < N) {
    L++;
    cout << L << endl;
  }
}

void dowhileloop(int N) {
  cout << "Range printed using Do While statement:\n";
  int L = 0;
  do {
    L++;
    cout << L << endl;
  } while (L < N);
}

int main() {
  int N = readnumber();

  forloop(N);
  whileloop(N);
  dowhileloop(N);

  return 0;
}
