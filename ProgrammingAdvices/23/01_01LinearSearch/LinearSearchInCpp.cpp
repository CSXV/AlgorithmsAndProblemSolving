#include <iostream>
#include <vector>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

int LinearSearch(vector<int> &numbers, int n) {

  for (int i = 0; i < numbers.size(); i++) {
    if (numbers[i] == n)
      return i;
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
  int n = 11;
  vector<int> numbers{64, 34, 25, 12, 22, 11, 90};

  PrintVector(n, LinearSearch(numbers, n));

  signature();
  return 0;
}
