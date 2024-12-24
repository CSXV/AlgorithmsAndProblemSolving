using System;

// 02 - Binary search

public class Program {
  public static int BinarySearch(int[] arr, int x) {
    int start = 0, end = arr.Length - 1;

    while (start <= end) {
      int middle = start + (end - start) / 2;

      // middle
      if (x == arr[middle]) {
        return middle;
      }
      // right
      if (x > arr[middle]) {
        start = middle + 1;
      }
      // left
      if (x < arr[middle]) {
        end = middle - 1;
      }
    }

    return -1;
  }

  static void Main() {
    int[] numbers = { 22, 25, 37, 41, 45, 46, 49, 51,
                      55, 58, 70, 80, 82, 90, 95 };

    // number to search for
    int x = 45;

    int index = BinarySearch(numbers, x);
    if (index != -1) {
      Console.WriteLine($"item {x} found at index: {index}");
    } else {
      Console.WriteLine($"item {x} not found :(");
    }
  }
}
