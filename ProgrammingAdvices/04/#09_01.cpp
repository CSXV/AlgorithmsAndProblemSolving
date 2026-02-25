#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Read three numbers and then print the sum of them.
// 2026-02-24

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

float readAnNumber(string message) {
  float numberToRead = 0;

  cout << message;
  cin >> numberToRead;

  return numberToRead;
}

short readPositiveNumber(string message) {
  short numberToRead = 0;

  do {
    numberToRead = readAnNumber(message);

    if (numberToRead <= 0) {
      cout << "\ttry again with positive number." << endl;
    }
  } while (numberToRead <= 0);

  return numberToRead;
}

void readNumbersNtime(vector<float> &numbers, short times) {
  string message = "";

  for (short i = 0; i < times; i++) {
    message = "Enter number " + to_string(i + 1) + ": ";

    numbers.push_back(readAnNumber(message));
  }
}

float SumOfNumbers(vector<float> numbers) {
  float sum = 0;

  for (short i = 0; i < numbers.size(); i++) {
    sum += numbers[i];
  }

  return sum;
}

void printResults(float sum) {
  cout << "The sum of all numbers: " << sum << endl;
}

int main() {
  vector<float> numbers;

  short times = readPositiveNumber("Enter how may numbers to read: ");

  readNumbersNtime(numbers, times);
  printResults(SumOfNumbers(numbers));

  signature();
  return 0;
}
