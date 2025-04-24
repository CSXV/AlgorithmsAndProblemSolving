// [c23] 08_05: simulate vehicles waiting at a traffic signal.

class Traffic {
  Stack<string> vehicles = new Stack<string>();

  public void Add(string name) { vehicles.Push(name); }

  public bool Simulate() {
    if (vehicles.Count == 0) {
      Console.WriteLine("Traffic is empty");

      return false;
    }

    Console.WriteLine("Traffic signal simulation started...\n");

    while (vehicles.Count > 0) {
      Console.WriteLine($"{vehicles.Pop()} has passed the signal.");
      Console.WriteLine("vehicles waiting: " + string.Join(",", vehicles) +
                        "\n");
    }

    Console.WriteLine("\nNo vehicles waiting");
    Console.WriteLine("Traffic signal simulation ended.\n");

    return true;
  }
  //
}

class Program {
  public static void Main(string[] args) {
    Traffic traffic = new Traffic();

    traffic.Add("Car01");
    traffic.Add("Truck01");
    traffic.Add("Bike01");
    traffic.Add("Bus01");

    traffic.Simulate();
  }
}
