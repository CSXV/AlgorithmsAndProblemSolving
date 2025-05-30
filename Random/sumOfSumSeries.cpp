// print sum of the sum-series of an number.

#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

int SumOfSumSeriesForN(int number) {
  int sumOfNaturalNumbers = 0;
  int sumOfSumSeries = 0;

  for (int i = 1; i <= number; i++) {
    sumOfNaturalNumbers = 0;

    for (int j = 1; j <= i; j++) {
      sumOfNaturalNumbers += j;
    }

    sumOfSumSeries += sumOfNaturalNumbers;
  }

  return sumOfSumSeries;
}

// another solution
int SumOfSumSeriesForN_2(int number) {
  int sumOfSumSeries = 0;

  for (int i = 1; i <= number; i++) {
    sumOfSumSeries += (i * (i + 1) / 2);
  }

  return sumOfSumSeries;
}

void PrintSums(short num) {
  for (short i = 1; i < num; i++) {
    cout << i << ": " << SumOfSumSeriesForN(i) << endl;
  }
}

int main() {
  PrintSums(6);

  signature();
  return 0;
}
