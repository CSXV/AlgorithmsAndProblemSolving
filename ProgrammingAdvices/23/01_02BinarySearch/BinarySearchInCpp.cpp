#include <iostream>
#include <vector>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

int BinarySearch(vector<int> numbers, int n) {
  short start = 0, end = numbers.size() - 1;

  while (start <= end) {
    short middle = start + (end - start) / 2;

    if (n == numbers[middle]) {
      return middle;
    }

    if (n > numbers[middle])
      start = middle + 1;

    if (n < numbers[middle])
      start = middle - 1;
  }

  return -1;
}

void PrintVector(int number, int index) {
  if (index != -1)
    cout << "item [" << number << "] found in index: " << index;
  else
    cout << "item [" << number << "] not found.";
}

int main() {
  int n = 80;
  vector<int> numbers = {22, 25, 37, 41, 45, 46, 49, 51,
                         55, 58, 70, 80, 82, 90, 95};

  PrintVector(n, BinarySearch(numbers, n));

  signature();
  return 0;
}
