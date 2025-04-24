// [c23] 08_10: simulate a web server that processes requests in the order they
// arrive.

class WebServer {
  private Queue<string> _processes = new();

  public void Add(string item) { _processes.Enqueue(item); }

  public string Process() {
    if (_processes.Count <= 0)
      return null;

    return _processes.Dequeue();
  }
}

class Program {
  public static void Main(string[] args) {
    WebServer webServer = new();

    for (int i = 0; i < 5; i++) {
      webServer.Add("Request " + i);
    }

    Console.WriteLine("Processing web server requests...");

    string current = webServer.Process();

    do {
      Console.WriteLine("Processed requeset: " + current);
      current = webServer.Process();
    } while (current != null);
  }
}
