#include <iostream>
using namespace std;
// Read array elements, or hard code them, then print if the array elements are
// palindrome or not.

void signature() {
  cout << "\n*************" << "\nNEVER SETTLE." << "\n*************" << endl;
}

void FillArray(int arr[100], int &arrLength) {
  arrLength = 6;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 30;
  arr[4] = 20;
  arr[5] = 10;
}

bool IsPalindromeNumber(int arr[100], int &arrLength) {
  for (int i = 0; i < arrLength; i++) {
    if (arr[i] != arr[arrLength - i - 1])
      return false;
  }
  return true;
}

void PrintArray(int arr[10], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int arr[100], arr2[10], arrLength, arr2Length = 0;
  FillArray(arr, arrLength);

  cout << "Array 01 elements: ";
  PrintArray(arr, arrLength);

  if (IsPalindromeNumber(arr, arrLength)) {
    cout << "\nYES, Array is palindrome" << endl;
  } else {
    cout << "\nNO, Array in not palindrome." << endl;
  }

  signature();
  return 0;
}
