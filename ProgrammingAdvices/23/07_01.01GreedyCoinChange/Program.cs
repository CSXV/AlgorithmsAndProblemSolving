// calculate the number of coins from amount and what coin is paid of.
//
// if i paid $67 with $100 coin, i will receive one $20, one $10, and three $1
// as a total of 5 coins.

public class Program {
  public static List<int> Greedy(int amount, int coin) {
    int[] coins = { 1, 5, 10, 20, 50, 100 };
    List<int> coinList = new List<int> { 0, 0, 0, 0, 0, 0 };
    int totalCoins = 0;

    int change = coin - amount;
    Console.WriteLine($"change = {change}");

    while (change != 0) {
      if (change >= coins[5]) {
        coinList[5]++;
        change -= 100;
        totalCoins++;
      }
      if (change >= coins[4]) {
        coinList[4]++;
        change -= 50;
        totalCoins++;
      }
      if (change >= coins[3]) {
        coinList[3]++;
        change -= 20;
        totalCoins++;
      }
      if (change >= coins[2]) {
        coinList[2]++;
        change -= 10;
        totalCoins++;
      }
      if (change >= coins[1]) {
        coinList[1]++;
        change -= 5;
        totalCoins++;
      }
      if (change >= coins[0]) {
        coinList[0]++;
        change -= 1;
        totalCoins++;
      }
    }

    Console.WriteLine($"Total Coins = {totalCoins}");

    return coinList;
  }

  public static void Print(List<int> coinList) {
    if (coinList[5] != 0)
      Console.WriteLine($"100 -> {coinList[5]}");
    if (coinList[4] != 0)
      Console.WriteLine($"050 -> {coinList[4]}");
    if (coinList[3] != 0)
      Console.WriteLine($"020 -> {coinList[3]}");
    if (coinList[2] != 0)
      Console.WriteLine($"010 -> {coinList[2]}");
    if (coinList[1] != 0)
      Console.WriteLine($"005 -> {coinList[1]}");
    if (coinList[0] != 0)
      Console.WriteLine($"001 -> {coinList[0]}");
  }

  public static void Main(string[] args) {
    int amount = 0, coin = 0;

    do {
      Console.Write("Please enter amount: ");
      amount = Convert.ToInt32(Console.ReadLine());

      Console.Write("Please enter Coin: ");
      coin = Convert.ToInt32(Console.ReadLine());
    } while (coin < amount);

    Console.WriteLine("------------------------------------");
    List<int> list = Greedy(amount, coin);
    Print(list);
    Console.WriteLine("------------------------------------");

    Console.ReadKey();
  }
}
