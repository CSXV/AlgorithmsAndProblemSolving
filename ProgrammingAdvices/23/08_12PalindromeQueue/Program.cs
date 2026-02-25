// Check if a queue is a palindrome (same forwards and backwards).

public class Program
{
    static void Main()
    {
        Queue<int> queue = new Queue<int>(new int[] { 1, 2, 3, 2, 1 });
        // Queue<int> queue = new Queue<int>(new int[] { 1, 2, 3, 4, 5 });

        Console.WriteLine(checkStacks(queue) ? "queue is palindrome" : "queue is not palindrome");
    }

    public static bool checkStacks(Queue<int> queue)
    {
        Stack<int> stack = new Stack<int>(queue);

        for (int i = 0; i < queue.Count; i++)
        {
            if (queue.Dequeue() != stack.Pop())
                return false;
        }

        return true;
    }
}
