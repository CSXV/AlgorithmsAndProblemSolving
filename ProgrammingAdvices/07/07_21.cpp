#include <iostream>
using namespace std;
// Print Fibonacci series of an number.

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

void CalculateFibinacci(short N) {
  short Feb = 0, p2 = 0, p1 = 1;
  cout << "1  ";

  for (short i = 2; i <= N; i++) {
    Feb = p1 + p2;
    cout << Feb << "  ";

    p2 = p1;
    p1 = Feb;
  }
}

int main() {
  short N =
      ReadPNumber("Calculating Fibonacci series.\nPlease enter an number: ");
  CalculateFibinacci(N);

  signature();
  return 0;
}
