public delegate double MyDelegate(int x, int y);

class Program
{
  public static double sum(int x, int y)
  {
    return x + y;
  }

  public static double sub(int x, int y)
  {
    return x - y;
  }

  public static double pow(int x, int y)
  {
    return x * y;
  }

  public static double div(int x, int y)
  {
    return x / y;
  }

  public static void Main(string[] args)
  {
    /*MyDelegate del = new MyDelegate(sum);*/
    MyDelegate del;

    double num = -1;

    del = sum;
    num = del(5, 5);
    Console.WriteLine($"sum: {num}");

    del -= sum;
    del += sub;
    num = del(5, 5);
    Console.WriteLine($"sub: {num}");

    del -= sub;
    del += pow;
    num = del(5, 5);
    Console.WriteLine($"pow: {num}");

    del -= pow;
    del += div;
    num = del(5, 5);
    Console.WriteLine($"div: {num}");
  }
}
