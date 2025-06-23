#include <iostream>
#include <ostream>
using namespace std;

// Print the sum of odd numbers in an number, with three solutions.

enum enOddEven { odd = 1, even = 2 };

int readnumber() {
  int a;

  cout << "Please enter an number, to sum the EVEN numbers of it: ";
  cin >> a;

  return a; // return NUMBER.
}

enOddEven cecknumber(int N) {
  if (N % 2 != 0)
    return enOddEven::odd; // will return 01.
  else
    return enOddEven::even; // will return 02.
}

int forloop(int N) {
  int sum = 0; // any variable must have enitial value, because there will be
               // garbage values in memory.

  cout << "\nThe sum of even numbers using (FOR) statement:\n";

  for (int c = 1; c <= N; c++) {            // we will use (<=) with (=).
    if (cecknumber(c) == enOddEven::even) { // IF C=02 == 02 sum += c;
    }
  }

  return sum;
}

int whileloop(int N) {
  int sum = 0, c = 0;

  cout << "\nThe sum of even numbers using (WHILE) statement:\n";

  while (c < N) { // Not using (<=), because the (=) will add even number.

    c++;
    if (cecknumber(c) == enOddEven::even)
      sum += c;
  }

  return sum;
}

int dowhileloop(int N) {
  int c = 0, sum = 0;

  cout << "\nThe sum of even numbers using (DO WHILE) statement:\n";

  do {
    c++;
    if (cecknumber(c) == enOddEven::even) {
      sum += c;
    }
  } while (c < N); // Not using (<=), because the (=) will add even number.
  //
  return sum;
}

int main() {
  int N = readnumber();

  cout << forloop(N) << endl;
  cout << whileloop(N) << endl;
  cout << dowhileloop(N) << endl;

  return 0;
}
