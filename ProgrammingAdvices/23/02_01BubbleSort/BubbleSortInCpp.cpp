#include <iostream>
#include <vector>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

void BubbleSort(vector<int> &numbers) {
  int n = numbers.size() - 1;

  for (short i = 0; i < n; i++) {
    for (short j = 0; j < n - i; j++) {
      if (numbers[j] > numbers[j + 1]) {
        int swap = numbers[j];

        numbers[j] = numbers[j + 1];
        numbers[j + 1] = swap;
      }
    }
  }
}

void PrintVector(vector<int> numbers) {
  for (int &number : numbers) {
    cout << number << " ";
  }

  cout << endl;
}

int main() {
  vector<int> numbers{64, 34, 25, 12, 22, 11, 90};

  cout << "original array: ";
  PrintVector(numbers);

  BubbleSort(numbers);

  cout << "Sotred array: ";
  PrintVector(numbers);

  signature();
  return 0;
}
