#include <iostream>
using namespace std;

// Check odd or even number.

enum enNum { even = 1, odd = 2 };

int ReadNum() {
  int Num;

  cout << "Please enter an number: ";
  cin >> Num;

  return Num;
}

enNum ChNu(int Num) {
  int result = Num % 2;

  if (result == 0)
    return enNum::even;
  else
    return enNum::odd;
}

void PrintNum(enNum NumType) {
  if (NumType == enNum::even)
    cout
        << "********************\nThe number is: Even.\n********************\n";
  else
    cout << "********************\nThe number is: Odd.\n********************\n";
}

int main() {
  PrintNum(ChNu(ReadNum()));

  return 0;
}
