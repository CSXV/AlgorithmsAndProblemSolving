using static System.Console;

class Program
{
  public static Func<double, double, double> Add = (x, y) => x + y;
  public static Func<double, double, double> Sub = (x, y) => x - y;
  public static Func<double, double, double> Pow = (x, y) => x * y;
  public static Func<double, double, double> Div = (x, y) => x / y;

  public static double ExecuteOperation(double x, double y, Func<double, double, double> Operation)
  {
    return Operation(x, y);
  }

  static void Main(string[] args)
  {
    var x = 5;
    var y = 10;

    WriteLine("Results: " + ExecuteOperation(x, y, Add));
    WriteLine("Results: " + ExecuteOperation(x, y, Sub));
    WriteLine("Results: " + ExecuteOperation(x, y, Pow));
    WriteLine("Results: " + ExecuteOperation(x, y, Div));
  }
}
