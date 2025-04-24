// You are given n activities with their start and end times. Select the maximum
// number of activities that can be performed by a single person, assuming that
// a person can only work on a single activity at a time.

using System.Linq;

public class Program {
  public static Dictionary<int, (int, int)>
  MaximumActivities(Dictionary<int, (int, int)> activities) {
    Dictionary<int, (int, int)> selected = new();

    // add the first data.
    selected.Add(activities.First().Key, activities.First().Value);

    foreach (var key in activities) {
      var lastKey = selected.LastOrDefault();

      // e.g. for the first  item: if 1 >= 4 and 4 > 1 then add it. (NO )
      // e.g. for the fourth item: if 5 >= 4 and 7 > 1 then add it. (YES)
      if (key.Value.Item1 >= lastKey.Value.Item2 &&
          (key.Value.Item2 > lastKey.Value.Item2))
        selected.Add(key.Key, key.Value);
    }

    return selected;
  }
  public static void Print(Dictionary<int, (int, int)> results) {
    Console.WriteLine("Valid Activities:");
    Console.WriteLine("+----+------+----+");
    Console.WriteLine("| No | From | To |");
    Console.WriteLine("+----+------+----+");

    foreach (var key in results) {
      Console.WriteLine(
          $"| 0{key.Key} |  0{key.Value.Item1}  | 0{key.Value.Item2} |");
    }

    Console.WriteLine("+----+------+----+");
  }

  public static void Main(string[] args) {
    Dictionary<int, (int, int)> Activities = new Dictionary<int, (int, int)>();

    Activities.Add(1, (1, 4));
    Activities.Add(2, (3, 5));
    Activities.Add(3, (0, 6));
    Activities.Add(4, (5, 7));
    Activities.Add(5, (8, 9));
    Activities.Add(6, (5, 9));

    var results = MaximumActivities(Activities);
    Print(results);
  }
}
