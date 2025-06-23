#include <iostream>
#include <ostream>
using namespace std;

// Print loop from an number to another number, with three Solutions.

int readnumber() {
  int a;

  cout << "Please enter the floor: ";
  cin >> a;

  return a;
}
int readsecondnumber() {
  int b;

  cout << "Please enter the top: ";
  cin >> b;

  return b;
}

void forloop(int N, int L) {
  cout << "Range printed using for statement:\n";

  for (int c = N; c >= L; c--) {
    cout << c << endl;
  }
}

void whileloop(int N, int L) {
  int n = N + 1;
  cout << "Range printed using while statement:\n";

  while (L < n) {
    n--;
    cout << n << endl;
  }
}

void dowhileloop(int N, int L) {
  int n = N + 1;
  cout << "Range printed using Do While statement:\n";

  do {
    n--;
    cout << n << endl;
  } while (L < n);
}

int main() {
  int N = readnumber();
  int L = readsecondnumber();

  forloop(N, L);
  whileloop(N, L);
  dowhileloop(N, L);

  return 0;
}
