#include <iostream>
using namespace std;
// If we list all the natural numbers below 10 that are multiples of 03 or 05,
// we get 03, 05, 06 and 09. The sum of these multiples is 23.

// Find the sum of all the multiples of 03 or 05 below 1000.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

class clsSum {
private:
  int _S = 0;
  short _N = 0;

public:
  clsSum(short n) { _N = n; }

  void SetNumber(short n) { _N = n; }
  short GetNumber() { return _N; }

  int SumOfMulitplesOf3And5() {
    for (short i = 0; i < _N; i++) {
      if (i % 3 == 0 || i % 5 == 0) {
        _S += i;
      }
    }

    return _S;
  }

  void PrintReults() { cout << _S; }
};

int main() {
  clsSum S1(1000);

  S1.SumOfMulitplesOf3And5();
  S1.PrintReults();

  signature();
  return 0;
}
