// using three ways of delegate to make simple validation to an number.

class Program
{
  public static Predicate<int> _IsEven = isEven;
  public static Func<int, string> _IsEvenOrOdd = isEvenOrOdd;
  public static Action<int> _IsEvenOrOdd2 = isEvenOrOdd2;

  public static bool isEven(int x)
  {
    return (x % 2 == 0);
  }

  public static string isEvenOrOdd(int x)
  {
    return (x % 2 == 0) ? "Even" : "Odd";
  }

  public static void isEvenOrOdd2(int x)
  {
    if (x % 2 == 0)
    {
      Console.WriteLine($"number {x} is: Even.");
    }
    else
    {
      Console.WriteLine($"number {x} is: Odd.");
    }
  }

  public static void Main(string[] args)
  {
    var x = 6;

    bool results1 = _IsEven(x);
    var results2 = _IsEvenOrOdd(x);

    Console.WriteLine($"is number {x} even? {results1}");
    Console.WriteLine($"number {x} is: {results2}");
    _IsEvenOrOdd2(x);
  }
}
