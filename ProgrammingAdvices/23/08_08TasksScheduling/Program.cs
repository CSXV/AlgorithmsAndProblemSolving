// [c23] 08_08: given a set of tasks with a specific order, simulate the order
// of execution using a queue.

class Tasks {
  private Queue<string> _task = new();

  public void Add(List<string> list) {
    foreach (var item in list) {
      _task.Enqueue(item);
    }
  }

  public void Add(string item) { _task.Enqueue(item); }

  public void Excecute() {
    while (_task.Count > 0)
      Console.WriteLine($"Processing: {_task.Dequeue()}");
  }
}

class Program {
  public static void Main(string[] args) {
    Tasks task = new Tasks();

    task.Add(["Task01", "Task02", "Task03", "Task04"]);
    task.Excecute();
  }
}
