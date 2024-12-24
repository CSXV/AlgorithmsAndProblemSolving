using System;

// 05 - Insertion sort

public class Program {
  public static void MyInsertionSort(int[] arr) {
    int n = arr.Length, key = 0, s = 0;

    for (int i = 0; i < n; i++) {
      key = arr[i];

      for (int j = 0; j < arr.Length; j++) {
        if (key <= arr[j])
          s = j;
      }

      arr[i] = arr[s];
      arr[s] = key;
    }
  }

  public static void InsertionSort(int[] arr) {
    int n = arr.Length;

    for (int i = 0; i < n; i++) {
      int key = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
      }

      arr[j + 1] = key;
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

    InsertionSort(numbers);
    Console.WriteLine("Sorted array:");
    PrintArray(numbers);
  }
}
