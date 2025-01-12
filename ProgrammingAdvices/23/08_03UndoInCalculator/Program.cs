// [c23] 08_03: implement undo function in a calculator.

class Calculator {
  private Stack<decimal> _History = new Stack<decimal>();

  public decimal Sum(decimal x, decimal y) {
    decimal results = x + y;
    _History.Push(results);

    return results;
  }

  public decimal Subtract(decimal x, decimal y) {
    decimal results = x - y;
    _History.Push(results);

    return results;
  }

  public decimal Multiply(decimal x, decimal y) {
    decimal results = x * y;
    _History.Push(results);

    return results;
  }

  public decimal Divid(decimal x, decimal y) {
    if (y <= 0)
      return 1;

    decimal results = x / y;
    _History.Push(results);

    return results;
  }

  public decimal LastOperation() { return _History.Peek(); }

  public decimal Undo() {
    if (_History.Count != 0)
      return _History.Pop();
    else
      return 0;
  }
}

class Program {
  public static void Main(string[] args) {
    Decimal x = 7, y = 2;
    Calculator calculator = new Calculator();

    Console.WriteLine($"Sum      of {x} and {y} = {calculator.Sum(x, y)}");
    Console.WriteLine($"Subtract of {x} and {y} = {calculator.Subtract(x, y)}");
    Console.WriteLine($"Multiply of {x} and {y} = {calculator.Multiply(x, y)}");
    Console.WriteLine($"Divid    of {x} and {y} = {calculator.Divid(x, y)}");

    Console.WriteLine();
    Console.WriteLine($"History             = {calculator.Undo()}");
    Console.WriteLine($"History             = {calculator.Undo()}");
    Console.WriteLine($"History             = {calculator.Undo()}");
    Console.WriteLine($"History             = {calculator.Undo()}");
  }
}
