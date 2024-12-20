#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

class clsCalculator {
private:
  double _Number = 0;
  double _OldNumber = 0;
  string _Operation = "";

public:
  void Add(double N) {
    _Operation = "Adding";
    _OldNumber = N;
    _Number += N;
  };
  double Add() { return _Number; };

  void Divide(double N) {
    _Operation = "Dividing";
    _OldNumber = N;
    _Number /= N;
  };
  double Divide() { return _Number; };

  void Multiply(double N) {
    _Operation = "Multipling";
    _OldNumber = N;
    _Number *= N;
  };
  double Multiply() { return _Number; };

  void Subtract(double N) {
    _Operation = "Subtracting";
    _OldNumber = N;
    _Number -= N;
  };
  double Subtract() { return _Number; };

  void Clear() {
    _OldNumber = 0;
    _Number = 0;
    _Operation = "";
  };

  void PrintResults() {
    cout << "Results after " << _Operation << " (" << _OldNumber
         << ") is: " << _Number << endl;
  }

  // void GetFinalResults(){_Number=N;};
  // int GetFinalResults() { return _Number; };
};

int main() {
  clsCalculator Calculator1;

  Calculator1.Add(10);
  Calculator1.PrintResults();

  Calculator1.Divide(2);
  Calculator1.PrintResults();

  Calculator1.Multiply(2);
  Calculator1.PrintResults();

  Calculator1.Subtract(2);
  Calculator1.PrintResults();

  signature();
  return 0;
}
