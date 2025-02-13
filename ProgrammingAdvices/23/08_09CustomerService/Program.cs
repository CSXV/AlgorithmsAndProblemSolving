// [c23] 08_09: Simulate a customer serivce system where customers are served in
// the order they arrive.

class Service {
  private Queue<int> _queue = new Queue<int>();
  private int _cout = 0;

  public void Add() {
    _cout++;
    _queue.Enqueue(_cout);
  }

  public int Serve() {
    if (_queue.Count == 0)
      return 0;

    return _queue.Dequeue();
  }
}

class Program {
  public static void Main(string[] args) {
    Service service = new();

    for (int i = 0; i < 5; i++) {
      service.Add();
    }

    Console.WriteLine("Serving Customers");

    int current = service.Serve();

    do {
      Console.WriteLine("Serving: " + current);
      current = service.Serve();
    } while (current != 0);
  }
}
