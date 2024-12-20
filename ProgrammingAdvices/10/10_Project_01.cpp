#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

class clsCalculator {
private:
  float _Reslut = 0;
  float _PreviousResults = 0;
  float _LastNumber = 0;
  string _LastOperation = "Clear";
  bool _IsZero(float Number) { return (Number == 0); }

public:
  void Add(float N) {
    _LastNumber = N;
    _PreviousResults = _Reslut;
    _LastOperation = "Adding";
    _Reslut += N;
  };

  void Divide(float N) {
    _LastNumber = N;

    if (_IsZero(N)) {
      N = 1;
    }

    _PreviousResults = _Reslut;
    _LastOperation = "Subtracting";
    _Reslut /= N;
  };

  void Multiply(float N) {
    _LastNumber = N;
    _PreviousResults = _Reslut;
    _LastOperation = "Multipling";
    _Reslut *= N;
  };

  void Subtract(float N) {
    _LastNumber = N;
    _PreviousResults = _Reslut;
    _LastOperation = "Subtracting";
    _Reslut -= N;
  };

  float GetFinalResults() { return _Reslut; }

  void Clear() {
    _LastNumber = 0;
    _PreviousResults = 0;
    _LastOperation = "Clear";
    _Reslut = 0;
  };

  void CancelLastOperation() {
    _LastNumber = 0;
    _LastOperation = "Cancelling last operation";
    _Reslut = _PreviousResults;
  }

  void PrintResults() {
    cout << "Result ";
    cout << "after " << _LastOperation << " (" << _LastNumber
         << ") is: " << _Reslut << "\n";
  }
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
