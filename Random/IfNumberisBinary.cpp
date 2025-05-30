// check if number is binary or not.

#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

bool checkNifBiary(int number) {
  if (number == 0 || number == 1 || number < 0)
    return false;

  while (number != 0) {
    if (number % 10 > 1)
      return false;

    number = number / 10;
  }

  return true;
}

void PrintResutls(bool results) {
  results ? cout << "number is binary\n" : cout << "number is NOT binary\n";
}

int main() {
  PrintResutls(checkNifBiary(1010));
  PrintResutls(checkNifBiary(1234));
  PrintResutls(checkNifBiary(1011));

  signature();
  return 0;
}
