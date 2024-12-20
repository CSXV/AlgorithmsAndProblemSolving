#include <iostream>
using namespace std;
// Dynamically read numbers and save them in a array with max size of 100,
// allocate simi-dynamic array lenght.

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  cout << message;
  cin >> N;
  return N;
}

void AddArrayElement(int number, int arr[100], int &arrLength) {
  arrLength++;
  arr[arrLength - 1] = number;
}

void InputInArray(int arr[100], int &arrLength) {
  bool AddMore = true;
  do {
    AddArrayElement(ReadNumber("Please enter an number: "), arr, arrLength);
    cout << "\nDo you want to add more numbers?\n[0] NO, [1] YES: ";
    cin >> AddMore;
  } while (AddMore);
}

void PrintArray(int arr[100], int arrLength) {
  cout << "\nArray elements: ";
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[100], arrLength = 0;
  InputInArray(arr, arrLength);

  cout << "\nArray Length: " << arrLength;
  PrintArray(arr, arrLength);

  signature();
  return 0;
}
