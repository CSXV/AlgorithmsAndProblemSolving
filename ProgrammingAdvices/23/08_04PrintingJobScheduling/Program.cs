// [c23] 08_04: use queue to manage print jobs.

class PrintingPool {
  private Queue<_Print> _printjobs = new Queue<_Print>();
  private Stack<_Print> _history = new Stack<_Print>();

  private class _Print {
    public string Name { get; set; }
    public int Pages { get; set; }

    public _Print(string name, int pages) {
      Name = name;
      Pages = pages;
    }
  }

  public void Add(string name, int pages) {
    _Print printjob = new _Print(name, pages);
    _printjobs.Enqueue(printjob);
  }

  public bool Print() {
    if (_printjobs.Count == 0) {
      Console.WriteLine("Print queue is empty.");
      return false;
    }

    Console.WriteLine($"\nPrinting {_printjobs.Peek().Name}...");
    _history.Push(_printjobs.Dequeue());
    Console.WriteLine("DONE PRINTING.\n");

    return true;
  }

  public void GetTop() {
    if (_printjobs.Count == 0) {
      Console.WriteLine("No more printing jobs.");
      return;
    }

    Console.WriteLine($"Top Printing Jobs name: {_printjobs.Peek().Name}.");
    Console.WriteLine($"with number of pages  : {_printjobs.Peek().Pages}.");
  }

  public void GetHistory() {
    if (_history.Count == 0) {
      Console.WriteLine("No printing history.");
      return;
    }

    Console.WriteLine($"Last Printed Job name: {_history.Peek().Name}.");
    Console.WriteLine($"with number of pages : {_history.Peek().Pages}.");
  }
  //
}

class Program {
  public static void Main(string[] args) {
    PrintingPool printpool = new PrintingPool();

    printpool.Add("Practical Vim", 330);
    printpool.Add("Modern Vim", 160);
    printpool.Add("Pro GIT", 250);

    printpool.GetTop();
    printpool.Print();

    printpool.GetTop();
    printpool.Print();

    printpool.GetTop();

    printpool.GetHistory();
  }
}
