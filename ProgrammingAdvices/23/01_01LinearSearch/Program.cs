using System;

// 01 Linear search

public class Program {
  public static int LinearSearch(List<int> numbers, int N) {
    int counter = -1;

    foreach (var item in numbers) {
      counter++;

      if (item == N) {
        return counter;
      }
    }

    return -1;
  }

  public static int AnotherLinearSearch(int[] arr, int N) {
    for (int i = 0; i < arr.Length; i++) {
      if (arr[i] == N) {
        return i;
      }
    }

    return -1;
  }

  static void Main() {
    List<int> numbers = new List<int> { 64, 34, 25, 12, 11, 90 };
    int[] numbers2 = { 64, 34, 25, 12, 11, 90 };

    Console.WriteLine("Orignial array:");
    foreach (var item in numbers) {
      Console.Write(item + " ");
    }

    // int to serach for
    int x = 34;

    int results1 = LinearSearch(numbers, x);
    Console.WriteLine("\n\nsolution 01 with List:");
    if (results1 != -1) {
      Console.WriteLine($"item {x} found at index: {results1}");
    } else {
      Console.WriteLine($"item {x} not found");
    }

    int results = AnotherLinearSearch(numbers2, x);
    Console.WriteLine("\nsolution 02 with array:");
    if (results != -1) {
      Console.WriteLine($"item {x} found at index: {results}");
    } else {
      Console.WriteLine($"item {x} not found");
    }
  }
}
