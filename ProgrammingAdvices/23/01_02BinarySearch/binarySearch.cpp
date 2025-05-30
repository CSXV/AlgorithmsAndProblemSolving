// binary Search

#include <iostream>
using namespace std;

void signature() {
  cout << "\n┏┓╻┏━╸╻ ╻┏━╸┏━┓   ┏━┓┏━╸╺┳╸╺┳╸╻  ┏━╸"
          "\n┃┗┫┣╸ ┃┏┛┣╸ ┣┳┛   ┗━┓┣╸  ┃  ┃ ┃  ┣╸ "
          "\n╹ ╹┗━╸┗┛ ┗━╸╹┗╸   ┗━┛┗━╸ ╹  ╹ ┗━╸┗━╸";
}

int binarySearch(int arr[], int length, int search) {
  int start = 0;
  int end = length - 1;
  int middle = start + (end - start) / 2;

  while (start <= end) {
    middle = start + (end - start) / 2;

    if (arr[middle] == search) {
      return middle;
    } else if (search > arr[middle]) {
      start = middle + 1;
    } else if (search < arr[middle]) {
      end = middle - 1;
    }
  }

  return -1;
}

void PrintResults(int results, int search) {
  if (results == -1)
    printf("[%d] not found.", search);
  else
    printf("[%d] found at index: %d", search, results);
}

int main() {
  int arr[] = {22, 25, 37, 41, 45, 46, 49, 51, 55, 58, 70, 80, 82, 90, 95};

  int Size = size(arr);
  int search = 70;
  // int search = 10;

  int index = binarySearch(arr, Size, search);

  PrintResults(index, search);

  signature();
  return 0;
}
