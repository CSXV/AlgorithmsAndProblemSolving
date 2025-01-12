// [c23] 08_01: Use a stack to implement a browser's back button functionality.

class Page {
  private Stack<string> _browser = new Stack<string>();

  public void AddNew(string url) { _browser.Push(url); }

  public string current() {
    return (_browser.Count != 0) ? _browser.Peek() : "Histroy is empty";
  }

  public void Back() {
    if (_browser.Count != 0)
      _browser.Pop();
  }
}

class Program {
  public static void Main(string[] args) {
    Page page = new Page();
    char answer = 'Y';

    do {
      Console.Write("Please enter URL: ");
      string url = Console.ReadLine();
      Console.WriteLine();

      page.AddNew(url);

      Console.Write("Do you want to enter another URL? [y/n]: ");
      answer = Convert.ToChar(Console.ReadLine());

      Console.WriteLine();
    } while (answer == 'Y' || answer == 'y');

    Console.WriteLine($"Current URL: {page.current()}");
    answer = 'Y';

    do {
      Console.Write("Do you want to go back? [y/n]: ");
      answer = Convert.ToChar(Console.ReadLine());

      page.Back();
      Console.WriteLine(page.current());
    } while (answer == 'Y' || answer == 'y');

    Console.ReadKey();
  }
}
