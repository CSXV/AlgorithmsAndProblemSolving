// You are given n activities with their start and end times. Select the maximum
// number of activities that can be performed by a single person, assuming that
// a person can only work on a single activity at a time.

class Actitvity {
  public int Start { get; set; }
  public int End { get; set; }

  public Actitvity(int start, int end) {
    this.Start = start;
    this.End = end;
  }
}

class Program {
  public static List<Actitvity> MaximumActivities(List<Actitvity> activities) {
    activities.Sort((a, b) => a.End.CompareTo(b.End));

    List<Actitvity> results = new();
    Actitvity lastSelectedActivity = null;

    foreach (var activity in activities) {
      if (lastSelectedActivity == null ||
          activity.Start >= lastSelectedActivity.End) {
        results.Add(activity);
        lastSelectedActivity = activity;
      }
    }

    return results;
  }

  public static void Print(List<Actitvity> results) {
    Console.WriteLine("Valid Activities:");
    Console.WriteLine("+---+---+---+");
    Console.WriteLine("| N | S | E |");
    Console.WriteLine("+---+---+---+");

    for (int i = 0; i < results.Count; i++) {
      Console.WriteLine($"| {i} | {results[i].Start} | {results[i].End} |");
    }

    Console.WriteLine("+---+---+---+");
  }

  public static void Main(string[] args) {
    List<Actitvity> activities = new List<Actitvity>();

    activities.Add(new Actitvity(1, 4));
    activities.Add(new Actitvity(3, 5));
    activities.Add(new Actitvity(0, 6));
    activities.Add(new Actitvity(5, 7));
    activities.Add(new Actitvity(8, 9));
    activities.Add(new Actitvity(5, 9));

    var results = MaximumActivities(activities);
    Print(results);
  }
}
