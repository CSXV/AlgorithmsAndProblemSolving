// [c23] 08_11: reverse queue items.

class Program {
  public static Queue<int> ReverseQueue(Queue<int> x) {
    Stack<int> swap = new();

    while (x.Count > 0)
      swap.Push(x.Dequeue());

    while (swap.Count > 0)
      x.Enqueue(swap.Pop());

    return x;
  }

  public static void Print(Queue<int> x) {
    foreach (var item in x) {
      Console.WriteLine(item);
    }
  }

  public static void Main(string[] args) {
    Queue<int> queue = new();

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);

    queue = ReverseQueue(queue);
    Print(queue);
  }
}
