// [c23] 08_02: Convert a decimal number to binary using a stack.

class Program {
  public static Stack<bool> DecimalToBinary(int number) {
    Stack<bool> binary = new Stack<bool>();
    int c = 0;

    while (number > 0) {
      if (number % 2 == 0) {
        binary.Push(false);
        c++;
      } else {
        binary.Push(true);
        c++;
      }

      number /= 2;
    }

    while (binary.Count < 8) {
      binary.Push(false);
    }

    return binary;
  }

  public static void Main(string[] args) {
    int number = 0;

    Console.Write("Enter an number to convet it to binary: ");
    number = Convert.ToInt32(Console.ReadLine());

    Stack<bool> results = DecimalToBinary(number);

    foreach (var item in results) {
      Console.Write((item == true ? "1" : "0"));
    }

    Console.ReadKey();
  }
}
