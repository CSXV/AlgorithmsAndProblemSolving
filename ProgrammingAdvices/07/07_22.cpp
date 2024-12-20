#include <iostream>
using namespace std;
// Print Fibonacci series of an number, using recurssion function.

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

short ReadPNumber(string message) {
  short N;
  cout << message;
  cin >> N;
  return N;
}

void CalculateFibinacci(short N, short p1, short p2) {
  short Feb = 0;
  if (N > 0) {
    Feb = p1 + p2;
    p2 = p1;
    p1 = Feb;

    cout << Feb << "  ";
    CalculateFibinacci(N - 1, p1, p2);
  }
}

int main() {
  short N =
      ReadPNumber("Calculating Fibonacci series.\nPlease enter an number: ");
  CalculateFibinacci(N, 0, 1);

  signature();
  return 0;
}
