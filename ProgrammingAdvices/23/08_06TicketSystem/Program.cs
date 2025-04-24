// [c23] 08_06: simulate a ticketing system where customers are served in the
// order they arrive.

class Ticket {
  private Queue<int> _line = new Queue<int>();
  private int _count = 0;

  public int Add() {
    _count++;

    int newTicket = _count;
    _line.Enqueue(newTicket);

    return newTicket;
  }

  public int Process() {
    if (_line.Count == 0)
      return 0;

    int process = _line.Dequeue();
    return process;
  }

  public string Remaining() {
    if (_line.Count == 0)
      return null;

    return String.Join(",", _line);
  }
}

class Program {
  public static void Main(string[] args) {
    Ticket ticket = new Ticket();

    for (int i = 0; i < 5; i++) {
      Console.WriteLine("Ticket " + ticket.Add() + " Issued.");
    }

    Console.WriteLine("Ticket system simulation started...");

    int current;
    string Remaining;

    do {
      current = ticket.Process();
      Remaining = ticket.Remaining();

      Console.WriteLine("Processing ticket: " + current);

      if (Remaining != null)
        Console.WriteLine("Remaining tickets: " + Remaining);
      else
        Console.WriteLine("No more tickets in the queue.");
    } while (Remaining != null);

    Console.WriteLine("Ticketing system simulation ended.");
  }
}
