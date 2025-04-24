// [c23] 08_07: use a stack for backtracking my day.

class MyDay {
  private Stack<string> _Backtrack = new Stack<string>();
  private Queue<string> _track = new Queue<string>();

  public void Add(string name) {
    _Backtrack.Push(name);
    _track.Enqueue(name);
  }

  public void BackTrack() {
    if (_Backtrack.Count == 0)
      return;

    foreach (var item in _Backtrack) {
      Console.WriteLine($"Back to: {item}");
    }
  }

  public void Track() {
    if (_track.Count == 0)
      return;

    foreach (var item in _track) {
      Console.Write($" -> {item}");
    }

    Console.WriteLine();
  }
}

class Program {
  public static void Main(string[] args) {
    MyDay myDay = new MyDay();

    myDay.Add("Start");
    myDay.Add("Go to Gaz station");
    myDay.Add("Go to superMarket");
    myDay.Add("To to work");
    myDay.Add("Go to cafe");
    myDay.Add("Return Home");

    myDay.Track();
    Console.WriteLine("\nBacktraking...");
    myDay.BackTrack();
  }
}
