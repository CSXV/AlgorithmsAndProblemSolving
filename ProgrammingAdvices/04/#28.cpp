#include <iostream>
using namespace std;

// Print the sum of odd numbers in an number, with three solutions.

enum enOddEven { odd = 1, even = 2 };

int ReadAnNumber() {
  int numberToRead;

  cout << "Please enter an number: ";
  cin >> numberToRead;

  return numberToRead;
}

enOddEven CheckNumber(int N) {
  if (N % 2 != 0)
    return enOddEven::odd; // will return 01.
  else
    return enOddEven::even; // will return 02.
}

int forloop(int N) {
  int sum = 0; // any variable must have enitial value, because there will be
               // garbage values in memory.

  cout << "\nThe sum of odd numbers using for statement:\n";

  for (int c = 1; c <= N; c++) {            // we will use (<=) with (=).
    if (CheckNumber(c) == enOddEven::odd) { // IF C=01 == 01
      sum += c;
    }
  }

  return sum;
}

int whileloop(int N) {
  int sum = 0, c = 0;

  cout << "\nThe sum of odd numbers using while statement:\n";

  while (c < N) { // Not using (<=), because the (=) will add even number.

    c++;
    if (CheckNumber(c) == enOddEven::odd)
      sum += c;
  }

  return sum;
}

int dowhileloop(int N) {
  int c = 0, sum = 0;

  cout << "\nThe sum of odd numbers using do while statement:\n";

  do {
    c++;
    if (CheckNumber(c) == enOddEven::odd) {
      sum += c;
    }
  } while (c < N); // Not using (<=), because the (=) will add even number.
  //
  return sum;
}

int main() {
  int N = ReadAnNumber();

  cout << forloop(N) << endl;
  cout << whileloop(N) << endl;
  cout << dowhileloop(N) << endl;

  return 0;
}
