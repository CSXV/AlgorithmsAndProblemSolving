using System;

// 04 - Selection sort

public class Program {
  public static void SelectionSortASC(int[] arr) {
    int n = arr.Length, swap;

    for (int i = 0; i < n; i++) {
      int minIndex = i;

      for (int j = i; j < n; j++) {
        if (arr[j] <= arr[minIndex]) {
          minIndex = j;
        }
      }

      swap = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = swap;
    }
  }

  public static void SelectionSortDESC(int[] arr) {
    int n = arr.Length, swap;

    for (int i = 0; i < n; i++) {
      int minIndex = i;

      for (int j = i; j < n; j++) {
        if (arr[j] >= arr[minIndex]) {
          minIndex = j;
        }
      }

      swap = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = swap;
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

    SelectionSortASC(numbers);
    Console.WriteLine("Sorted array ASC:");
    PrintArray(numbers);

    SelectionSortDESC(numbers);
    Console.WriteLine("Sorted array DESC:");
    PrintArray(numbers);
  }
}
