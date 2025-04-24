public class Calculator
{
  public delegate double MathOperation(double x, double y);
  // make an insatnce of the delegate
  private MathOperation _onMathOperation;

  public Calculator(MathOperation onMathOperation)
  {
    _onMathOperation = onMathOperation;
  }

  public double PerformOperation(double x, double y)
  {
    return _onMathOperation(x, y);
  }
}

internal class Program
{
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
    Calculator operationAdd = new Calculator(Add);
    Calculator operationSub = new Calculator(Subtract);
    Calculator operationMul = new Calculator(Multiply);
    Calculator operationDiv = new Calculator(Divide);

    var x = 5;
    var y = 10;

    Console.WriteLine($"{x} + {y} = {operationAdd.PerformOperation(x, y)}");
    Console.WriteLine($"{x} - {y} = {operationSub.PerformOperation(x, y)}");
    Console.WriteLine($"{x} * {y} = {operationMul.PerformOperation(x, y)}");
    Console.WriteLine($"{x} / {y} = {operationDiv.PerformOperation(x, y)}");

    Console.ReadLine();
  }
}
