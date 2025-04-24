internal class Program
{
  // you can use those, but FUNC is better
  //
  /*public delegate double Calculator(double x, double y);*/
  /*public static Calculator _Calculator;*/

  public static Func<double, double, double> _Calculator;

  public static double Add(double x, double y)
  {
    return x + y;
  }

  public static double Subtract(double x, double y)
  {
    return x - y;
  }

  public static double Multiply(double x, double y)
  {
    return x * y;
  }

  public static double Divide(double x, double y)
  {
    return (y == 0) ? 0 : x / y;
  }

  static void Main(string[] args)
  {
    var x = 5;
    var y = 10;

    _Calculator = Add;
    Console.WriteLine($"{x} + {y} = {_Calculator(x, y)}");

    _Calculator += Subtract;
    Console.WriteLine($"{x} - {y} = {_Calculator(x, y)}");

    _Calculator += Multiply;
    Console.WriteLine($"{x} * {y} = {_Calculator(x, y)}");

    _Calculator += Divide;
    Console.WriteLine($"{x} / {y} = {_Calculator(x, y)}");

    Console.ReadLine();
  }
}
