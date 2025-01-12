// calculate the number of coins from amount and what coin is paid of.
//
// if i paid $67 with $100 coin, i will receive one $20, one $10, and three $1
// as a total of 5 coins.

public class Program {
  public static List<int> Greedy(int amount, int coin, List<int> coins) {
    List<int> results = new List<int>();

    // sort coins list  DESC
    coins.Sort((a, b) => b.CompareTo(a));

    // get the remainder
    int change = coin - amount;
    Console.WriteLine($"change = {change}");

    foreach (int c in coins) {
      while (change >= c) {
        results.Add(c);
        change -= c;
      }
    }

    return results;
  }

  public static void Print(List<int> coinList) {
    foreach (int c in coinList)
      Console.WriteLine($"{c}");
  }

  public static void Main(string[] args) {
    List<int> coins = new List<int> { 1, 5, 10, 20, 50, 100 };
    int amount = 0, coin = 0;

    do {
      Console.Write("Please enter Amount: ");
      amount = Convert.ToInt32(Console.ReadLine());

      Console.Write("Please enter Coin  : ");
      coin = Convert.ToInt32(Console.ReadLine());
    } while ((coin < amount) || (coin == 0) || (amount == 0));

    Console.WriteLine("------------------------------------");
    List<int> list = Greedy(amount, coin, coins);
    Console.WriteLine($"Total  = {list.Count}");
    Console.WriteLine("---------------------");
    Print(list);
    Console.WriteLine("------------------------------------");

    Console.ReadKey();
  }
}
