public delegate void MyDelegate(int x, int y);

class Program
{
  public static void sum(int x, int y)
  {
    Console.WriteLine($"sum: {x + y}");
  }

  public static void sub(int x, int y)
  {
    Console.WriteLine($"sub: {x - y}");
  }

  public static void pow(int x, int y)
  {
    Console.WriteLine($"pow: {x * y}");
  }

  public static void div(int x, int y)
  {
    Console.WriteLine($"dev: {x / y}");
  }

  public static void Main(string[] args)
  {
    /*MyDelegate del = new MyDelegate(sum);*/
    MyDelegate del;

    del = sum;
    del += sub;
    del += pow;
    del += div;

    del(5, 5);
  }
}
