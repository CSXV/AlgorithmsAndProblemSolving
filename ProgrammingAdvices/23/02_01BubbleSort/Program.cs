using System;

// 03 - Bubble sort

public class Program {
  public static void BubbleSort(int[] arr) {
    int n = arr.Length - 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - i; j++) {
        if (arr[j] > arr[j + 1]) {
          int swap = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = swap;
        }
      }
    }
  }

  public static void PrintArray(int[] arr) {
    foreach (var item in arr) {
      Console.Write(item + " ");
    }

    Console.WriteLine("\n");
  }

  static void Main() {
    int[] numbers = { 64, 34, 25, 12, 22, 11, 90 };

    Console.WriteLine("Original array:");
    PrintArray(numbers);

    BubbleSort(numbers);

    Console.WriteLine("Sorted array:");
    PrintArray(numbers);
  }
}
