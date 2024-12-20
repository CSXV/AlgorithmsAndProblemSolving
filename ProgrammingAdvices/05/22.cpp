#include <iostream>
using namespace std;
// Read an N elements, then store them in an array, then print all array
// elements, and ask for a number to check, then print how many number a certian
// element is repeated in that array (0_o)

void signature() {
  cout << "\n*************"
       << "\nNEVER SETTLE."
       << "\n*************" << endl;
}

int ReadNumber(string message) {
  int N;
  do {
    cout << message;
    cin >> N;
  } while (N < 0);
  return N;
}

void ReadArray(int arr[100], int &arrLength) {
  cout << "Enter array of element";
  cin >> arrLength;

  for (int i = 0; i < arrLength; i++) {
    cout << "Element [" << i << "] : ";
    cin >> arr[i];
  }
  cout << endl;
}

void PrintArray(int arr[100], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

int TimesRepeated(int Number, int arr[100], int arrLength) {
  int counter = 0;
  for (int i = 0; i < arrLength; i++) {
    if (Number == arr[i]) {
      counter++;
    }
  }
  return counter;
}

int main() {
  int arr[100], arrLength, NumberToCheck;
  ReadArray(arr, arrLength);

  NumberToCheck = ReadNumber("Please enter an number: ");
  cout << "Original Array: ";
  PrintArray(arr, arrLength);

  cout << "\nNumber " << NumberToCheck;
  cout << " is repeated ";
  cout << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)." << endl;
  signature();
  return 0;
}
